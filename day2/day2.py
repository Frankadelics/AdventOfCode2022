def tallyPointsPart1(input_string, tally_list):
    if input_string == "B X":
        tally_list[1] += 1
    if input_string == "C Y":
        tally_list[2] += 1
    if input_string == "A Z":
        tally_list[3] += 1
    if input_string == "A X":
        tally_list[4] += 1
    if input_string == "B Y":
        tally_list[5] += 1
    if input_string == "C Z":
        tally_list[6] += 1
    if input_string == "C X":
        tally_list[7] += 1
    if input_string == "A Y":
        tally_list[8] += 1
    if input_string == "B Z":
        tally_list[9] += 1
    
def tallyPointsPart2(input_string, tally_list):
    if input_string == "B X":
        tally_list[1] += 1
    if input_string == "C X":
        tally_list[2] += 1
    if input_string == "A X":
        tally_list[3] += 1
    if input_string == "A Y":
        tally_list[4] += 1
    if input_string == "B Y":
        tally_list[5] += 1
    if input_string == "C Y":
        tally_list[6] += 1
    if input_string == "C Z":
        tally_list[7] += 1
    if input_string == "A Z":
        tally_list[8] += 1
    if input_string == "B Z":
        tally_list[9] += 1 

def getList(file_path):
    tally_list = []
    with open(file_path, 'r') as file:
        tally_list = [x.strip() for x in file.readlines()]
        return tally_list

def calcScore(tally_list):
    total_score = 0
    for x in range(len(tally_list)):
        total_score += tally_list[x] * x
    return total_score

def main():
    #Lists that hold input
    small_tally_list = getList("small_input_day2.txt")
    large_tally_list = getList("large_input_day2.txt")
    
    #Part 1
    small_tally_counter = [0] * 10
    large_tally_counter = [0] * 10
    for x in range(len(small_tally_list)):
        tallyPointsPart1(small_tally_list[x], small_tally_counter)
    for x in range(len(large_tally_list)):
        tallyPointsPart1(large_tally_list[x], large_tally_counter)
    print("Total Score: " + str(calcScore(small_tally_counter)))
    print("Total Score: " + str(calcScore(large_tally_counter)))

    #Part2
    small_tally_counter_2 = [0] * 10
    large_tally_counter_2 = [0] * 10
    for x in range(len(small_tally_list)):
        tallyPointsPart2(small_tally_list[x], small_tally_counter)
    for x in range(len(large_tally_list)):
        tallyPointsPart2(large_tally_list[x], large_tally_counter)
    print("Total Score: " + str(calcScore(small_tally_counter_2)))
    print("Total Score: " + str(calcScore(large_tally_counter_2)))


if __name__ == "__main__":
    main()