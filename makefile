# ============================================================
# Makefile for Poker Project (Educational Version)
#
# Purpose of a Makefile:
# ----------------------
# - Automates the build process so you don’t have to type long
#   g++ commands every time you compile.
# - Keeps track of which files changed and only recompiles those.
# - Lets you organize your project into multiple source files
#   (main.cpp, poker.cpp, tests.cpp, etc.).
# - Provides shortcuts like "make run-tests" or "make clean".
#
# How to use:
# -----------
#   make          -> builds both poker (main program) and tests
#   make poker    -> builds just the main program
#   make run-main -> builds and runs the main program
#   make tests    -> builds the test program with Catch2
#   make run-tests-> builds and runs tests
#   make clean    -> removes compiled files so you can start fresh
# ============================================================

# Compiler and flags
CXX = g++
# -std=c++17   = use the C++17 standard
# -Wall        = enable common warnings
# -Wextra      = enable extra warnings
# -pedantic    = warn about non-standard C++ code
# (Optional) -Werror = treat all warnings as errors (forces you to fix them)
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# ------------------------------------------------------------
# "all" target: default when you just run "make"
# It will build both the main program (poker) and the tests.
# ------------------------------------------------------------
all: poker tests

# ------------------------------------------------------------
# Build the main program "poker"
# Links together:
#   - main.o  (entry point with main function)
#   - poker.o (function implementations from poker.cpp)
# ------------------------------------------------------------
poker: main.o poker.o
	$(CXX) $(CXXFLAGS) -o poker main.o poker.o

# ------------------------------------------------------------
# Build the test program "tests"
# Links together:
#   - tests.o (Catch2 test cases)
#   - poker.o (function implementations from poker.cpp)
# ------------------------------------------------------------
tests: tests.o poker.o
	$(CXX) $(CXXFLAGS) -o tests tests.o poker.o

# ------------------------------------------------------------
# Rule to build poker.o from poker.cpp
# This compiles the implementations of your functions.
# ------------------------------------------------------------
poker.o: poker.cpp poker.h
	$(CXX) $(CXXFLAGS) -c poker.cpp

# ------------------------------------------------------------
# Rule to build main.o from main.cpp
# Depends on poker.h so that header changes trigger recompilation.
# ------------------------------------------------------------
main.o: main.cpp poker.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# ------------------------------------------------------------
# Rule to build tests.o from tests.cpp
# Depends on:
#   - poker.h   (your prototypes)
#   - catch.hpp (the Catch2 header-only framework)
# ------------------------------------------------------------
tests.o: tests.cpp poker.h catch.hpp
	$(CXX) $(CXXFLAGS) -c tests.cpp

# ------------------------------------------------------------
# Convenience target: build and immediately run tests
# Ensures the test program is up-to-date, then executes it.
# ------------------------------------------------------------
run-tests: tests
	./tests

# ------------------------------------------------------------
# Convenience target: build and immediately run the main program
# Ensures poker is up-to-date, then executes ./poker.
# ------------------------------------------------------------
run-main: poker
	./poker

# ------------------------------------------------------------
# "clean" target: removes all generated files
# Lets you reset your project so the next "make" starts fresh.
# ------------------------------------------------------------
clean:
	rm -f *.o poker tests