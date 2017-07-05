CXX = g++
CXXFLAGS += -std=c++11

TARGET = textclock

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

all: $(TARGET)
	@echo Build done.

clean:
	rm -f $(OBJECTS) $(TARGET)

