all: day03.input.clean

day03.input.clean:
	cat day03.input | awk '{print $$3 " " $$4}' | sed 's/[,:x]/ /g' > $@
