IDIR=include
LDIR=libs
SRCDIR=src
ODIR=$(SRCDIR)/obj
CXX=g++
CXXFLAGS=-I$(IDIR) -Ipugixml/src -Ihapply -g
DEPS=$(IDIR)/*.hpp happly/happly.h pugixml/src/*.hpp
OBJ= $(ODIR)/main.o $(ODIR)/functions.o $(ODIR)/commands.o pugixml/pugixml.o
RM= rm -f

all : colorply

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(DEPS)
	$(CXX) -c $<  $(CXXFLAGS) -o $@

$(ODIR)/functions.o : $(SRCDIR)/functions.cpp $(DEPS)
	$(CXX) -c $<  $(CXXFLAGS) -o $@

$(ODIR)/commands.o : $(SRCDIR)/commands.cpp $(DEPS)
	$(CXX) -c $<  $(CXXFLAGS) -o $@

pugixml/pugixml.o : pugixml/src/pugixml.cpp $(DEPS)
	$(CXX) -c $<  $(CXXFLAGS) -o $@

colorply : $(OBJ)
	$(CXX) $(ODIR)/*.o $(DEPS) $(CXXFLAGS) -o $@

testt : test/test.cpp pugixml/pugixml.o
	$(CXX) $< pugixml/pugixml.o $(DEPS) $(CXXFLAGS) -o $@

PHONY: clean
clean:
	$(RM) $(OBJ)
	$(RM) colorply
	$(RM) testt
