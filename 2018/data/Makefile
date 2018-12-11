all: day03.input.part1 day03.input.part2

day03.input.part1:
	cat day03.input | awk '{print $$3 " " $$4}' | sed 's/[,:x]/ /g' > $@

day03.input.part2:
	cat day03.input | awk '{print $$1 " " $$3 " " $$4}' | sed 's/[,:x#]/ /g' > $@
