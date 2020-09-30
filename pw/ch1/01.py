import random

def guessing_game():
    number = random.randint(1, 100)

    while True:
        guess = int(input("Guess a number: "))

        if guess > number:
            print(f"{guess} is too high. Guess again.")
        elif guess < number:
            print(f"{guess} is too low. Guess again.")
        else:
            print(f"{guess} - you got it!")
            break

guessing_game()
