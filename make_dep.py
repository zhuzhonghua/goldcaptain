#python3

import sys
import os

os.system("touch temp/dep.d")

for cpp in sys.argv[1:]:
	print("g++ -MM $(CPPFLAGS) "+cpp)
