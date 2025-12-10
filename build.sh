# gcc src/main.cpp -Wall -o test

EXE="byte-pack"

cmake .

make

./$EXE
