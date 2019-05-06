OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

CPPFLAGS := $(shell sdl2-config --cflags)
CPPLIBS := $(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image

goldcaptain:$(OBJECTS)
	g++ -o $@ $(OBJECTS) $(CPPLIBS)

%.d: %.cpp
	rm -f $@; \
	g++ -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

include $(OBJECTS:.o=.d)

.PHONY: clean

clean:
	rm -f *.d; \
	rm -f *.o;
