TEMP := temp
TARGET := goldcaptain

#SRC := $(wildcard glm/*.hpp)
SRC := $(wildcard *.cpp)

SRC_SLASH := $(subst /,.,$(SRC))
OBJECTS := $(patsubst %.cpp, $(TEMP)/%.cpp.o, $(SRC_SLASH))

CPPFLAGS := $(shell sdl2-config --cflags)
CPPLIBS := $(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image

#goldcaptain:$(OBJECTS)
#	g++ -o $@ $(OBJECTS) $(CPPLIBS)

$(TARGET):
	@echo "goldcaptainbbb"

%.d: %.cpp
	rm -f $@; \
	g++ -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

#check if make target is default
ifeq ($(MAKECMDGOALS),)
#$(warning kdkdksk)
include $(OBJECTS:.o=.d)
endif

.PHONY: clean

clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET)
