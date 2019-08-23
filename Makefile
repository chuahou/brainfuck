CXX?=g++
CPPFLAGS?=-g
LDFLAGS?=-g

export CXX
export CPPFLAGS:=$(CPPFLAGS) -Wall -O3

SRCDIR:=src
HEADERDIR:=include
OBJDIR:=obj
OUTDIR:=bin

INCLUDES=$(HEADERDIR:%=-I%)

DIRS:=$(SRCDIR) $(OBJDIR) $(OUTDIR)

SRC:=$(wildcard $(SRCDIR)/*.cpp)
OBJ:=$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OUT:=$(OUTDIR)/brainfuck

.PHONY: build setup clean

build: setup $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

setup: $(DIRS)

$(DIRS):
	mkdir -p $@

clean:
	rm $(OUTDIR)/* $(OBJDIR)/* || true

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADDERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
