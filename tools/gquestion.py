#!/usr/bin/python3
import sys
import os
import pathlib
import subprocess
from utils import leetcode, template, modify

prompt = "this file is generated by {}".format(os.path.basename(__file__))
proj_path = pathlib.Path(__file__).parent.parent.resolve()
sour_path = os.path.join(proj_path, "src")
list_csv = os.path.join(sour_path, "questions_list.csv")
log_csv = os.path.join(sour_path, "logs.csv")


class QuestionFile:
    def __init__(self, id: int):
        self.__id: str = str(id).zfill(4)
        self.__intv: str = leetcode.get_question_id_path(id)
        self.__name: str = "q{}.hpp".format(self.__id)
        self.__ut_name: str = "q{}_unittest.hpp".format(self.__id)
        self.__path: str = os.path.join(sour_path, self.__intv)

    def interval(self):
        return self.__intv

    def id(self):
        return int(self.__id)

    def src(self):
        return os.path.join(self.__path, self.__name)

    def unittest(self):
        return os.path.join(self.__path, self.__ut_name)

    def path(self):
        return self.__path


def add_question(ques: QuestionFile):
    path = ques.path()
    src = ques.src()
    utsrc = ques.unittest()
    desc = leetcode.get_description(ques.id(), prompt)
    if desc == None:
        print("[-] question #{} needs a plus account or does not exist."
              .format(ques.id()))
        return

    utindex = os.path.join(path, "unittest.hpp")
    if not os.path.isdir(path):
        os.makedirs(path)
        print("[+] create directory: {}".format(path))
        template.generate_intv_unittest(utindex, ques.interval())
        modify.unittest(os.path.join(
            sour_path, "unittest.cc"), ques.id(), ques.interval())

    if os.path.exists(src):
        print("[!] file exist: {}".format(src))
    else:
        template.generate_source(src, ques.id(), desc)
        subprocess.run(["code", src])

    if os.path.exists(utsrc):
        print("[!] file exist: {}".format(utsrc))
    else:
        template.generate_unittest(utsrc, ques.id(), desc)
        subprocess.run(["code", utsrc])

    modify.question_list(list_csv, [ques.id()])
    modify.subunittest(utindex, os.path.basename(utsrc))


if len(sys.argv) < 2:
    print("[Usage] <question number> ...")
else:
    # if not os.path.exists(list_csv):
    #     template.generate_question_list(list_csv)
    #     solved = leetcode.get_solved_ids()
    #     modify.question_list(list_csv, solved)

    for i in range(1, len(sys.argv)):
        ques = QuestionFile(int(sys.argv[i]))
        # add_question(ques)

    modify.readme(
        os.path.join(proj_path, "README.md"),
        list_csv,
        log_csv)
