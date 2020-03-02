# Environment
CXXFLAGS=`fltk-config --cxxflags` --std=c++11 
LDFLAGS=`fltk-config --ldflags`
CXX=`fltk-config --cxx`

#The Apps
TARGETS=tic-tac-toe boardtest
all: $(TARGETS)
tic-tac-toe: tic-tac-toe.o main.o control.o board.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
boardtest: boardtest.cpp board.h board.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#The Ingredients
main.o: main.cpp tic-tac-toe.h
control.o: control.cpp control.h
baord.o: board.cpp board.h
tic-tac-toe.o: tic-tac-toe.cxx tic-tac-toe.h
	$(CXX) $(CXXFLAGS) -c -o $@ tic-tac-toe.cxx

#FLUID ingredient builds
%.h %.cxx: %.fl
	fluid -c $^

# utility
clean:
	rm -f *.o $(TARGETS) tic-tac-toe.cxx tic-tac-toe.h
