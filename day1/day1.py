
def getCalorieList(file_path):
    with open(file_path, 'r') as file:
        calorie_list = file.read().splitlines()
    return calorie_list

def getSumPerElfCalorieList(calorie_list):
    counter = 0
    condensed_calorie_list = []
    for i in range(len(calorie_list)):
        if calorie_list[i] != "":
            counter += int(calorie_list[i])
        if calorie_list[i] == "":
            condensed_calorie_list.append(counter)
            counter = 0
    return sorted(condensed_calorie_list, reverse=True)

def printCalories(calorie_list):
    print("Max Calories: " + str(calorie_list[0]))
    print("Sum of Top Three Calories: " + str(calorie_list[0] + calorie_list[1] + calorie_list[2]))

def main():
    small_calorie_list = getCalorieList("small_input.txt")
    large_calorie_list = getCalorieList("input_day1.txt")

    condensed_small_list = getSumPerElfCalorieList(small_calorie_list)
    condensed_large_list = getSumPerElfCalorieList(large_calorie_list)

    print("Day 1 Part 1")
    printCalories(condensed_small_list)
    print()
    print("Day 1 Part 2")
    printCalories(condensed_large_list)

    #For debug
#    print(small_calorie_list)
#    print(large_calorie_list)

if __name__ == "__main__":
    main()