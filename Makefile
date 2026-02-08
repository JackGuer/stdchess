# Get library name
LIB = $(notdir $(CURDIR))
SO_FILE = lib$(LIB).so
EXE_FILE = chess_tester

# Directories
SRCDIR = src
LIBDIR = lib
BINDIR = bin
INCDIR = include

# Variables
CC = gcc
CFLAGS = -Wall -I./$(INCDIR) -g
SO_CFLAGS = -I$(INCDIR) -fPIC -shared
LDFLAGS = -L$(LIBDIR) -Wl,-rpath,. -l$(LIB)

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(SRCDIR)/%.o, $(SOURCES))

.PHONY: all clean exe so

default: $(LIBDIR)/$(SO_FILE) $(BINDIR)/$(EXE_FILE)
all: default

so: $(LIBDIR)/$(SO_FILE)

exe: so $(BINDIR)/$(EXE_FILE)

$(BINDIR)/$(EXE_FILE): $(SRCDIR)/main.o so
	$(CC) $(SRCDIR)/main.o -o $(BINDIR)/$(EXE_FILE) $(LDFLAGS)

$(LIBDIR)/$(SO_FILE): $(OBJECTS)
	$(CC) $(SO_CFLAGS) $^ -o $@

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SRCDIR)/*.o $(LIBDIR)/$(SO_FILE) $(BINDIR)/$(EXE_FILE)
