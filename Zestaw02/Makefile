QUEUE = Queue
GENERATOR = Generator
RADIX = Radix

QUEUEEXEC = $(QUEUE).x
GENERATOREXEC  = $(GENERATOR).x
RADIXEXEC = $(RADIX).x

QUEUEOBJS  = $(QUEUE).o
GENERATOROBJS  = $(GENERATOR).o
RADIXOBJS  = $(RADIX).o

CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean

all: $(QUEUEEXEC) $(GENERATOREXEC) $(RADIXEXEC)
$(QUEUEEXEC): $(QUEUEOBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(GENERATOREXEC): $(GENERATOROBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(RADIXEXEC): $(RADIXOBJS)
		$(LD) -o $@ $(LFLAGS) $^

clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 