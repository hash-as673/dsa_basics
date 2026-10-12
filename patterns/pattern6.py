n = 5
for i in range(n):
    x = 1
    for j in range(n-i):
        print(x, end="")
        x += 1
    print()