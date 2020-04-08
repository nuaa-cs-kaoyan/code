# -*- coding: utf-8 -*-
"""
2020-03-26

@author: wanshuo
"""

import re

path = "QQ号.txt"

qq_reg = "\d{9,12}"
fr = open(path, "r", encoding="utf-8")

qq_numbers = []
for line in fr.readlines():
    match_result = re.findall(qq_reg, line)
    if match_result:
        qq_numbers.append(match_result[0])

fr.close()
print(";".join(qq_numbers))

