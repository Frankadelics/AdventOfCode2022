class Rucksack:
	def __init__(self, full_comp, first_comp, second_comp, priority):
		self.full_comp = full_comp
		self.first_comp = first_comp
		self.second_comp = second_comp
		self.priority = priority

def getList(file_path):
	set_of_item = set()
	list_of_set = []
	full_comp = ""
	first_comp = ""
	second_comp = ""
	with open(file_path, 'r') as file:
		rucksack_list = [x.strip() for x in file.readlines()]
	return rucksack_list

def getPriority(rucksack_list):
	comp1 = ""
	comp2 = ""
	comp1_set = set()
	comp2_set = set()
	priority_list = []
	for i in range(len(rucksack_list)):
		comp1, comp2 = splitCompartments(rucksack_list[i])
		comp1_set = createCharSet(comp1)
		comp2_set = createCharSet(comp2)

		intersection = list(comp1_set.intersection(comp2_set))
		priority_list += intersection
	return priority_list

def getBadge(rucksack_list):
	priority_list = []
	for i in range(0, len(rucksack_list),3):
		if i > len(rucksack_list):
			break
		else:
			rucksack1 = createCharSet(rucksack_list[i])
			rucksack2 = createCharSet(rucksack_list[i + 1])
			rucksack3 = createCharSet(rucksack_list[i + 2])

			intersection = list(rucksack1.intersection(rucksack2, rucksack3))
			priority_list += intersection
	return priority_list


def splitCompartments(full_compartment):
	comp1 = ""
	comp2 = ""
	length = len(full_compartment)
	half_length = length / 2
	comp1 = full_compartment[0:int(half_length)]
	comp2 = full_compartment[int(half_length):length]
	return comp1, comp2

def createCharSet(compartment_string):
	compartment_set = set()
	for letter in compartment_string:
		compartment_set.add(letter)
	return compartment_set

def calculatePriority(priority_list):
	total_priority = 0
	for i in range(len(priority_list)):
		letter = ord(priority_list[i])
		if letter >= 97 and letter <= 122:
			total_priority += letter - 96
		else:
			total_priority += letter - 38
	print("Total Priority: " + str(total_priority))

def main():
	#Part 1
	small_list = getList("small_input_day3.txt")
	large_list = getList("large_input_day3.txt")

	small_priority = getPriority(small_list)
	large_priority = getPriority(large_list)

	print("Part 1")
	calculatePriority(small_priority)
	calculatePriority(large_priority)

	print()
	
	#Part 2
	small_badge = getBadge(small_list)
	large_badge = getBadge(large_list)

	print("Part 2")
	calculatePriority(small_badge)
	calculatePriority(large_badge)	
	#print(small_list_set)
	#print(large_list_set)

if __name__ == "__main__":
	main()
