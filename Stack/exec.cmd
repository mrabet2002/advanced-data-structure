g++ -c ./stack.cpp
g++ -c ./main.cpp
g++ ./stack.o ./main.o -o ./app
@REM gcc ./main.o -lstdc++ -o ./app

app