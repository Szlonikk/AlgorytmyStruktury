BINARYTREE = BinaryTree
BINARYTREEEXEC = $(BINARYTREE).x
BINARYTREEOBJS  = $(BINARYTREE).o


CXXFLAGS = -Wall -pedantic -O3
LDFLAGS = -Wall -pedantic -O3

CO = g++
LD = $(CO)

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cxx
	$(CO) $(CXXFLAGS) -c $<

.PHONY: all clean

all: $(BINARYTREEEXEC)
$(BINARYTREEEXEC): $(BINARYTREEOBJS)
		$(LD) -o $@ $(LFLAGS) $^

clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 
