# Arnold Beckmann, 19.01.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs = Recurrence.class Experiment.class

all : $(programs)

cleanall :
	- rm $(programs)

#########################

Recurrence.class : Recurrence.java
	javac $<

Experiment.class : Experiment.java Recurrence.class
	javac $<

gen1 : cp1 Recurrence.class

cp1 : solutions/Recurrence_1.java
	cp solutions/Recurrence_1.java Recurrence.java

gen2 : cp2 Recurrence.class

cp2 : solutions/Recurrence_2.java
	cp solutions/Recurrence_2.java Recurrence.java

