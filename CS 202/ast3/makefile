bankBranch: main2.o bankBranch.o
	g++ main2.o bankBranch.o

main.o: main2.cpp
	g++ -c main2.cpp

bankBranch.o: bankBranch.cpp
	g++ -c bankBranch.cpp

clean:
	rm bankBranch.o
	rm main2.o
