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

all: init bin/main clean

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
# Runs valgrind with 'build/func_ordem'
val:
	valgrind --leak-check=yes build/func_ordem

# ============== EXECUTABLES ==============
# For main:
bin/main: bin/main.o func_ordem.o
	g++ $^ -o $@

# ================ OBJECTS ================
# For main:
bin/main.o: src/main.cpp
	g++ $(CPPFLAGS) $< $(INC1) $(INC2) $(INC3) -c -o $@

# For func_ordem:
bin/func_ordem.o: src/func_ordem.cpp
	g++ $(CPPFLAGS) $< $(INC1) $(INC2) $(INC3) -c -o $@

# ================ CLEANER ================
# Removes objects
clean:
	$(RM) bin/*.o