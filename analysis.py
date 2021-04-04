# -*- coding: utf-8 -*-
import pandas as pd
import matplotlib.pyplot as plt

# config
plt.rcParams[u'font.sans-serif'] = ['simhei']
plt.rcParams['axes.unicode_minus'] = False
line_marker = '-o'

file = "data_clean/2021录取数据.txt"
with open(file, 'r', encoding="utf8") as fr:
    lines = fr.readlines()

data = []
for line in lines:
    if not line.startswith("08"):
        continue
    infos = line.split(" ")
    data.append({
        "专业": infos[1],
        "初试": int(infos[4]),
        "复试": float(infos[5]),
        "总分": float(infos[6]),
    })

pd_data = pd.DataFrame(data)
pd_data_group_describe = pd_data.groupby(["专业"]).describe()
pd_data_group_describe.to_csv("test.csv", encoding="utf8")
print(pd_data_group_describe)
ax = pd_data_group_describe.plot(figsize=(10, 8))
fig = ax.get_figure()
fig.savefig('test.png', dip=300)