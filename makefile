CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -L /src/lib
SRC = main.cpp menu.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC) -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)