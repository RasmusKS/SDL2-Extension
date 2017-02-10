CC          = g++# Compiler
ARCH		= ar# Archeive

CFLAGS		= -c -std=c++11# Compiler flags
LDFLAGS		= -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_mixer# Linker flags
AFLAGS		= rcs# Archive flags

SOURCES	    = Rect.cpp#
SOURCES	   += Circle.cpp#

INCLUDE	= -I ../../include/#
LIBRARIES	= -L ../../lib/#

OBJECTS		= $(SOURCES:.cpp=.o)#Object files

BINARYPATH	= ../../lib/#
BINARY		= libshapes.a# Library name

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS)
	$(ARCH) $(AFLAGS) $(BINARYPATH)$(BINARY) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:  ; rm *.o $(BINARYPATH)$(BINARY)
