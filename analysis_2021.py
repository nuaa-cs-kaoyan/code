# -*- coding: utf-8 -*-
import pandas as pd
import matplotlib.pyplot as plt

# config
plt.rcParams[u'font.sans-serif'] = ['simhei']
plt.rcParams['axes.unicode_minus'] = False
line_marker = '-o'


def load_total_score_dataframe():
    """加载 2021录取数据-总分.txt"""
    file = "source_data/2021录取数据-总分.txt"
    with open(file, 'r', encoding="utf8") as fr:
        lines = fr.readlines()
    data = []
    for line in lines:
        infos = line.strip().split(" ")
        data.append({
            "id": infos[0],
            "专业": infos[1],
            "初试": int(infos[4]),
            "复试": float(infos[5]),
            "总分": float(infos[6]),
        })

    pd_data = pd.DataFrame(data)
    return pd_data


def load_each_subject_dataframe():
    """加载复试数据 """
    file = "source_data/2021复试名单-各科分数.txt"
    with open(file, 'r', encoding="utf8") as fr:
        lines = fr.readlines()
    data = []
    for line in lines[1:]:
        infos = line.strip().split(" ")
        data.append({
            "id": infos[0],
            "专业": infos[3],
            "政治": int(infos[5]),
            "英语": int(infos[6]),
            "数学": int(infos[7]),
            "专业课": int(infos[8]),
            "总分": int(infos[9])
        })

    pd_data = pd.DataFrame(data)
    return pd_data


def analysis_total_score():
    """已经剔除了退伍大学生计划的数据"""
    pd_data = load_total_score_dataframe()
    pd_data_group_describe = pd_data.groupby(["专业"]).describe()
    pd_data_group_describe.to_csv("2021-初复试总分分析.csv", encoding="utf8")
    print(pd_data_group_describe)
    ax = pd_data_group_describe.plot(figsize=(10, 8))
    fig = ax.get_figure()
    fig.savefig('test.png', dip=300)


def analysis_each_subject():
    """每个科目的平均分、分位"""
    pd_total_score = load_total_score_dataframe()
    pd_each_subject_score = load_each_subject_dataframe()
    enroll_ids = pd_total_score["id"].tolist()
    pd_each_subject_score = pd_each_subject_score[pd_each_subject_score.id.isin(enroll_ids)]
    pd_each_subject_score_describe = pd_each_subject_score.groupby(["专业"]).describe()
    pd_each_subject_score_describe.to_csv("2021-初复试单科分数分析.csv", encoding="utf8")


if __name__ == "__main__":
    # analysis_total_score()
    analysis_each_subject()
    pass