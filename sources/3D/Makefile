CC          = g++# Compiler
ARCH		= ar# Archeive

CFLAGS		= -c -std=c++11# Compiler flags
LDFLAGS		= # Linker flags
AFLAGS		= rcs# Archive flags

SOURCES	    = Cam.cpp#
SOURCES	   += World.cpp#

INCLUDE	= -I ../../include/#
LIBRARIES	= -L ../../lib/#

OBJECTS		= $(SOURCES:.cpp=.o)#Object files

BINARYPATH	= ../../lib/#
BINARY		= lib3D.a# Library name

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS)
	$(ARCH) $(AFLAGS) $(BINARYPATH)$(BINARY) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:  ; rm *.o $(BINARYPATH)$(BINARY)
