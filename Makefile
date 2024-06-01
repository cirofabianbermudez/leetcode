# ====================================
#               Variables
# ====================================

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -g -std=c++23 -Wall

# Formater
CPP_FORMATER = clang-format

# Source code
#SRCS = $(wildcard *.cpp)
SRCS = 01_two_sum.cpp

# Generate object file list
OBJS = $(SRCS:.cpp=.o)

# Target name
TARGET = leetcode

# Formater
CLANG_FORMAT = $(shell command -v $(CPP_FORMATER))

# Number of data sets
NUM ?= 1000
# 1 PNG   2 PDF
TERMINAL ?= 1

# ====================================
#               Targets
# ====================================

.PHONY: run formater gnuplot clean view

# Rule to compile every .cpp to a .o
%.o: %.cpp
	@echo "> Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(TARGET) run 

$(TARGET): $(OBJS)
	@echo "> Linking object files"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) 

run:
	@echo "> Running $(TARGET)"
	./$(TARGET)


format: $(SRCS)
	@if command -v $(CPP_FORMATER) > /dev/null 2>&1 ; then \
		echo "> $(CPP_FORMATER) -i $^"; \
		$(CPP_FORMATER) -i $^ --style=Google; \
	else \
	  echo "$(CPP_FORMATER) is not installed. Formater skip."; \
	fi

clean:
	@echo "> Removing *.exe and *.o"
	rm -rf *.o *.exe *.txt *.png *.pdf $(TARGET)

help:
	@echo "> Help"

