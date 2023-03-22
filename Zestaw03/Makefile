LIST = LinkedList
GENERATOR = Generator


LISTEXEC = $(LIST).x
GENERATOREXEC  = $(GENERATOR).x


LISTOBJS  = $(LIST).o
GENERATOROBJS  = $(GENERATOR).o


CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean

all: $(LISTEXEC) $(GENERATOREXEC)
$(LISTEXEC): $(LISTOBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(GENERATOREXEC): $(GENERATOROBJS)
		$(LD) -o $@ $(LFLAGS) $^

clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 