import time
import datetime
import math
from . import local


def subunittest(intv: str, files: list[str]):
    return "\n".join([
        "",
        "#ifndef {}_UNITTEST".format(intv.upper()),
        "#define {}_UNITTEST".format(intv.upper()),
        ""] + [
        "#include \"{}\"".format(file) for file in files] + [
        "",
        "#endif"])


def mainunittest(subunittest: list[str]):
    return "\n".join([
        "#include <gtest/gtest.h>"] + [
        "#include \"{}\"".format(utfile) for utfile in subunittest] + [
        "",
        "int main(int argc, char **argv) {",
        "  ::testing::InitGoogleTest(&argc, argv);",
        "  return ::RUN_ALL_TESTS();",
        "}"])


def question_detail(question: local.QuestionDetails):
    id = str(question.id()).zfill(4)
    if question.done():
        return "|[✅]({})|{}|{}|{}|".format(
            "./src/{}/q{}.hpp".format(local.id_folder(question.id()), id),
            question.id(),
            "[{}](https://leetcode.com/problems/{}/)".format(question.title(),
                                                             question.slug()),
            "Hard" if question.level() == 3 else ("Medium" if question.level() == 2 else "Easy"))
    else:
        return "||{}|{}|{}|".format(
            question.id(),
            "[{}](https://leetcode.com/problems/{}/)".format(question.title(),
                                                             question.slug()),
            "Hard" if question.level() == 3 else ("Medium" if question.level() == 2 else "Easy"))


def accepted_svg(e: int, m: int, h: int, total: int):
    radius: float = 30.0
    text = ["Easy Solved",
            "Medium Solved",
            "Hard Solved",
            "Total Solved"]
    text_pos = [50 + radius * 2, 50 - radius - 10]
    e_fm = [50 + radius, 50]
    e_to = [50 + radius * math.cos(math.radians(360 * e / total)),
            50 + radius * math.sin(math.radians(360 * e / total))]
    m_to = [50 + radius * math.cos(math.radians(360 * (e+m) / total)),
            50 + radius * math.sin(math.radians(360 * (e+m) / total))]
    h_to = [50 + radius * math.cos(math.radians(360 * (e+m+h) / total)),
            50 + radius * math.sin(math.radians(360 * (e+m+h) / total))]
    return "\n".join([
        '<?xml version="1.0" encoding="UTF-8" standalone="no"?>',
        '<svg width="200" height="100" viewBox="0 0 200 100" xmlns="http://www.w3.org/2000/svg"', 'xmlns:xlink="http://www.w3.org/1999/xlink" stroke-width="40" fill="none">',
        '<style>.small {font: bold 10px sans-serif; fill: #d0d0d0; stroke: black; stroke-width: 0.5px;}</style>',
        '<style>.esy {font: bold 10px sans-serif; fill: green;}</style>',
        '<style>.mdm {font: bold 10px sans-serif; fill: orange;}</style>',
        '<style>.hrd {font: bold 10px sans-serif; fill: red;}</style>',
        '<circle cx="50" cy="50" r="{}" stroke="gray" />'.format(
            radius, radius),
        '<path d="M{} {} A {} {}, 0, {}, 1, {} {}" stroke="green" />'.format(e_fm[0], e_fm[1],
                                                                             radius, radius, 0 if e / total < 0.5 else 1,
                                                                             e_to[0], e_to[1]),
        '<path d="M{} {} A {} {}, 0, {}, 1, {} {}" stroke="orange" />'.format(e_to[0], e_to[1],
                                                                              radius, radius, 0 if m / total < 0.5 else 1,
                                                                              m_to[0], m_to[1]),
        '<path d="M{} {} A {} {}, 0, {}, 1, {} {}" stroke="red" />'.format(m_to[0], m_to[1],
                                                                           radius, radius, 0 if h / total < 0.5 else 1,
                                                                           h_to[0], h_to[1]),
        '<text x="{}" y="{}" class="small">{}</text>'.format(text_pos[0], text_pos[1],
                                                             text[0]),
        '<text x="{}" y="{}" class="esy">{}</text>'.format(text_pos[0], text_pos[1] + 10,
                                                           e),
        '<text x="{}" y="{}" class="small">{}</text>'.format(text_pos[0], text_pos[1] + 25,
                                                             text[1]),
        '<text x="{}" y="{}" class="mdm">{}</text>'.format(text_pos[0], text_pos[1] + 35,
                                                           m),
        '<text x="{}" y="{}" class="small">{}</text>'.format(text_pos[0], text_pos[1] + 50,
                                                             text[2]),
        '<text x="{}" y="{}" class="hrd">{}</text>'.format(text_pos[0], text_pos[1] + 60,
                                                           h),
        '<text x="{}" y="{}" class="small">{}</text>'.format(text_pos[0], text_pos[1] + 75,
                                                             text[3]),
        '<text x="{}" y="{}" class="small">{}</text>'.format(text_pos[0], text_pos[1] + 85,
                                                             e+m+h),
        '</svg>'])


def __table_row(line: list[str], details: local.QuestionDetails, base: str):
    line[2] += str(details.id())
    line[3] += "[📎]({}/src/{}/q{}.hpp)".format(base, local.id_folder(details.id()),
                                               str(details.id()).zfill(4))
    line[4] += "[{}](https://leetcode.com/problems/{}/)".format(details.title(),
                                                                details.slug())
    line[5] += "{}".format("Hard" if details.level() == 3 else (
        "Medium" if details.level() == 2 else "Easy"))
    return line


def table_row(date: str, details: list[local.QuestionDetails], base: str = "."):
    line: list[str] = ["", date, "", "", "", "", ""]
    line = __table_row(line, details[0], base)
    for i in range(1, len(details)):
        for j in range(2, 6):
            line[j] += "<br>"
        line = __table_row(line, details[i], base)
    return "|".join(line)


def log_readme(month: str, solved_logs: list[local.Log], ques_data: local.QuestionList):
    day_map: dict[int, list[local.QuestionDetails]] = {}
    for log in solved_logs:
        d = int(time.strftime("%d",
                              time.localtime(log.timestamp())))
        if d not in day_map:
            day_map[d] = []
        details = ques_data.get(log.id())
        day_map[d].append(details)

    table_content: list[str] = []
    for date, details_list in sorted(day_map.items(), key=lambda t: t[0], reverse=True):
        details_list.sort(key=lambda e: e.id())
        table_content.append(table_row("Day {}".format(date),
                                       details_list, ".."))

    return "\n".join([
        "## {}".format(month),
        "",
        "||#|</>|Question Title|Difficulty|",
        "|:--|--:|:-:|:--|:--|",
        "\n".join(table_content),
        "",
        ""])
