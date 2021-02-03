# Project: ICP
# File: Makefile
# Description: This file uses qmake to generate a Makefile.
# Authors: Daniel Kamenický (xkamen21)
#          Marek Fiala (xfiala60)
compile:
	cd src && qmake -makefile ijc.pro && make

doxygen: src/Doxyfile
	doxygen src/Doxyfile

clean:
	cd src && rm *.o Makefile ijc moc_*.cpp moc_predefs.h ui_mainwindow.h

run: compile
	cd src && ./ijc

pack:
	zip -r xkamen21-xfiala60.zip doc src examples Makefile readme.txt
