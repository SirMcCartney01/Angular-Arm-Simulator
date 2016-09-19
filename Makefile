CC ?= gcc
CXX ?= g++

CC_FLAGS = -std=c99
CXX_FLAGS = -c -Wall -O2 -std=c++11

SOURCE = src
FILES = $(SOURCE)/Arm.cpp

OBJS = Arm.o
PROGRAM = arm

LIBS = -lglut \
       -lGLU \
       -lGL

RM = rm -f

.PHONY: all, run, clean

all:
	@echo "Compiling..."
	$(CXX) $(CXX_FLAGS) $(FILES)
	@echo "Linking..."
	$(CXX) $(OBJS) -o $(PROGRAM) $(LIBS)

run:
	@echo "Executing"
	./$(PROGRAM)

clean:
	@echo "Cleaning..."
	$(RM) $(OBJS)
	$(RM) $(PROGRAM)

