# C++ compiler, compiler flags, and include statement
CXX      := g++-10
CXXFLAGS := -Wall -Wpedantic -Wextra -std=c++17
CXXINCLD := -I $(HOME)/projects/stl-type-traits/include
TESTOBJS := test_main.o test_helper_class.o test_primary_type_categories.o test_type_relationships.o test_const_volatile_specifiers.o test_other_transformations.o

all: test.exe

test.exe: $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -o test.exe $(TESTOBJS)

test_main.o: test_main.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_main.cxx

test_helper_class.o: test_helper_class.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_helper_class.cxx

test_primary_type_categories.o: test_primary_type_categories.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_primary_type_categories.cxx

test_type_relationships.o: test_type_relationships.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_type_relationships.cxx

test_const_volatile_specifiers.o: test_const_volatile_specifiers.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_const_volatile_specifiers.cxx

test_other_transformations.o: test_other_transformations.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) -c test_other_transformations.cxx

run: test.exe
	./test.exe

clean:
	rm *.exe *.o
	clear