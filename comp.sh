#!/bin/bash

echo "CXX = g++" > Makefile

echo "EXE = allstars" >> Makefile

echo "LIBS = -lsfml-graphics -lsfml-window -lsfml-system" >> Makefile

echo "IDIR = include/" >> Makefile

echo -e "FLAGS = -std=c++11 -I\$(IDIR)" >> Makefile

echo -n "OBJS = " >> Makefile
for file in src/*
do
	filename=${file##*/}
	filename=${filename%.*}
	echo -n "obj/$filename.o " >> Makefile
done

echo -e "\n\nall: \$(EXE)\n" >> Makefile

echo -e "\$(EXE): \$(OBJS)" >> Makefile
echo -e "\t\$(CXX) \$(LIBS) $^ -o \$@\n" >> Makefile

for file in src/*
do
	filename=${file##*/}
	filename=${filename%.*}
	echo "obj/$filename.o: src/$filename.cpp" >> Makefile
	echo -e "\t\$(CXX) \$(FLAGS) -c -o \$@ \$<\n" >> Makefile
done

echo -e "main.o: src/main.cpp\n" >> Makefile

echo -e "clean:\n\trm obj/*.o *.gch include/*.gch" >> Makefile


clear
for arg in "$@"; do
	if [[ $arg == *"c"* ]]; then
		make clean 2> /dev/null
	fi

	if [[ $arg == *"m"* ]]; then
		make
	fi
done

