INCLUDES=-Iinclude
CCFLAGS=-g -Wall -O3
CCC=g++
LDFLAGS=-g

SRCDIR:=src
OBJDIR:=obj
OUTDIR:=bin

DIRS:=$(SRCDIR) $(OBJDIR) $(OUTDIR)

SRC:=$(wildcard $(SRCDIR)/*.cpp)
OBJ:=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OUT:=$(OUTDIR)/brainfuck

$(OUT): $(OBJ)
	$(CCC) $(LDFLAGS) -o $@ $^

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CCC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

setup: $(DIRS)

$(DIRS):
	mkdir -p $@

clean:
	rm $(OUTDIR)/* $(OBJDIR)/*
