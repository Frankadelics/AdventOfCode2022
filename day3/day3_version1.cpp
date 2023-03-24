#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
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

void getInput(vector<vector<char>>& rucksack_vector, string filename)
{
	string input;
	vector<char> line;
	const char *p = 0;
	ifstream readFromFile(filename);
	while (getline(readFromFile, input))
	{
		line.clear();
		p = input.c_str();
		for (int i = 0; i < input.length(); i++)
			line.push_back(*(p + i));
		sort(line.begin(), line.end());
		rucksack_vector.push_back(line);
	}
	cout << "Input Vector Size: " << rucksack_vector.size() << endl;
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

int calculateFullPriority(vector<char>& badge)
{
	int counter = 0;
	for (int i = 0; i < badge.size(); i++)
	{
		if (int(badge[i]) >= 97 && int(badge[i]) <= 122)
			counter += int(badge[i]) - 96;
		else
			counter += int(badge[i]) - 38;
	}
	return counter;
}

void printVector(vector<char>& rucksack)
{
	for (int i = 0; i < rucksack.size(); i++)
		cout << rucksack[i];
	cout << endl;
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

vector<char> findBadge(vector<vector<char>>& rucksack_vector)
{
	vector<char> vec1, vec2, vec3, vec12, intersection;
	int inc = 3;
	for (int i = 0; i < rucksack_vector.size(); i+=inc)
	{
		vec1.clear(); vec2.clear(); vec3.clear(); vec12.clear();
		vec1 = rucksack_vector[i];
		//printVector(vec1);
		vec2 = rucksack_vector[i + 1];
		//printVector(vec2);
		vec3 = rucksack_vector[i + 2];
		//printVector(vec3);
		set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec12));
		set_intersection(vec3.begin(), vec3.end(), vec12.begin(), vec12.end(), back_inserter(intersection));
	}
	return intersection;
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

void printVecVec(vector<vector<char>>& rucksack_vector)
{
	for (int i = 0; i < rucksack_vector.size(); i++)
	{
		for (int j = 0; j < rucksack_vector[i].size(); j++)
			cout << rucksack_vector[i][j];
		cout << endl;
	}
}

int main()
{
	//Day 1
	vector<RuckSack> small_rucksack;
	vector<RuckSack> large_rucksack;

	//Common between daus
	getInput(small_rucksack, "small_input_day3.txt");
	getInput(large_rucksack, "large_input_day3.txt");
	
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
	vector<vector<char>> small_sack;
	vector<vector<char>> large_sack;
	vector<char> small_intersection;
	vector<char> large_intersection;

	cout << "Day 2" << endl;
	getInput(small_sack, "small_input_day3.txt");
	getInput(large_sack, "large_input_day3.txt");

	cout << "large_sack size: " << large_sack.size() << endl;

	small_intersection = findBadge(small_sack);
	large_intersection = findBadge(large_sack);

	cout << "elements: " << large_intersection.size() << endl;
	cout << "small elements: " << small_intersection.size() << endl;

	//printVector(large_intersection);
	cout << "Small Total Priority: " << calculateFullPriority(small_intersection) << endl;
	cout << "Large Total Priority: " << calculateFullPriority(large_intersection) << endl;

	return 0;
}

