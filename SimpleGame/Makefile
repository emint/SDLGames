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
HEADERS = Controls/MovementControls.h Interactions/KeyboardController.h Display/Sprite.h
HEADERS += Exceptions/ResourceNotFoundException.h Display/SurfaceLoader.h Display/Window.h
HEADERS += Display/SurfaceUtils.h Exceptions/InvalidArgumentException.h Display/Rect.h
HEADERS += Character/CharacterModel.h Character/CharacterView.h Character/CharacterController.h
HEADERS += Utils/TimeProvider.h

SOURCES = Controls/MovementControls.cpp Interactions/KeyboardController.cpp Display/Sprite.cpp
SOURCES += Exceptions/ResourceNotFoundException.cpp Display/SurfaceLoader.cpp Display/Window.cpp
SOURCES += Display/SurfaceUtils.cpp Exceptions/InvalidArgumentException.cpp Display/Rect.cpp
SOURCES += Character/CharacterModel.cpp Character/CharacterView.cpp Character/CharacterController.cpp
SOURCES += Utils/TimeProvider.cpp

#Sources that can be run
MAIN_SOURCES = main.cpp

#For testing source files
TEST_SOURCES = unit-test/MovementControlTests.cpp 
TEST_SOURCES += unit-test/KeyboardControllerTest.cpp unit-test/SpriteTest.cpp
TEST_SOURCES += unit-test/WindowTest.cpp unit-test/CharacterControllerTest.cpp
TEST_SOURCES += unit-test/CharacterModelTest.cpp unit-test/CharacterViewTest.cpp

TEST_HEADERS = unit-test/Mock_MovementControl.h unit-test/Mock_SurfaceLoader.h 
TEST_HEADERS += unit-test/Mock_SurfaceUtils.h unit-test/Mock_TimeProvider.h
TEST_HEADERS += unit-test/Mock_CharacterModel.h unit-test/Mock_CharacterView.h
TEST_HEADERS += unit-test/Mock_CharacterController.h unit-test/Mock_Window.h
#Objects
OBJECTS = $(SOURCES:.cpp=.o)
#Objects that can be run
MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)
#Dependency file to write
DEPENDENCY_FILE = Makefile.dependencies

#Target names
TARGETS = driver unit_tests

all: dependencies $(TARGETS) 

driver: $(MAIN_OBJS) $(OBJECTS) $(HEADERS) 
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $(MAIN_OBJS) $(OBJECTS)

unit_tests: $(TEST_OBJS) $(OBJECTS) $(HEADERS) $(SOURCES) $(TEST_HEADERS) $(TEST_SOURCES) 
	$(CXX) $(CXXFLAGS)  $(LIBS) $(TESTLIBS) -o $@ $(OBJECTS) $(TEST_OBJS)

##Generate dependencies using -MM gcc flag
dependencies: $(SOURCES) $(HEADERS) $(TEST_SOURCES) $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) $(TEST_SOURCES) > $(DEPENDENCY_FILE)

-include Makefile.dependencies

clean:
	rm -f $(TARGETS) $(MAIN_OBJS) $(TEST_OBJS) $(OBJECTS) *~ Makefile.dependencies