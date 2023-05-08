import matplotlib.pyplot as plt
import math

with open("data1-1.txt") as f:
    x1 = [int(i.split()[0])+1 for i in f.readlines()[:30]]
    f.seek(0)
    y1 = [math.log(float(i.split()[1])+0.001) for i in f.readlines()[:30]]

with open("data1-2.txt") as f:
    x2 = [int(i.split()[0])+1 for i in f.readlines()[:30]]
    f.seek(0)
    y2 = [math.log(float(i.split()[1])+0.001) for i in f.readlines()[:30]]

with open("data1-3.txt") as f:
    x3 = [int(i.split()[0])+1 for i in f.readlines()[:30]]
    f.seek(0)
    y3 = [math.log(float(i.split()[1])+0.001) for i in f.readlines()[:30]]

with open("data1-4.txt") as f:
    x4 = [int(i.split()[0])+1 for i in f.readlines()[:30]]
    f.seek(0)
    y4 = [math.log(float(i.split()[1])+0.001) for i in f.readlines()[:30]]

plt.plot(x1, y1, label='Град. спуск 1/lambda_max')
plt.plot(x2, y2, label='Град. спуск c опт. пар.')
plt.plot(x3, y3, label='Чеб. ускорение c 8 узл.')
plt.plot(x4, y4, label='Симм. Г-3')
plt.xlabel("Номер итерации")
plt.ylabel("Невязка (ln(r+0.001))")
plt.grid()
plt.legend()
plt.savefig("task1.png")