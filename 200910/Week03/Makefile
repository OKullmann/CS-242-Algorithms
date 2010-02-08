# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = Recurrence.class Experiment.class

all : $(programs)

cleanall :
	rm $(programs)

#########################

Recurrence.class : Recurrence.java
	javac $<

Experiment.class : Experiment.java Recurrence.class
	javac $<

gen : solutions/Recurrence_1.java
	solutions/gensolution Recurrence

