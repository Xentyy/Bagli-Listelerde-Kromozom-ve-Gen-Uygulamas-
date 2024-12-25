program:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/DNA.cpp -o ./lib/DNA.o
	g++ -c -I "./include" ./src/Gen.cpp -o ./lib/Gen.o
	g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/DNA.o ./lib/Gen.o ./lib/Kromozom.o ./lib/main.o -o ./bin/main.exe
calistir:
	./bin/main.exe