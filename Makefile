TEMP := temp
TARGET := goldcaptain
MAKE_DEP := $(TEMP)/make_dep.d
DIRS = .

CPPFLAGS := $(shell sdl2-config --cflags)
CPPLIBS := $(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image

define TEMP_O
TEMP_FILE = $(TEMP)/$(subst /,., $(1)).o
$(shell g++ -MM $(CPPFLAGS) $(1))
endef

#get all srcs
SRC := $(foreach DIR,$(DIRS),$(wildcard $(DIR)/*.cpp))
#remove ./
SRC := $(subst ./,,$(SRC))

#replace slash(/) to dot(.)
SRC_SLASH := $(subst /,., $(SRC))

#temporary files under temp dir
OBJECTS := $(TEMP)/$($(SRC_SLASH): %=%.o)


goldcaptain:$(OBJECTS)
	g++ -o $@ $(OBJECTS) $(CPPLIBS)


$(foreach CPP,$(SRC),$(eval $(call TEMP_o,$(CPP))))

#check if make target is default
#ifeq ($(MAKECMDGOALS),)
#include $(OBJECTS_DEPS)
#endif

.PHONY: clean

clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET)
