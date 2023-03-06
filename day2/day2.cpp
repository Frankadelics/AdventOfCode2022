/*
    A - Rock
    B - Paper
    C - Scissors

    X - Choose Rock
    Y - Choose Paper
    Z - Choose Scissors

    Points Awarded for Shape
    1  - Rock
    2  - Paper
    3  - Scissors 

    Points Awarded for Outcome
    0 - Lose
    3 - Draw
    6 - Win
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//class Score() {
//    private:
//        string choice = "";
//        char outcome = '';
//        int score = 0;
//    public:
//        getChoice() { return choice; }
//        getOutcome() { return outcome; }
//        getScore() { return score; }
//}

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

void calcScore()
{
    int total_score = 0;
    for (int i = 0; i < 10; i++)
        total_score += tallys[i] * i;
    cout << "Total Score: " << total_score << endl;
}

void getInputVector(string filename)
{
    string input = "";
    ifstream readFromFile(filename);
    while (getline(readFromFile, input)) {
        tallyPointsPart1(input);
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
    //Part 1
    getInputVector("small_input_day2.txt");
    calcScore();
    clearTallys();
    getInputVector("large_input_day2.txt");
    calcScore();
    clearTallys();

    return 0;
}