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

phony = """
.PHONY: clean all
all:$(TARGET)
""".replace("$(TARGET)", target)

flags = """
CPPFLAGS := $(cpp_flags)
CPPLIBS := $(cpp_libs)
CC := $(cc)


""".replace("$(cpp_flags)", cpp_flags).replace("$(cpp_libs)", cpp_libs).replace("$(cc)", cc)

def filter_head(dep_str):
	t1 = re.sub(r'\S*\/SDL2\/\S*', "", dep_str)
	t2 = re.sub(r'\S*\/glm\/\S*', "", t1)
	t3 = re.sub(r'\\\s*', "", t2)
	
	return t3
	
def get_gen_temp_o(cpp):
	cmd = "$(cc) -MM $(CPPFLAGS) ".replace("$(cc)", cc)+cpp
	return filter_head(os.popen(cmd.replace("$(CPPFLAGS)", cpp_flags)).read())+"\t$(cc) -c $< -o $@ $(CPPFLAGS)\n".replace("$(CPPFLAGS)", cpp_flags).replace("$(cc)", cc)
	
def write_temp_o(make_file, cpp_files):
	for cpp in cpp_files:		
		temp_o = get_temp_o(cpp)		
		make_file.write(re.sub(r'^.*\.o\s*:', temp_o+":", get_gen_temp_o(cpp)))
		make_file.write("\n")
		print(temp_o+":"+cpp)
	
target_cmd = """
$(TARGET):$(OBJS)
	$(cc) $(OBJS) -o $@ $(CPPLIBS)
""".replace("$(TARGET)", target).replace("$(OBJS)", " ".join(objs)).replace("$(cc)", cc)

clean_cmd = """
clean:
	rm -f *.d; \
	rm -f temp/*.o; \
	rm -f $(TARGET)
""".replace("$(TARGET)", target)

##with open("Makefile", "w") as make_file:
##	print("start write makefile")
##	make_file.write(phony)
##	print(phony)
##	make_file.write(flags)
##	print(flags)
##	write_temp_o(make_file, cpp_files)
##	make_file.write(target_cmd)
##	print(target_cmd)
##	make_file.write(clean_cmd)
##	print(clean_cmd)
##	print("end write makefile")

#print(get_gen_temp_o("dungeonmap.cpp"))
t1 = os.popen("g++ -MM $(CPPFLAGS) zengine/timing.cpp".replace("$(CPPFLAGS)", cpp_flags)).read()
#print(re.sub(r'\s.*\/SDL2\/.*\s', "", "bbc /usr/include/SDL2/SDL.h def"))
t2 = re.sub(r'\S*\/SDL2\/\S*', "", t1)
t3 = re.sub(r'\S*\/glm\/\S*', "", t2)
t4 = re.sub(r'\\\s*', "", t3)
print(t3)
