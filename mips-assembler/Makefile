
CPP      = g++ -D__DEBUG__
CC       = gcc -D__DEBUG__
OBJ      = assembler.o file_parser.o
LINKOBJ  = assembler.o file_parser.o
BIN      = mips-assembler
CXXFLAGS = $(CXXINCS) -g3 -std=c99
CFLAGS   = $(INCS) -g3 -std=c99
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after


$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

assembler.o: assembler.c
	$(CC) -c assembler.c -o assembler.o $(CFLAGS)

file_parser.o: file_parser.c
	$(CC) -c file_parser.c -o file_parser.o $(CFLAGS)

clean: clean-custom
	${RM} $(OBJ) $(BIN)
