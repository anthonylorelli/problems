import random
number = random.randint(1, 100)

while True:
    guess = int(input("Guess a number: "))

    if guess > number:
        print("Too high. Guess again.")
    elif guess < number:
        print("Too low. Guess again.")
    else:
        print("You got it!")
        break
