# Oliver Kullmann, 22.12.2009 (Swansea)

SHELL = /bin/bash
.SUFFIXES :

.PHONY : all cleanall

###

programs =

all : $(programs)

cleanall :
	rm $(programs)

#########################

Experiment_down : Experiment_down.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Experiment_up : Experiment_up.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Experiment_rand : Experiment_rand.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

Test : Test.cpp Sorting.hpp Generators.hpp
	$(CXX) -o $@ $(Standard_options) $(Warning_options) $(Optimisation_options) $(include_option) $(CPPFLAGS) $(CXXFLAGS) $<

gen : solutions/Sorting_1.hpp
	solutions/gensolution Sorting

