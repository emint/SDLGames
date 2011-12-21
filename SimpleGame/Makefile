#Home directory
HOME = /home/emint


#Path to avoid the "../" in includes
SRC_PATH = .

#Compiler, flags, and system libraries
CXXFLAGS = -Wall -g -Werror -I$(HOME)/gtest-1.6.0/include -I$(HOME)/gmock-1.6.0/include -I$(SRC_PATH)
LIBS = -lSDL -lSDL_image

#Testing library, assuming gtest in homefolder
TESTLIBS = $(HOME)/gmock-1.6.0/make/gmock_main.a

#Sources and headers
HEADERS = Controls/MovementControls.h Interactions/KeyboardController.h
SOURCES = Controls/MovementControls.cpp Interactions/KeyboardController.cpp
#Sources that can be run
MAIN_SOURCES = main.cpp

#For testing source files
TEST_SOURCES = unit-test/MovementControlTests.cpp unit-test/Mock_MovementControl.h
TEST_SOURCES += unit-test/KeyboardControllerTest.cpp

#Objects
OBJECTS = $(SOURCES:.cpp=.o)
#Objects that can be run
MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)

#Dependency file to write
DEPENDENCY_FILE = Makefile.dependencies

#Target names
TARGETS = driver unit_tests

all: $(TARGETS) dependencies

driver: $(MAIN_OBJS) $(OBJECTS) $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $(MAIN_OBJS) $(OBJECTS)

unit_tests: $(TEST_OBJS) $(OBJECTS) $(TEST_SOURCES) 
	$(CXX) $(CXXFLAGS)  $(LIBS) $(TESTLIBS) -o $@ $(OBJECTS) $(TEST_OBJS)

##Generate dependencies using -MM gcc flag
dependencies: $(SOURCES) $(HEADERS) $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) $(TEST_SOURCES) > $(DEPENDENCY_FILE)

-include Makefile.dependencies

clean:
	rm -f $(TARGETS) $(MAIN_OBJS) $(TEST_OBJS) $(OBJECTS) *~ Makefile.dependencies