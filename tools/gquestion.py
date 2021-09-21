#!/usr/bin/python3
import sys
import os
import re
import math
import pathlib
import subprocess
from utils import leetcode

if((len(sys.argv) - 2) % 3):
    print("[Usage] <question number>")
else:
    gen = os.path.basename(__file__)
    quest_num = str(int(sys.argv[1]))
    project_path = pathlib.Path(__file__).parent.parent.resolve()
    interval_name = leetcode.get_question_id_path(int(quest_num))
    source_root_path = os.path.join(project_path, "src")
    source_path = os.path.join(source_root_path, interval_name)
    source_name = "q{}.hpp".format(quest_num.rjust(4, '0'))
    source = os.path.join(source_path, source_name)
    unittest_name = "q{}_unittest.hpp".format(quest_num.rjust(4, '0'))
    unittest = os.path.join(source_path, unittest_name)

    if os.path.exists(source):
        print("[-] file exist: {}".format(source))
    elif os.path.exists(unittest):
        print("[-] file exist: {}".format(unittest))
    else:
        description = leetcode.get_description(
            int(quest_num), "this file is generated by {}".format(gen))
        if description != None:
            utindex = os.path.join(source_path, "unittest.hpp")
            if not os.path.isdir(source_path):
                os.makedirs(source_path)
                print("[+] create directory: {}".format(source_path))
                with open(utindex, 'w') as f:
                    f.write("\n")
                    f.write("#ifndef {}_UNITTEST\n".format(
                        interval_name.upper()))
                    f.write("#define {}_UNITTEST\n".format(
                        interval_name.upper()))
                    f.write("#endif")
                    f.truncate()
                print("[+] create file: {}".format(utindex))
                with open(os.path.join(source_root_path, "unittest.cc"), 'r+') as f:
                    text = f.readlines()
                    index = 0
                    for i in range(0, len(text)):
                        index = i
                        if re.search("#include", text[i]):
                            num = re.search("Q_(\d*)_(\d*)", text[i])
                            if num and int(num.group(1)) > int(quest_num):
                                break
                            elif num and int(num.group(1)) < int(quest_num) and int(num.group(2)) > int(quest_num):
                                index = len(text) - 1
                                break
                        else:
                            break

                    if index < len(text) - 1:
                        text.insert(
                            index, "#include \"{}/unittest.hpp\"\n".format(interval_name.lower()))
                        f.seek(0)
                        f.write("".join(text))
                        f.truncate()
                        print("[+] modify unittest.cc.")

            with open(source, 'w') as f:
                f.write("\n")
                f.write("#ifndef LEETCODE_Q{}_H__\n".format(quest_num))
                f.write("#define LEETCODE_Q{}_H__\n".format(quest_num))
                f.write("#include <iostream>\n")
                f.write("\n")
                f.write("namespace l{} {{\n".format(quest_num))
                f.write("using namespace std;\n")
                f.write("\n")
                f.writelines(description)
                f.write("\n")
                f.write("   // Put your code here\n")
                f.write("}}  // namespace l{}\n".format(quest_num))
                f.write("#endif")
                f.truncate()

            print("[+] create file: {}".format(source))

            with open(unittest, 'w') as f:
                f.write("\n")
                f.write("#ifndef Q{}_UNITTEST_H__\n".format(quest_num))
                f.write("#define Q{}_UNITTEST_H__\n".format(quest_num))
                f.write("#include <gtest/gtest.h>\n")
                f.write("\n")
                f.write("#include \"{}\"\n".format(source_name))
                f.write("using namespace std;\n")
                f.write("\n")
                f.writelines(description)
                f.write("\n")
                f.write("TEST(q{}, sample_input01) {{\n".format(quest_num))
                f.write("}\n")
                f.write("\n")
                f.write("#endif")
                f.truncate()

            print("[+] create file: {}".format(unittest))

            with open(utindex, 'r+') as f:
                text = f.readlines()
                for i in range(0, len(text)):
                    if text[i] == "#endif":
                        text.insert(i, "#include \"{}\"\n".format(unittest_name))
                        print("[+] modifify file: {}".format(utindex))
                        f.seek(0)
                        f.write("".join(text))
                        f.truncate()
                        break

            # with open(os.path.join(project_path, "README.md"), "r+") as f:
            #     text = f.readlines();
            #     for i in range(0, len(text)):
            #         if re.match("{}".format(quest_num.rjust(4, "0"))):
            #             break

            subprocess.run(["code", source])
            subprocess.run(["code", unittest])

        else:
            print(
                "[-] question #{} need plus account or does not exist.".format(quest_num))
            sys.exit()
