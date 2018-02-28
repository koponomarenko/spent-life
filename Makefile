CXX = g++
CXXFLAGS = -Wall -std=c++11

objects = main.o

prog_name = spent-life.out

all: $(prog_name)

$(prog_name): $(objects)
	$(CXX) -o $(prog_name) $(LDFLAGS) $(objects) $(LDLIBS)

# TODO: in the future headers/includes must be taken care of automatically.

.PHONY:
clean:
	-rm -rf $(objects) $(prog_name)
