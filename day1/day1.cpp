#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

void createCalorieVector(vector<int>& calories, string filename)
{
    string input = "";
    int counter = 0;
    ifstream readFromFile(filename);
    while (getline(readFromFile, input)) {
        if (input != "")
            counter += stoi(input);
        if (input == "") {
            calories.push_back(counter);
            counter = 0;
        }
    }

}

void calculateCalories(vector<int>& calories)
{
    sort(calories.begin(), calories.end(), greater<int>());
    cout << "Max Calories: " << calories[0] << endl;
    cout << "Sum of Top Three Calories: " << calories[0] + calories[1] + calories[2] << endl;
}

int main()
{
    vector<int> large_input_calories;
    vector<int> small_input_calories;

    //Create vector of calories for each input
    createCalorieVector(small_input_calories, "small_input.txt");
    createCalorieVector(large_input_calories, "input_day1.txt");

    //Calculate and print the 
    calculateCalories(small_input_calories);
    calculateCalories(large_input_calories);

    //For Debug
//    printVector(small_input_calories);
//    printVector(large_input_calories);

    return 0;
}