from sys import deactivate_stack_trampoline
import numpy as np
import matplotlib.pyplot as plt
m=75
k=0.375
v0=80
def  dv_dt(v,t):
    return (m*9.8-k*(v**2))/m
t=np.linspace(0,50,1000)
v=np.zeros_like(t)
v[0]=v0
for i in range(1,len(t)):
    dt=t[i]-t[i-1]
    v[i]=v[i-1]+dv_dt(v[i-1],[t-1])*dt
    min_v=np.min(v)
    min_v_index=np.argmin(v)
    min_v_time=t[min_v_index]
print(min_v_time,"s")
asymptotic_v=np.sqrt(m*9.8/k)
print(asymptotic_v,"m/s")
plt.plot(t,v)
plt.show()
