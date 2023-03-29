def getSections(filename):
	sections = []
	with open(filename, 'r') as file:
		sections = [x.strip() for x in file.readlines()]
		return sections

def splitSections(section):
	section_by_elf = section.split(",")
	split_sections = section_by_elf[0].split("-")
	split_sections += section_by_elf[1].split("-")
	return int(split_sections[0]), int(split_sections[1]), int(split_sections[2]), int(split_sections[3])

def findOverlapsPart1(sections):
	overlap1 = False
	overlap2 = False
	counter = 0
	for i in range(len(sections)):
		#e1b/e1b - Elf 1/2 begin
		#e1e/e2e - Elf 1/2 end
		e1b, e1e, e2b, e2e = splitSections(sections[i])
		if e1b >= e2b and e1e <= e2e:
			overlap1 = True
		if e2b >= e1b and e2e <= e1e:
			overlap2 = True
		if overlap1 or overlap2:
			counter+=1
		overlap1 = False
		overlap2 = False
	print("Overlaps: " + str(counter))
		
def findOverlapsPart2(sections):
	overlap1 = False
	overlap2 = False
	counter = 0
	for i in range(len(sections)):
		#e1b/e1b - Elf 1/2 begin
		#e1e/e2e - Elf 1/2 end
		e1b, e1e, e2b, e2e = splitSections(sections[i])
		if e2b <= e1b and e2e >= e1b:
			overlap1 = True
		if e1b <= e2b and e1e >= e2b:
			overlap2 = True
		if overlap1 or overlap2:
			counter+=1
		overlap1 = False
		overlap2 = False
	print("Overlaps: " + str(counter))

def main():
	small_sections = getSections("small_input_day4.txt")
	large_sections = getSections("large_input_day4.txt")
	#Part 1
	print("Part 1")
	findOverlapsPart1(small_sections)
	findOverlapsPart1(large_sections)
	#Part 2
	print("Part 2")
	findOverlapsPart2(small_sections)
	findOverlapsPart2(large_sections)

if __name__ == "__main__":
	main()
