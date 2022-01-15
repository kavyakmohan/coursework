#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
//input the number, n
int n, sum;
n = atoi(argv[1]);

//initalize sum to 0
sum = 0;

//while n is not 0
while (n != 0)
	{
	sum = (n % 10) + sum;
	n = n / 10;
	}

//output sum
cout << sum << endl;
return 0;
}
