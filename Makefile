# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = game.out

# Source files
SRCS = Pion.cpp Animal.cpp Mouton.cpp Loup.cpp Herbe.cpp Main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Clean rule to remove generated files
clean:
	@rm *.o