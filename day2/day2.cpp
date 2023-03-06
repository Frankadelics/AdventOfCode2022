/*
    Opponents Choices
    A - Rock
    B - Paper
    C - Scissors

    Points Awarded for Shape
    1  - Rock
    2  - Paper
    3  - Scissors 

    Points Awarded for Outcome
    0 - Lose
    3 - Draw
    6 - Win

    Part 1 - What Shape Do I Pick?
    X - Choose Rock
    Y - Choose Paper
    Z - Choose Scissors

    Part 2 - What Outcome Do I Want?
    X - Need to Lose
    Y - Need to Draw
    Z - Need to Win
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int tallys[10];

void tallyPointsPart1(string input)
{
    if (input == "B X")
        tallys[1]++;   
    if (input == "C Y")
        tallys[2]++;
    if (input == "A Z")
        tallys[3]++;
    if (input == "A X")
        tallys[4]++;
    if (input == "B Y")
        tallys[5]++;
    if (input == "C Z")
        tallys[6]++;
    if (input == "C X")
        tallys[7]++;
    if (input == "A Y")
        tallys[8]++;
    if (input == "B Z")
        tallys[9]++;
}

void tallyPointsPart2(string input)
{
    if (input == "B X")
        tallys[1]++;   
    if (input == "C X")
        tallys[2]++;
    if (input == "A X")
        tallys[3]++;
    if (input == "A Y")
        tallys[4]++;
    if (input == "B Y")
        tallys[5]++;
    if (input == "C Y")
        tallys[6]++;
    if (input == "C Z")
        tallys[7]++;
    if (input == "A Z")
        tallys[8]++;
    if (input == "B Z")
        tallys[9]++;
}

void calcScore()
{
    int total_score = 0;
    for (int i = 0; i < 10; i++)
        total_score += tallys[i] * i;
    cout << "Total Score: " << total_score << endl;
}

void getInputVector(string filename, int part)
{
    string input = "";
    ifstream readFromFile(filename);
    while (getline(readFromFile, input)) {
        if (part == 1)
            tallyPointsPart1(input);
        else
            tallyPointsPart2(input);
    }
}

void clearTallys()
{
    for (int i = 0; i < 10; i++)
        tallys[i] = 0;
}

void printTallys()
{
    for (int i = 0; i < 10; i++)
        cout << i << " " << tallys[i] << endl;
}

int main()
{
    cout << "Part 1" << endl;
    getInputVector("small_input_day2.txt", 1);
    calcScore();
    clearTallys();
    getInputVector("large_input_day2.txt", 1);
    calcScore();
    clearTallys();

    cout << "Part 2" << endl;
    getInputVector("small_input_day2.txt", 2);
    calcScore();
    clearTallys();
    getInputVector("large_input_day2.txt", 2);
    calcScore();
    clearTallys();
    return 0;
}