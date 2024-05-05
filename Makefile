CXX = clang++
CXXFLAGS = -Wall -Wextra -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = play

# List of source files
SRCS = main.cpp $(wildcard backend/*.cpp)

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Main target
$(TARGET): $(OBJS) $(MEDIA)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(MEDIA) $(LDFLAGS)

# Rule to compile .cpp files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
