# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = ChangeMaking.class ExperimentDP.class

all : $(programs)

cleanall :
	rm *.class

#########################

ChangeMaking.class : ChangeMaking.java
	javac $<

ExperimentDP.class : Experiment.java ChangeMaking.class
	javac $<

