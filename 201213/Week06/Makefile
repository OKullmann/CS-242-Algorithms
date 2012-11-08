# Oliver Kullmann, 4.11.2012 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

CXX = g++
JAVAC = gcj


Standard_options := -std=c++11 -pedantic
Warning_options := -Wall -Wno-main
Optimisation_options := -O3 -DNDEBUG


###

java_programs = Stack Queue
special_java_programs = QueueViaStacks
cpp_programs = Stack2 Queue2

programs = $(java_programs) $(special_java_programs) $(cpp_programs)

all : $(programs)

cleanall :
	-rm $(programs)

# ########################

$(java_programs) : % : %.java
	$(JAVAC) -o $@ $(JFLAGS) --main="$@" $<

QueueViaStacks : QueueViaStacks.java Stack.java
	$(JAVAC) -o $@ $(JFLAGS) --main="$@" $^

Stack2 : Stack2.cpp Stack.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Queue2 : Queue2.cpp Queue.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<
