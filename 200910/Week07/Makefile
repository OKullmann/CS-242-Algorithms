# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = Huffman.class Experiment.class ExperimentA.class ExperimentB.class ExperimentC.class ExperimentD.class

all : $(programs)

cleanall :
	rm $(programs)

#########################

Array_Generators.class : Generators.java
	javac $<

Huffman.class : Huffman.java
	javac $<

Experiment.class : Experiment.java Huffman.class
	javac $<

Test.class : Test.java ArrayGenerators.class Insertion_Sort.class
	javac $<

gen : solutions/Experiment_1.java
	solutions/gensolution Experiment

