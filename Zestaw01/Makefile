STACK = Stack
GENERATOR = Generator
ONP = ONP

STACKEXEC = $(STACK).x
GENERATOREXEC  = $(GENERATOR).x
ONPEXEC = $(ONP).x

STACKOBJS  = $(STACK).o
GENERATOROBJS  = $(GENERATOR).o
ONPOBJS  = $(ONP).o

CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean

all: $(STACKEXEC) $(GENERATOREXEC) $(ONPEXEC)
$(STACKEXEC): $(STACKOBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(GENERATOREXEC): $(GENERATOROBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(ONPEXEC): $(ONPOBJS)
		$(LD) -o $@ $(LFLAGS) $^

clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 