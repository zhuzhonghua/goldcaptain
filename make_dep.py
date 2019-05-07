#python3

import sys
import os

#argv = dir list

cpp_files = []
for arg_dir in sys.argv[1:]:
	cpp_files = cpp_files + [cpp for cpp in os.listdir(arg_dir) if cpp.endswith('.cpp') or cpp.endswith('.c')]

cmd = """
	rm -f $@; \\n
	g++ -MM $(CPPFLAGS) $< > #@.$$$$; \\n
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \\n
	rm -f $@.$$$$\n
"""

with open("temp/make_dep.d", "a") as make_dep:
	for cpp in cpp_files:
		dep_file = "temp/"+cpp.replace("/",".")+".d"
		make_dep.write(dep_file+":"+cpp+"\n")
		make_dep.write(cmd+"\n\n")
	
