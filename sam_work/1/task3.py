import matplotlib.pyplot as plt

with open("data3") as f:
    x = [float(i.split()[0]) for i in f.readlines()]
    f.seek(0)
    y = [int(i.split()[1]) for i in f.readlines()]

plt.figure(1)
plt.plot(x, y)
plt.xlabel("Шаг итерации tau")
plt.ylabel("Кол-во итераций")
plt.grid()
plt.savefig("task3.png")

with open("data4_simple_iterative") as f:
    x = [int(i.split()[0]) for i in f.readlines()]
    f.seek(0)
    y = [float(i.split()[1]) for i in f.readlines()]

plt.figure(2)
plt.plot(x, y)
plt.xlabel("Номер итерации")
plt.ylabel("Норма невязки")
plt.grid()
plt.savefig("task4_simple_iterative.png")

with open("data4_jacobi") as f:
    x = [int(i.split()[0]) for i in f.readlines()[:101]]
    f.seek(0)
    y = [float(i.split()[1]) for i in f.readlines()[:101]]

plt.figure(3)
plt.plot(x, y)
plt.xlabel("Номер итерации")
plt.ylabel("Норма невязки")
plt.grid()
plt.savefig("task4_jacobi.png")

with open("data4_gauss_seidel") as f:
    x = [int(i.split()[0]) for i in f.readlines()[:101]]
    f.seek(0)
    y = [float(i.split()[1]) for i in f.readlines()[:101]]

plt.figure(4)
plt.plot(x, y)
plt.xlabel("Номер итерации")
plt.ylabel("Норма невязки")
plt.grid()
plt.savefig("task4_gauss_seidel.png")
