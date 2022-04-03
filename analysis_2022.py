# -*- coding: utf-8 -*-
import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimHei'] #设置字体，设置了字体后，负号会变成乱码
plt.rcParams['axes.unicode_minus'] = False

x_index = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
bins = [320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420]
# labels = ['340', '340 — 350', '350 — 360', '360 — 370', '370 — 380', '380 — 390', '390 — 400', '400 — 410', '410 — 420']
title = "熊二学长(QQ 321556185)：南航计算机考研2022录取结果分析 - 初试总分分析"


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


def analysis_chushi():
    pd_data = load_total_score_dataframe()
    series_电子信息 = pd_data[pd_data.专业 == "专硕-电子信息"]["初试"]
    series_学硕_计科 = pd_data[pd_data.专业 == "学硕-计科"]["初试"]
    series_学硕_软工 = pd_data[pd_data.专业 == "学硕-软工"]["初试"]
    series_学硕_网安 = pd_data[pd_data.专业 == "学硕-网安"]["初试"]
    pd_analysis_电子信息 = pd.value_counts(series_电子信息, bins=bins, sort=False)
    print(pd_analysis_电子信息)
    pd_analysis_学硕_计科 = pd.value_counts(series_学硕_计科, bins=bins, sort=False)
    pd_analysis_学硕_软工 = pd.value_counts(series_学硕_软工, bins=bins, sort=False)
    pd_analysis_学硕_网安 = pd.value_counts(series_学硕_网安, bins=bins, sort=False)

    pd_merge = pd.concat([pd_analysis_电子信息, pd_analysis_学硕_计科, pd_analysis_学硕_软工, pd_analysis_学硕_网安], axis=1)
    pd_merge.columns = ["电子信息", "学硕_计科", "学硕_软工", "学硕_网安"]

    print(pd_merge)
    ax = pd_merge.plot(figsize=(15, 13),
                       kind='bar',
                       title=title,
                       width=0.8,
                       xlabel="分数区间",
                       ylabel="录取人数")

    for x, y in zip(x_index, pd_analysis_电子信息.tolist()):
        ax.text(x-0.3, y, y, ha = 'center',va = 'bottom',fontsize=15)
    for x, y in zip(x_index, pd_analysis_学硕_计科.tolist()):
        ax.text(x-0.1, y, y, ha = 'center',va = 'bottom',fontsize=15)
    for x, y in zip(x_index, pd_analysis_学硕_软工.tolist()):
        ax.text(x+0.1, y, y, ha = 'center',va = 'bottom',fontsize=15)
    for x, y in zip(x_index, pd_analysis_学硕_网安.tolist()):
        ax.text(x+0.3, y, y, ha = 'center',va = 'bottom',fontsize=15)

    fig = ax.get_figure()
    plt.show()
    fig.savefig('test.png', dip=500)

    # print(pd_data_电子信息_cut.unique())
    pass

def analysis_fushi():

    pass


if __name__ == "__main__":
    # analysis_total_score()
    analysis_chushi()
    pass