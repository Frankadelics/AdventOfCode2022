#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class ElfSection {
	private:
		int e1_begin = 0;
		int e2_begin = 0;
		int e1_end = 0;
		int e2_end = 0;
	public:
		//Getters
		int getE1begin() { return e1_begin; }		
		int getE2begin() { return e2_begin; }
		int getE1end() { return e1_end; }
		int getE2end() { return e2_end; }

		//Setters
		void setE1begin(int num) { e1_begin = num; }
		void setE2begin(int num) { e2_begin = num; }
		void setE1end(int num) { e1_end = num; }
		void setE2end(int num) { e2_end = num; }		
};

vector<int> parseSections(string input)
{
	//Format of f1-f2,n1-n2
	vector<int> sections;
	string delimiter1 = ",";
	string delimiter2 = "-";
	string token1, token2;

	//For f1
	token1 = input.substr(0, input.find(delimiter1)); //should have f1-f2
	//cout << "f1-f2: " << token1 << endl;
	token2 = token1.substr(0, token1.find(delimiter2)); //should have f1
	//cout << "f1: " << token2 << endl;
	sections.push_back(stoi(token2));

	//For f2
	token1 = input.substr(0, input.find(delimiter1)); //should have f1-f2
	//cout << "f1-f2: " << token1 << endl;
	token2 = token1.substr(token1.find(delimiter2) + 1, token2.length() + 1); //should have f2
	//cout << "f2: " << token2 << endl;
	sections.push_back(stoi(token2));

	//For n1
	token1 = input.substr(input.find(delimiter1) + 1, input.length()); //should have n1-n2
	//cout << "n1-n2: " << token1 << endl;
	token2 = token1.substr(0, token1.find(delimiter2)); //should have n1
	//cout << "n1: " << token2 << endl;
	sections.push_back(stoi(token2));

	//For n2
	token1 = input.substr(input.find(delimiter1) + 1, input.length()); //should have n1-n2
	//cout << "n1-n2: " << token1 << endl;
	token2 = token1.substr(token1.find(delimiter2) + 1, token2.length() + 1); //should have n2
	//cout << "n2: " << token2 << endl;
	sections.push_back(stoi(token2));

	return sections;
}

void findOverlapsPart1(vector<ElfSection> elf_sections)
{
	bool overlap1 = false;
	bool overlap2 = false;
	int counter = 0;
	ElfSection es;
	for (int i = 0; i < elf_sections.size(); i++)
	{
		es = elf_sections[i];
		//Check if first elf's sections fully overlap with the second elf's
		if (es.getE1begin() >= es.getE2begin() && es.getE1end() <= es.getE2end())
		{
			//cout << "overlap1: " << es.getE1begin() << "-" << es.getE1end() << "," << es.getE2begin() << "-" << es.getE2end() << endl;
			overlap1 = true;
		}
		
		//Check if the second elf's sections fully overlap with the first elf's
		if (es.getE2begin() >= es.getE1begin() && es.getE2end() <= es.getE1end())
		{
			//cout << "overlap2: " << es.getE1begin() << "-" << es.getE1end() << "," << es.getE2begin() << "-" << es.getE2end() << endl;
			overlap2 = true;
		}
		
		//If there is any overlap from either elf, then one range is fully within another
		if (overlap1 || overlap2)
				counter++;
		
		overlap1 = false;
		overlap2 = false;
	}
	cout << "Overlaps: " << counter << endl;
}

void findOverlapsPart2(vector<ElfSection> elf_sections)
{
	bool overlap1 = false;	
	bool overlap2 = false;
	int counter = 0;
	ElfSection es;
	for (int i = 0; i < elf_sections.size(); i++)
	{
		es = elf_sections[i];
		if (es.getE2begin() <= es.getE1begin() && es.getE2end() >= es.getE1begin())
			overlap1 = true;
		if (es.getE1begin() <= es.getE2begin() && es.getE1end() >= es.getE2begin())
			overlap2 = true;
		if (overlap1 || overlap2)
			counter++;
		overlap1 = false;
		overlap2 = false;
	}
	cout << "Overlaps: " << counter << endl;
}

void printSections(vector<ElfSection> elf_sections)
{
	for (int i = 0; i < elf_sections.size(); i++)
	{		
		cout << i << " Section" << endl;
		cout << "e1.begin: " << elf_sections[i].getE1begin() << endl;
		cout << "e1.end: " << elf_sections[i].getE1end() << endl;
		cout << "e2.begin: " << elf_sections[i].getE2begin() << endl;
		cout << "e2.end: " << elf_sections[i].getE2end() << endl;
		cout << endl;
	}
}

vector<ElfSection> getSections(string filename)
{
	vector<ElfSection> elf_sections;
	vector<int> sections;
	ElfSection es;
	string input = "";
	ifstream readFromFile(filename);
	while (getline(readFromFile, input))
	{
		sections = parseSections(input);
		es.setE1begin(sections[0]);
		es.setE1end(sections[1]);
		es.setE2begin(sections[2]);
		es.setE2end(sections[3]);
		elf_sections.push_back(es);
	}
	return elf_sections;
}

void printVector(vector<string> sections)
{
	for (int i = 0; i < sections.size(); i++)
		cout << sections[i] << endl;
}

int main()
{
	vector<ElfSection> small_sections;	
	vector<ElfSection> large_sections;

	small_sections = getSections("small_input_day4.txt");
	large_sections = getSections("large_input_day4.txt");
	
	//Part 1
	cout << "Part 1" << endl;
	findOverlapsPart1(small_sections);
	findOverlapsPart1(large_sections);

	//Part 2
	cout << "Part 2" << endl;
	findOverlapsPart2(small_sections);
	findOverlapsPart2(large_sections);
	return 0;
}

