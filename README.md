#coding=gbk
import math
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
#本程序中,长度单位为cm,体积单位为ml.
lj_df = pd.DataFrame()
d=0.02#宽度
Vsteel=[]#存储所用钢材体积
rate=[]#存储高与直径之比
ratemin=[]
V=[]
for v in range(300,500,10):#分别对不同容积进行讨论
    V.append(v)
    for h in np.arange(5.0,20.0,0.1): #高的取值范围与步长
        for R in np.arange(3.0,15.0,0.1):#直径的取值范围与步长
            PI=math.pi
            y1=PI*(R-2*d)*(R-2*d)*(h-4*d)/4#易拉罐容积
            if(y1>=v-5 and y1<=v+5):#易拉罐所需容积取值范围
                y2=PI*R*R*h/4-y1#钢材体积
                Vsteel.append(y2)#存储钢材体积
                rate.append(h/R)#存储高与直径之比
    print(v)
    print(rate[Vsteel.index(min(Vsteel))])#输出所需钢材最少时的直径与高的比
    ratemin.append(rate[Vsteel.index(min(Vsteel))])
    Vsteel.clear()#清除存储值
    rate.clear()#清除存储值
    print("\n")
#生成表格
lj_df['V']=V
lj_df['rate']=ratemin
print(lj_df)
#生成散点图
plt.figure(figsize=(10,15),dpi=100)
plt.scatter(V,ratemin,c='red',s=100,label='Rate')
plt.xticks(range(300,500,10))
plt.yticks(np.arange(1,3,0.1))
plt.xlabel("Volumn",fontdict={'size':16})
plt.ylabel("Rate  h/R",fontdict={"size":16})
plt.title("can",fontdict={'size':20})
plt.legend(loc='best')
plt.show()
