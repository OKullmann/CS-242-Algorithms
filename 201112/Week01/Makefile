# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = Insertion_Sort.class ArrayGenerators.class Experiment_up.class Experiment_down.class Experiment_rand.class

all : $(programs)

cleanall :
	rm $(programs)

#########################

ArrayGenerators.class : Generators.java
	javac $<

Insertion_Sort.class : Sorting.java
	javac $<

Experiment_up.class : Experiment.java ArrayGenerators.class Insertion_Sort.class
	javac $<

gen : solutions/Sorting_1.java
	solutions/gensolution Sorting

