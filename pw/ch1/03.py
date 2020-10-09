# Exercise 3 Run Timing
def run_timing():
    total = 0.0
    count = 0

    while True:
        time = input("Enter 10 km run time: ")

        if not time:
            break

        count += 1
        total += int(time)

    avg = total / count
    print(f"Average of {avg}, over {count} runs")

run_timing()
