#Compiler, flags, and system libraries
CC = g++
CCFlags = -Wall -g -Werror
LIBS = -lSDL -lSDL_image

#Sources and headers
HEADERS = Controls/MovementControls.h
SOURCES = Controls/MovementControls.cpp

#Sources that can be run
MAIN_SOURCES = main.cpp

#For testing source files
TEST_SOURCES = 

#Objects
OBJECTS = $(SOURCES:.cpp=.o)
#Objects that can be run
MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)

#Dependency file to write
DEPENDENCY_FILE = Makefile.dependencies

#Target names
TARGETS = driver
all: driver dependencies

driver: $(MAIN_OBJS) $(OBJECTS)
	$(CXX) $(CCFlags) $(LIBS) -o $@ $(MAIN_OBJS) $(OBJECTS)
	
##Generate dependencies using -MM gcc flag
dependencies: $(SOURCES) $(HEADERS) $(TEST_SOURCES)
	$(CXX) $(CCFLAGS) -MM $(SOURCES) $(TEST_SOURCES) > $(DEPENDENCY_FILE)

-include Makefile.dependencies

clean:
	rm -f $(TARGETS) $(MAIN_OBJS) $(TEST_OBJS) $(OBJECTS) *~ Makefile.dependencies