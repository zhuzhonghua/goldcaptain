.PHONY: clean all init

TEMP := temp
TARGET := goldcaptain
DIRS = .

all: $(TARGET)

CPPFLAGS := $(shell sdl2-config --cflags)
CPPLIBS := $(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image

#get all srcs and remove ./
SRC := $(subst ./,,$(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.cpp)))

#temp/util.cpp.o:util.cpp
#	g++ -c $(CPPFLAGS) $< -o $@

#replace slash(/) to dot(.)
SRC_SLASH := $(subst /,., $(SRC))

#temporary files under temp dir
OBJECTS := $(patsubst %.cpp,%.o,$(foreach ONE,$(SRC_SLASH),$(TEMP)/$(ONE)))

$(TARGET):$(OBJECTS)
	g++ -o $@ $(OBJECTS) $(CPPLIBS)

#check if make target is default
ifeq ($(MAKECMDGOALS),)
include temp/temp.d
endif

define TEMP_O
$(eval CPP_O = $(patsubst %.cpp,%.o,$(TEMP)/$(subst /,.,$(1))))
$(shell g++ -MM $(CPPFLAGS) $(1) | sed -e "s|^.*\.o[ :]*|$(CPP_O):|g" >> temp/temp.d)
$(shell echo "\n" >> temp/temp.d)
endef

init:
	rm -f temp/temp.d; \
$(foreach CPP,$(SRC),$(call TEMP_O,$(CPP)))

clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET)
