import pandas as pd, numpy as np, matplotlib.pyplot as plt
df=pd.read_csv("TimeComplexity\SelectionSortTC.csv")
x=[]
y=[]
for row in range(len(df)):
        x.append(df["n"][row])
        y.append(df["time_taken"][row])
plt.bar(x, y, color = 'g', width = 0.72, label = "Time_Complexity")
plt.xlabel('n')
plt.ylabel('Timetaken')
plt.legend()
plt.show()