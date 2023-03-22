BINARYTREE = FibHeap
BINARYTREEEXEC = $(BINARYTREE).x
BINARYTREEOBJS  = $(BINARYTREE).o


CXXFLAGS = -Wall -pedantic -O2
LDFLAGS = -Wall -pedantic -O2

CO = g++
LD = $(CO)

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cxx
	$(CO) $(CXXFLAGS) -c $<

.PHONY: all run clean

all: $(BINARYTREEEXEC)
$(BINARYTREEEXEC): $(BINARYTREEOBJS)
		$(LD) -o $@ $(LFLAGS) $^

run:
	./$(BINARYTREEEXEC)
clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 
