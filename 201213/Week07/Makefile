# Oliver Kullmann, 11.11.2012 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++
JAVAC = gcj


Standard_options := -std=c++11 -pedantic
Warning_options := -Wall -Wno-main
Optimisation_options := -O3 -DNDEBUG


###

java_programs = BinarySearch
special_java_programs =
cpp_programs =

programs = $(java_programs) $(special_java_programs) $(cpp_programs)

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

$(java_programs) : % : %.java
	$(JAVAC) -o $@ $(JFLAGS) --main="$@" $<

