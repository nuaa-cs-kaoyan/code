# -*- coding: utf-8 -*-
"""
2020-03-26

@author: wanshuo
"""
import matplotlib.pyplot as plt


image_path = "images/"

# config
plt.rcParams[u'font.sans-serif'] = ['simhei']
plt.rcParams['axes.unicode_minus'] = False
line_marker = '-o'


x = [2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024]
# data
x_label = ["2017", "2018", "2019", "2020", "2021", "2022", "2023", "2024"]
y_统考_录取人数 = [90, 102, 139, 220, 176, 151, 136, 159]
y_985调剂_录取人数 = [18, 46, 39, 0, 0, 0, 0, 0]
y_学硕_计算机_录取人数 = [25, 27, 31, 36, 25, 30, 29, 30]
y_学硕_软工_录取人数 = [12, 12, 15, 24, 19, 17, 17, 17]
y_学硕_网安_录取人数 = [4, 12, 15, 24, 25, 21, 16, 20]
y_专硕_总录取人数 = [49, 51, 78, 136, 107, 83, 74, 67]
y_专硕_计算机 = [31, 18, 41, 0, 0, 0, 0, 30]
y_专硕_软工 = [18, 33, 37, 0, 0, 0, 0, 17]
y_专硕_网安 = [0, 0, 0, 0, 0, 0, 0, 20]

y_list = [(y_统考_录取人数, "统考-录取人数"),
          (y_985调剂_录取人数, "985调剂"),
          (y_学硕_计算机_录取人数, "学硕-计算机"),
          (y_学硕_软工_录取人数, "学硕-软工"),
          (y_学硕_网安_录取人数, "学硕-网安"),
          (y_专硕_总录取人数, "专硕"),
            (y_专硕_计算机, "专硕-计算机"),
            (y_专硕_软工, "专硕-软工"),
            (y_专硕_网安, "专硕-网安"),
          ]


plt.figure(figsize=(10, 8))  # 设置图像大小
plt.xticks(x, x_label)
plt.ylabel("人数")
plt.title("南航计算机考研历年统考录取情况 \n 熊二 2025南航计算机考研群：938584974")



for y in y_list[:]:
    plt.plot(x, y[0], "-o", label=y[1])
    for x_data, y_data in zip(x, y[0]):
        plt.text(x_data, y_data, y_data, ha='right', va='bottom', fontsize=10)

plt.legend(loc='upper left')
plt.savefig(image_path + "visualization.png", dip=300)


