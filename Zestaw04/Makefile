ARRAYLIST = ArrayList
GENERATOR = Generator
CURSORLIST = CursorList

ARRAYLISTEXEC = $(ARRAYLIST).x
GENERATOREXEC  = $(GENERATOR).x
CURSORLISTEXEC = $(CURSORLIST).x

ARRAYLISTOBJS  = $(ARRAYLIST).o
GENERATOROBJS  = $(GENERATOR).o
CURSORLISTOBJS  = $(CURSORLIST).o

CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

CO = g++
LD = $(CO)

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all clean

all: $(ARRAYLISTEXEC) $(GENERATOREXEC) $(CURSORLISTEXEC)
$(ARRAYLISTEXEC): $(ARRAYLISTOBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(GENERATOREXEC): $(GENERATOROBJS)
		$(LD) -o $@ $(LFLAGS) $^

$(CURSORLISTEXEC): $(CURSORLISTOBJS)
		$(LD) -o $@ $(LFLAGS) $^

clean:
		rm -f *.o  *~ *.a *.so *.x *.out *.exe 