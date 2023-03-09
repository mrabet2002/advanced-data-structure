gcc -c ./IntList.cpp -lstdc++
gcc -c ./Node.cpp -lstdc++
gcc -c ./main.cpp -lstdc++
gcc ./IntList.o ./Node.o ./main.o -lstdc++ -o ./app

app