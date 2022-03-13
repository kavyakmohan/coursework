//Kavya Mohan cs 202 section 1005
//assignment 1

#include <iostream>
#include <cmath> //pow function
	
using namespace std;

int main ()
{
	int digit[5]; //array to store digits in a 5-digit number

	for (int i = 10000; i < 99999; i++) //loops through values from 10000 to 99999
	{
		int OriginalNum = i; //store the number being checked
		int sum = 0; //initialize sum to 0

		//assign the digits to the array
		digit[0] = (i / 10000) % 10; //ten-thousands place
		digit[1] = (i / 1000) % 10;  //thousands place
		digit[2] = (i / 100) % 10;   //hundreds place
		digit[3] = (i / 10) % 10;    //tens place
		digit[4] = i % 10;           //ones place
		
		//loop through the array to determine the sum of the digits to the 5th power
		for (int j = 0; j < 5; j++)
		{
			sum = sum + pow(digit[j],5); //sum is updated
		}
	
		if (OriginalNum == sum) //if the original number equals the sum of its digits to the 5th power
		{
				cout << sum << " "; //the solution(s) is/are outputted
		}	
	}
	cout << endl;
	return 0;
}

