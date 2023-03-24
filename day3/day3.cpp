#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<string> getVector(string filename)
{
	vector<string> rucksack;
	string input = "";
	ifstream readFromFile(filename);
	while (getline(readFromFile, input))
		rucksack.push_back(input);
	return rucksack;
}

vector<string> splitCompartment(string compartment)
{
	vector<string> compartment_holder;
	int length = compartment.length();
	int half_length = length / 2;
	compartment_holder.push_back(compartment.substr(0, half_length));
	compartment_holder.push_back(compartment.substr(half_length, length));
	return compartment_holder;
}

vector<char> createCharVec(string compartment)
{
	vector<char> comp_char;
	for (int i = 0; i < compartment.length(); i++)
		comp_char.push_back(compartment[i]);
	sort(comp_char.begin(), comp_char.end());
	return comp_char;
}

vector<char> getPriority(vector<string>& rucksack)
{
	string comp1 = "";
	string comp2 = "";
	vector<string> comp_holder;
	vector<char> vec1, vec2, holder, priority_list;
	char container;
	for (int i = 0; i < rucksack.size(); i++)
	{
		comp_holder = splitCompartment(rucksack[i]);
		comp1 = comp_holder[0];
		comp2 = comp_holder[1];
		comp_holder.clear();

		vec1 = createCharVec(comp1);
		vec2 = createCharVec(comp2);

		set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(holder));
		container = holder[0];
		holder.clear();
		priority_list.push_back(container);
	}
	return priority_list;
}

vector<char> getBadge(vector<string>& rucksacks)
{
	vector<char> rucksack1, rucksack2, rucksack3, rucksack12, priority_list, holder;
	char character;
	for (int i = 0; i < rucksacks.size(); i+=3)
	{
		rucksack1.clear(); rucksack2.clear(); rucksack3.clear(); rucksack12.clear();
		rucksack1 = createCharVec(rucksacks[i]);
		rucksack2 = createCharVec(rucksacks[i + 1]);
		rucksack3 = createCharVec(rucksacks[i + 2]);
		set_intersection(rucksack1.begin(), rucksack1.end(), rucksack2.begin(), rucksack2.end(), back_inserter(rucksack12));
		set_intersection(rucksack12.begin(), rucksack12.end(), rucksack3.begin(), rucksack3.end(), back_inserter(holder));
		character = holder[0];
		holder.clear();
		priority_list.push_back(character);
	}
	return priority_list;
}

void calculatePriority(vector<char>& badge)
{
	int counter = 0;
	for (int i = 0; i < badge.size(); i++)
	{
		if (int(badge[i]) >= 97 && int(badge[i]) <= 122)
			counter += int(badge[i]) - 96;
		else
			counter += int(badge[i]) - 38;
	}
	cout << "Total Priority: " << counter << endl;
}

int main()
{
	vector<string> small_rucksack;
	vector<string> large_rucksack;
	vector<char> small_priority;
	vector<char> large_priority;
	vector<char> small_badge;
	vector<char> large_badge;

	//Part 1
	cout << "Part 1" << endl;
	small_rucksack = getVector("small_input_day3.txt");
	large_rucksack = getVector("large_input_day3.txt");

	small_priority = getPriority(small_rucksack);
	large_priority = getPriority(large_rucksack);

	calculatePriority(small_priority);
	calculatePriority(large_priority);

	cout << endl;

	//Part 2
	cout << "Part 2" << endl;
	small_badge = getBadge(small_rucksack);
	large_badge = getBadge(large_rucksack);

	calculatePriority(small_badge);
	calculatePriority(large_badge);
	
	return 0;
}