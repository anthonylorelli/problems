# Exercise 2 Summing numbers
def mysum(*args):
    sum = 0
    for n in args:
        sum += n

    return sum

j = mysum(1, 2)
k = mysum(2, 3, 4)
l = mysum(3, 4, 5, 6)

print(f"Sum 1: {j} Sum 2: {k} Sum 3: {l}")