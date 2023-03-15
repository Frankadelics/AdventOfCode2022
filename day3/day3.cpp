#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

class RuckSack
{
	private:
		string both_comp = "";
		string comp1 = "";
		string comp2 = "";
		int priority = 0;
	public:
		//Getters
		string getBothComp() { return both_comp; }
		string getComp1() { return comp1; }		
		string getComp2() { return comp2; }
		int getPriority() { return priority; }
		
		//Setters
		void setBothComp(string comp) { both_comp = comp; }
		void setComp1(string comp) { comp1 = comp; }		
		void setComp2(string comp) { comp2 = comp; }
		void setPriority(int prio) { priority = prio; }
};

void getInput(vector<RuckSack>& rucksack_vector, string filename)
{
	string input = "";
	RuckSack item;
	ifstream readFromFile(filename);
	while (getline(readFromFile, input))
	{
		item.setBothComp(input);
		rucksack_vector.push_back(item);
	}
}

void printBothComp(vector<RuckSack>& rucksack_vector)
{
	for (int i = 0; i < rucksack_vector.size(); i++)
		cout << rucksack_vector[i].getBothComp() << endl;
}

void printSplitComps(vector<RuckSack>& rucksack_vector)
{
	for (int i = 0; i < rucksack_vector.size(); i++)
		cout << rucksack_vector[i].getComp1() << " | " << rucksack_vector[i].getComp2() << endl;
}

void printPriority(vector<RuckSack>& rucksack_vector)
{
	for (int i = 0; i < rucksack_vector.size(); i++)
		cout << rucksack_vector[i].getPriority() << endl;
}

int calculateFullPriority(vector<RuckSack>& rucksack_vector)
{
	int counter = 0;
	for (int i = 0; i < rucksack_vector.size(); i++)
		counter += rucksack_vector[i].getPriority();
	
	return counter;
}

int findMatch(string comp1, string comp2)
{
	for (int i = 0; i < comp1.length(); i++)
	{
		for (int j = 0; j < comp2.length(); j++)
		{
			if (comp1[i] == comp2[j])
			{
				//Lower case letters offset
				if (int(comp1[i]) >= 97 && int(comp1[i]) <= 122)
					return int(comp1[i]) - 96;
				//Upper case letters offset
				else
					return int(comp1[i]) - 38;
			}
		}
	}
	return 0;
}

void splitCompartments(vector<RuckSack>& rucksack_vector)
{
	string comp1 = "";
	string comp2 = "";
	string full_comp = "";
	int length = 0;
	int half_length = 0;
	for (int i = 0; i < rucksack_vector.size(); i++)
	{
		full_comp = rucksack_vector[i].getBothComp();
		length = full_comp.length();
		half_length = length / 2;
		comp1 = full_comp.substr(0, half_length);
		comp2 = full_comp.substr(half_length, length - 1);

		rucksack_vector[i].setComp1(comp1);
		rucksack_vector[i].setComp2(comp2);
		rucksack_vector[i].setPriority(findMatch(comp1, comp2));
	}
}

int main()
{
	vector<RuckSack> small_rucksack;
	vector<RuckSack> large_rucksack;

	//Common between daus
	getInput(small_rucksack, "small_input_day3.txt");
	getInput(large_rucksack, "large_input_day3.txt");
	
	//Day 1
	cout << "Day 1" << endl;
	splitCompartments(small_rucksack);
	cout << "Small Total Priority: " << calculateFullPriority(small_rucksack) << endl;
	//printBothComp(small_rucksack);
	//printSplitComps(small_rucksack);
	//printPriority(small_rucksack);

	splitCompartments(large_rucksack);
	cout << "Large Total Priority: " << calculateFullPriority(large_rucksack) << endl;
	//printBothComp(large_rucksack);
	//printSplitComps(large_rucksack);
	//printPriority(large_rucksack);

	//Day 2
	cout << "Day 2" << endl;

	return 0;
}

