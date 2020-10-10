# Exercise 4 Hexadecimal output

def hex_output():
    decnum = 0
    hexnum = input("Enter number in hexadecimal: ")
    for index, letter in enumerate(reversed(hexnum)):
        decnum += int(letter, 16) * 16 ** index

    return decnum

print(hex_output())