CC	  = g++#Compiler

CFLAGS      = -c -std=c++11#Compiler Flags

LDFLAGS	    = -l2D -lSDL2 -lSDL2_gfx #Linker options

SOURCES     = main.cpp#

OBJECTS     = $(SOURCES:.cpp=.o)#Object files

EXECUTEABLE = a.out #Output name

INCLUDES    = -I ~/library/include/#

LIBRARY     = -L ~/library/lib/#

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBRARY) $(LDFLAGS)# -o $(EXECUTEABLE)

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
 
