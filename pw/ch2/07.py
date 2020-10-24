# Exercise 7 Ubbi Dubbi
def ubbi_dubbi(word):
    output = []
    for char in word:
        if char in 'aeiou':
            output.append(f"ub{char}")
        else:
            output.append(char)
    return ''.join(output)

print(ubbi_dubbi("elephant"))