# Oliver Kullmann, 28.4.2010 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

executable = minisat_static
target = minisat2
directory = Minisat/simp
compile_command = make rs

###

all : 
	cd ${directory}; ${compile_command}; mv ${executable} ../../${target}

cleanall :
	-rm ${target} Minisat/core/Solver.or Minisat/simp/Main.or Minisat/simp/SimpSolver.or Minisat/simp/depend.mk

