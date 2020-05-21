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


x = [1, 2, 3, 4]
# data
x_label = ["2017届", "2018届", "2019届", "2020届"]
y_统考_录取人数 = [90, 102, 139, 211]
y_985调剂_录取人数 = [18, 46, 39, 0]
y_学硕_计算机_录取人数 = [25, 27, 31, 36]
y_学硕_软工_录取人数 = [12, 12, 15, 24]
y_学硕_网安_录取人数 = [4, 12, 15, 24]
y_专硕_录取人数 = [49, 51, 78, 127]

y_list = [(y_统考_录取人数, "统考-录取人数"),
          (y_985调剂_录取人数, "985调剂-录取人数"),
          (y_学硕_计算机_录取人数, "学硕-计算机-录取人数"),
          (y_学硕_软工_录取人数, "学硕-软工-录取人数"),
          (y_学硕_网安_录取人数, "学硕-安全-录取人数"),
          (y_专硕_录取人数, "专硕-录取人数")]

plt.xticks(x, x_label)
plt.ylabel("人数")
plt.title("南航计算机考研历年录取情况")

for y in y_list[:]:
    plt.plot(x, y[0], "-o", label=y[1])
    for x_data, y_data in zip(x, y[0]):
        plt.text(x_data, y_data, y_data, ha='right', va='bottom', fontsize=10)

plt.legend(loc='upper left')
plt.savefig(image_path + "visualization.png", dip=300)

plt.show()

