IDIR=include
LDIR=libs
SRCDIR=src
ODIR=$(SRCDIR)/obj
CXX=g++
CXXFLAGS=-I$(IDIR) -g
DEPS=$(IDIR)/*.hpp happly/happly.h


all : colorply

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(DEPS)
	$(CXX) -c  $< $(CXXFLAGS) -o $@
	
$(ODIR)/commands.o : $(SRCDIR)/commands.cpp $(DEPS)
	$(CXX) -c  $< $(CXXFLAGS) -o $@

$(ODIR)/functions.o : $(SRCDIR)/functions.cpp $(DEPS)
	$(CXX) -c  $< $(CXXFLAGS) -o $@

colorply : $(ODIR)/main.o $(ODIR)/commands.o $(ODIR)/functions.o
	$(CXX)  $(ODIR)/*.o $(DEPS) $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm $(ODIR)/*.o
	rm colorply
