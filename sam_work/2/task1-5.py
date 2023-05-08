import matplotlib.pyplot as plt

with open("data1-5.txt") as f:
    x = [float(i.split()[0]) for i in f.readlines()]
    f.seek(0)
    y = [int(i.split()[1]) for i in f.readlines()]

plt.plot(x, y)
plt.xlabel("L_max при фикс. L_min")
plt.ylabel("Кол-во итераций")
plt.grid()
plt.savefig("task1-5.png")