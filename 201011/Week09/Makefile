# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = FlowAdjacencyList.class Experiment.class

all : $(programs)

cleanall :
	rm $(programs)

#########################

FlowAdjacencyList.class : FlowNetworks.java
	javac $<

Experiment.class : Experiment.java FlowAdjacencyList.class
	javac $<

Test.class : Test.java ArrayGenerators.class Insertion_Sort.class
	javac $<

gen : solutions/Experiment_1.java
	solutions/gensolution Experiment

