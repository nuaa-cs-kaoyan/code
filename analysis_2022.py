# -*- coding: utf-8 -*-
import pandas as pd
import matplotlib.pyplot as plt

# config
plt.rcParams[u'font.sans-serif'] = ['simhei']
plt.rcParams['axes.unicode_minus'] = False
line_marker = '-o'


def load_total_score_dataframe():
    """加载 2021录取数据-总分.txt"""
    file = "source_data/2022录取名单数据.txt"
    with open(file, 'r', encoding="utf8") as fr:
        lines = fr.readlines()
    data = []
    for line in lines:
        infos = line.strip().split(" ")
        data.append({
            "专业": infos[0],
            "初试": int(infos[1]),
            "复试": float(infos[2]),
            "总分": float(infos[3]),
        })

    pd_data = pd.DataFrame(data)
    return pd_data

def analysis_total_score():
    """已经剔除了退伍大学生计划的数据"""
    pd_data = load_total_score_dataframe()

    pd_data_group_describe = pd_data.groupby(["专业"]).describe()
    pd_data_group_describe.to_csv("2022-初复试总分分析.csv", encoding="utf8")
    print(pd_data_group_describe)




if __name__ == "__main__":
    analysis_total_score()
    pass