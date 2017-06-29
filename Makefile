##by @bnatalha.

# - - - - - - - - - - - - - - - - - - - -
# - - ---------- VARIABLES ---------- - -
# - - - - - - - - - - - - - - - - - - - -

# Directories
INC_DIR =include
SRC_DIR =src
OBJ_DIR =build
LIB_DIR =lib
EXP_LIB =-l stdexcept

# Compilation flags
#CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g -I $(INC_DIR) -I. -I include/lista -l <stdexcept>
CPPFLAGS += -Wall -ansi -std=c++11 -pedantic -O0 -g -I $(INC_DIR) -I.

# Compilators
CC =g++

# - - - - - - - - - - - - - - - - - - - -
# - - ----------- TARGETS ----------- - -
# - - - - - - - - - - - - - - - - - - - -

# =============== PHONY =================
.PHONY: all init val clean docs
#.PHONY: linux init val clean docs

all: init build/main clean

# Creates the 'build' and the 'lib' folder at the current directory if there's no other folder with this name on it.
init:
	mkdir -p build ;\
	mkdir -p data

# ============ DOCUMENTATION ==============
# Creates the 'docs' folder at the current directory if there's no other folder with this name on it.
# Generates .html documentation via doxygen at the folder 'docs'
docs: Doxyfile
	mkdir -p docs ;\
	doxygen	

# ============== VALGRIND =================
# Runs valgrind with 'build/main'
val:
	valgrind --leak-check=yes build/main

# ============== EXECUTABLES ==============
# For main:
build/main: build/main.o build/myTAD_stats.o
	g++ $^ -o $@

# For main:
#build/main: build/main.o
#	g++ $^ -o $@

# ================ OBJECTS ================
# For main:
build/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< -c -o $@

# For myTAD_stats:
build/myTAD_stats.o: src/myTAD_stats.cpp
	g++ $(CPPFLAGS) $< -c -o $@

# ================ CLEANER ================
# Removes objects
clean:
	$(RM) build/*.o