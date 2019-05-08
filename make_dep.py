#python3

import sys
import os

#all src dirs
dirs = "."
temp_dir = "temp"
target = "goldcaptain"
cpp_flags = "$(shell sdl2-config --cflags)"
cpp_libs = "$(shell sdl2-config --libs) -lfreetype -lSDL2_mixer -lSDL2_image"

############################
#create tempdir
if not os.path.exists(temp_dir):
	os.make_dirs(temp_dir)
	
#########################################
#split line
cpp_files = []
for one_dir in dirs.split(' '):
	cpp_files = cpp_files + [cpp for cpp in os.listdir(arg_dir) if cpp.endswith('.cpp') or cpp.endswith('.c')]

objs = list(map(lambda cpp:temp_dir+"/"+cpp.replace(".cpp",".o").replace("/","."), cpp_files))

phony = """
.PHONY: clean all
all:$(TARGET)

""".replace("$(TARGET)", target)

flags = """

CPPFLAGS := $(cpp_flags)
CPPLIBS := $(cpp_libs)

""".replace("$(cpp_flags)", cpp_flags).replace("$(cpp_libs)", cpp_libs)

clean_cmd = """

clean:
	rm -f *.d; \
	rm -f *.o; \
	rm -f $(TARGET)

""".replace("$(TARGET)", target)

target_cmd = """
$(TARGET):$(OBJS)
	g++ -o $@ $< $(CPPLIBS)

""".replace("$(TARGET)", target).replace("$(OBJS)", objs.join(" "))

with open("Makefile", "a") as make_file:
	make_file.write(phony)
	make_file.write(flags)
	make_file.write(clean_cmd)
	
