# -*- coding: utf-8 -*-
import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei'] #设置字体，设置了字体后，负号会变成乱码
plt.rcParams['axes.unicode_minus'] = False

x_index_chushi = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
x_index_fushi = [0, 1, 2, 3, 4, 5, 6, 7]
bins_chushi = [320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420]
bins_fushi = [220, 230, 240, 250, 260, 270, 280, 290]
title_chushi = "熊二学长(QQ 321556185)：南航计算机考研2022录取结果分析 - 初试总分分析"
title_fushi = "熊二学长(QQ 321556185)：南航计算机考研2022录取结果分析 - 复试总分分析"


def load_total_score_dataframe():
    """加载 2021录取数据-总分.txt"""
    file = "source_data/2023复试名单-各科分数.txt"
    with open(file, 'r', encoding="utf8") as fr:
        lines = fr.readlines()
    data = []
    for line in lines:
        infos = line.strip().split(" ")
        print(infos)
        data.append({
            "专业": infos[3],
            "数学": int(infos[6]),
            "专业课": int(infos[7]),
            "英语": int(infos[5]),
            "政治": int(infos[4]),
            "总分": int(infos[8])
        })

    pd_data = pd.DataFrame(data)
    return pd_data

def analysis_total_score():
    """已经剔除了退伍大学生计划的数据"""
    pd_data = load_total_score_dataframe()
    pd_data_group_describe = pd_data.groupby(["专业"]).describe()
    pd_data_group_describe.to_csv("2023-初试各科分数分析.csv", encoding="utf8")
    print(pd_data_group_describe)

if __name__ == "__main__":
    # 分析 2023 初试成绩
    analysis_total_score()
