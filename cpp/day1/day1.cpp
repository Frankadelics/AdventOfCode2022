#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int getMaxCalories(string filename)
{
    string input = "";
    int counter = 0;
    int max_value = 0;
    ifstream readFromFile(filename);
    while (getline(readFromFile, input)) {
        if (input != "")
            counter += stoi(input);
        if (input == "") {
            if (max_value <= counter)
                max_value = counter;
            counter = 0;
        }
    }
    return max_value;
}

int main()
{
    //Part 1
    cout << "Max Calories: " << getMaxCalories("small_input.txt") << endl;
    cout << "Max Calories: " << getMaxCalories("input_day1.txt") << endl;
    
    return 0;
}