#python3

import sys
import os
import re

#all src dirs
dirs = [".", "zengine"]
temp_dir = "temp"
target = "goldcaptain"
cpp_flags = os.popen("sdl2-config --cflags").read().replace("\n","")+" -p -shared -g -g3 -fPIC -S -Wall -Wextra -Wpedantic -Izengine -Izengine/scheme/include -D__SDL__ -DSEXP_STATIC_LIBRARY"

cpp_libs = os.popen("sdl2-config --libs").read().replace("\n","")+" -lfreetype -lSDL2_mixer -lSDL2_image -lSDL2_ttf"

cc = "g++"
#scheme_src = """
#zengine/scheme/bignum.c
#zengine/scheme/eval.c
#zengine/scheme/gc.c
#zengine/scheme/opcodes.c
#zengine/scheme/sexp.c
#zengine/scheme/vm.c
#zengine/scheme/include/chibi/sexp-hufftabs.c
#"""
scheme_src = ""

############################
#create tempdir
if not os.path.exists(temp_dir):
	os.make_dirs(temp_dir)
	
#########################################
#split line
cpp_files = []
for one_dir in dirs:
	cpp_files = cpp_files + [one_dir+"/"+cpp for cpp in os.listdir(one_dir) if cpp.endswith('.cpp') or cpp.endswith('.c') or cpp.endswith('.cc')]

cpp_files = cpp_files + scheme_src.split()

get_temp_o = lambda cpp:temp_dir+"/"+cpp.replace("./","").replace(".cpp",".o").replace(".cc",".o").replace(".c",".o").replace("/",".")
	
objs = list(map(get_temp_o, cpp_files))


flags = """
CPPFLAGS := $(cpp_flags)
CPPLIBS := $(cpp_libs)
CC := $(cc)

OBJS := $(objs)

TARGET := $(target)

""".replace("$(cpp_flags)", cpp_flags).replace("$(cpp_libs)", cpp_libs).replace("$(cc)", cc).replace("$(objs)", " ".join(objs)).replace("$(target)", target)

phony = """
.PHONY: clean all
all:$(TARGET)

"""


def filter_head(t1):
	exp_lamb = lambda exp: exp.find("\\") == -1 and exp.find("SDL2") == -1 and exp.find("glm") == -1
	return " ".join(filter(exp_lamb, t1.split()))+"\n"
	
def get_gen_temp_o(cpp):
	cmd = "$(cc) -MM $(CPPFLAGS) ".replace("$(CPPFLAGS)", cpp_flags).replace("$(cc)", cc)+cpp
	return filter_head(os.popen(cmd).read())+"\t$(CC) $(CPPFLAGS) -o $@ $(cpp)\n".replace("$(cpp)", cpp)
	
def write_temp_o(make_file, cpp_files):
	for cpp in cpp_files:		
		temp_o = get_temp_o(cpp)		
		make_file.write(re.sub(r'^.*\.o\s*:', temp_o+":", get_gen_temp_o(cpp.replace("./",""))))
		make_file.write("\n")
		print(temp_o+":"+cpp)
	
target_cmd = """
$(TARGET):$(OBJS)
	$(CC)  $(CPPLIBS) -o $@ $^
"""

clean_cmd = """
clean:
	rm -f *.d; \
	rm -f temp/*.o; \
	rm -f $(TARGET)
""".replace("$(TARGET)", target)

with open("Makefile", "w") as make_file:
	print("start write makefile")
	make_file.write(flags)
	print(flags)
	
	make_file.write(phony)
	print(phony)
	
	write_temp_o(make_file, cpp_files)
	make_file.write(target_cmd)
	print(target_cmd)
	
	make_file.write(clean_cmd)
	print(clean_cmd)
	print("end write makefile")

#t1 = os.popen("g++ -MM $(CPPFLAGS) dungeonmap.cpp".replace("$(CPPFLAGS)", cpp_flags)).read()
#print(filter_head(t1))
