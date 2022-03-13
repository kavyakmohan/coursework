#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

int main (int argc, char *argv[]){

if (argc != 2)
	{
	cout << "Error" << endl;
	exit (EXIT_FAILURE);
	}
else
	{
	int v, sqroot,randnum, sqrt2;
	v=atoi(argv[1]);
	sqroot=pow(v,2);
	srand (135);
	randnum=rand() % sqroot +1;
	cout << sqrt(randnum);
	}

return 0;
}
