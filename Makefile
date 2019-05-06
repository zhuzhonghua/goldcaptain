TEMP := temp
TARGET := goldcaptain

#SRC := $(wildcard glm/*.hpp)
SRC := $(wildcard *.cpp)

#replace slash(/) to dot(.)
SRC_SLASH := $(subst /,.,$(SRC))
#temporary files under temp dir
OBJECTS := $(patsubst %.cpp, $(TEMP)/%.cpp.o, $(SRC_SLASH))
#the real dep file
OBJECTS_DEPS := $(patsubst %.o, %.d, $(OBJECTS))

CPPFLAGS := $(shell sdl2-config --cflags)
CPPLIBS := $(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image

goldcaptain:$(OBJECTS)
	g++ -o $@ $(OBJECTS) $(CPPLIBS)


%.temp: %.cpp
	rm -f $@; \
	g++ -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#check if make target is default
ifeq ($(MAKECMDGOALS),)
$(warning $(shell python3 make_dep.py $(SRC)))
endif

#check if make target is default
#ifeq ($(MAKECMDGOALS),)
#include $(OBJECTS_DEPS)
#endif

.PHONY: clean

clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET)
