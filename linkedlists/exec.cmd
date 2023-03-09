@REM gcc -c ./IntList.cpp -lstdc++
@REM gcc -c ./Node.cpp -lstdc++
g++ -c ./main.cpp
@REM gcc ./IntList.o ./Node.o ./main.o -lstdc++ -o ./app
g++ ./main.o -o ./app

app