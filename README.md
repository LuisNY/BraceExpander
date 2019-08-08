# BraceExpander

Personal implementation of brace expander.

The program can be compiled from terminal with the following commands:

- g++ -o BraceExpansion /path/to/folder/main/main.cpp /path/to/folder/expander/src/Expander.cpp -std=c++17

- echo "{A,B}" | /path/to/folder/BraceExpantion

Alternatively from the project folder with CMake (version 3.11 required):

- mkdir build

- cd build

- cmake ../

- make

- make check (to run the tests)

- echo "{A,B}"	| ../bin/brace_expander

