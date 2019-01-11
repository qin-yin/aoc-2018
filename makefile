CXX = g++
CXXFLAGS = -Wall -MMD -std=c++17 
BOOSTFLAGS = -lboost_program_options
EXEC = bin/aoc
OBJECTS = src/main.o src/day1/part1.o src/day1/part2.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} ${BOOSTFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS}
