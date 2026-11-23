CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
TARGET = manager.exe
SRCS = $(wildcard src/*.cpp)

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: all
	$(TARGET)

clean:
	-del /Q $(TARGET)

.PHONY: all run clean