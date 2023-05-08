import matplotlib.pyplot as plt

with open("data2-1.txt") as f:
    x1 = [float(i.split()[0]) for i in f.readlines()[:20]]
    f.seek(0)
    y1 = [float(i.split()[1]) for i in f.readlines()[:20]]

with open("data2-2.txt") as f:
    x2 = [float(i.split()[0]) for i in f.readlines()[:20]]
    f.seek(0)
    y2 = [float(i.split()[1]) for i in f.readlines()[:20]]

with open("data2-3.txt") as f:
    x3 = [float(i.split()[0]) for i in f.readlines()]
    f.seek(0)
    y3 = [float(i.split()[1]) for i in f.readlines()]

with open("data2-4.txt") as f:
    x4 = [float(i.split()[0]) for i in f.readlines()[:20]]
    f.seek(0)
    y4 = [float(i.split()[1]) for i in f.readlines()[:20]]

with open("data2-5.txt") as f:
    x5 = [float(i.split()[0]) for i in f.readlines()]
    f.seek(0)
    y5 = [float(i.split()[1]) for i in f.readlines()]

#plt.plot(x1, y1, label="Град. спуск 0.9 * 2 / L_max")
#plt.plot(x2, y2, label="Град. спуск с опт. парам.")
plt.plot(x3, y3, label="Наиск. град. спуск")
#plt.plot(x4, y4, label="Чеб. ускорение с 8 узл.")
plt.plot(x5, y5, label="Сопряж. град.")
plt.xlabel("L_min")
plt.ylabel("L_max")
plt.grid()
plt.legend()
plt.savefig("task2 (without 1, 2 and 4).png")