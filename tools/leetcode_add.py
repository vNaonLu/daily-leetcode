#!/usr/bin/python3
import os
import optparse
import pathlib
import subprocess
import time
from utils import prompt as pmt
from utils import local, modify, generate
from leetcode import request as LeetCodeRequest
from leetcode.question import LeetCodeQuestion


def __add_question(qfile: local.QuestionSource, testcase: bool):
    if os.path.exists(qfile.src()):
        pmt.show(pmt.fail("\033[37mThe file has already exist: \033[0m{}".format(qfile.src()),
                          "!"))
        return False

    pmt.pending(
        "\033[37mRequesting a slug with question id {}\033[0m".format(qfile.id()))
    slug = LeetCodeRequest.question_slug(qfile.id())
    if slug == None:
        pmt.recieve(
            pmt.fail("\033[37mThere is no question with id {}\033 or have a network error[0m!".format(qfile.id()), "x"))
        return False
    pmt.recieve(pmt.succ("\033[37mSuccessfully get the slug \"{}\".\033[0m".format(slug),
                         "v"))
    pmt.pending(
        "\033[37mRequesting a details of question \"{}\"\033[0m".format(slug))
    ques = LeetCodeQuestion(slug, testcase)
    if ques.is_valid():
        pmt.recieve(
            pmt.succ("\033[37mSuccessfully received the details \"{}\".\033[0m".format(slug),
                    "v"))
    else:
        pmt.recieve(
            pmt.fail("\033[37mThere is a network error \"{}\".\033[0m".format(slug),
                     "v"))
        return False

    pmt.pending("\033[37mGenerating the template: \033[0m {}".format(slug))
    src = ques.template("This file is generated by {}".format(os.path.basename(__file__)),
                        70)
    pmt.recieve(pmt.succ("\033[37mGenerated the template!", "+"))

    if not os.path.isdir(qfile.path()):
        os.makedirs(qfile.path())
        pmt.show(
            pmt.succ("\033[37mThe directory has been created:\033[0m {}".format(qfile.path()),
                     "+"))

    generate.file(qfile.src(), src)
    subprocess.run(["open", qfile.src()])

    return True


def __parser():
    parser = optparse.OptionParser(usage="%prog [options] id1 id2 ...")
    parser.add_option("-o", "--out",
                      dest="output",
                      action="store",
                      default=".",
                      metavar=" Source_Path",
                      help="The directory where files are generated")
    parser.add_option("-q", "--question-list",
                      dest="list",
                      action="store",
                      default="./questions_list.csv",
                      metavar=" Question_Lists_File")
    parser.add_option("-l", "--question-log",
                      dest="log",
                      action="store",
                      default="./logs.csv",
                      metavar=" Question_Logs_File")
    parser.add_option("-n", "--no-testcase",
                      dest="testcase",
                      action="store_true",
                      default=False,
                      metavar=" Question_Logs_File")
    parser.add_option("--timestamp",
                      dest="timestamp",
                      action="store",
                      default=int(time.time()),
                      metavar=" Question_Logs_File")
    return parser


def __main():
    parser = __parser()
    options, args = parser.parse_args()

    if len(args) == 0:
        pmt.show("Usage: {} [options] id1 id2 ...".format(
            os.path.basename(__file__)))
        return

    sour_path = pathlib.Path(options.output).resolve()
    list_csv = pathlib.Path(options.list).resolve()
    log_csv = pathlib.Path(options.log).resolve()
    timestamp = int(options.timestamp)
    testcase = not options.testcase

    modify_subunittest: set = set()
    question_added = False

    for id in args:
        qfile = local.QuestionSource(int(id), sour_path)

        if __add_question(qfile, testcase):
            modify.log(log_csv, qfile.id(), timestamp)
            modify_subunittest.add(qfile.interval())
            question_added = True
        else:
            pmt.show(
                pmt.fail("\033[37mFailed to generate question #{}!\033[0m".format(qfile.id()), "x"))

    if question_added:
        if not os.path.exists(list_csv):
            pmt.pending("\033[37mRequesting the question list\033[0m")
            question_list = LeetCodeRequest.questions()
            pmt.recieve(pmt.succ("\033[37mSuccessfully received the question list.\033[0m",
                                 "v"))
            generate.question_list(list_csv, question_list)
        solved = local.solved_question_ids(sour_path)
        modify.done_question(list_csv, solved)


if __name__ == "__main__":
    __main()
