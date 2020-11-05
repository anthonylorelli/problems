# Exercise 10 Summing anything
def mysum(*args):
    if not args:
        return args
    result = args[0]
    for val in args[1:]:
        result += val
    return result

print(mysum(1,2,3))
print(mysum("a", "b", "c"))
print(mysum((2.0,), (3.0,), (4.0,)))
