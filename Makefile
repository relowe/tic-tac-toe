# Environment
CXXFLAGS=`fltk-config --cxxflags` --std=c++11
LDFLAGS=`fltk-config --ldflags`
CXX=`fltk-config --cxx`

#The Apps
TARGETS=
all: $(TARGETS)

#The Ingredients

#FLUID ingredient builds
%.h %.cxx: %.fl
	fluid -c $^

# utility
clean:
	rm -f *.o $(TARGETS)
