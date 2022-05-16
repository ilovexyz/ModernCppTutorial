C = gcc
CXX = g++

SOURCE_C = foo.c
OBJECTS_C = foo.o

SOURCE_CXX = 1.1.cpp

TARGET = 1.1.exe
CXX_FLAGS = -std=c++2a

all:
	$(C) -c $(SOURCE_C)
	$(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(CXX_FLAGS) -o $(TARGET)

clean:
	rm -rf *.o .\$(TARGET)
