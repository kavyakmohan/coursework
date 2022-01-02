// Kavya Mohan Midterm Filestreams
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (){
double sum = 0;
int entrycount, entrynum;
string word;
string record0 = "record0.txt";
string record1 = "record1.txt";
string record2 = "record2.txt";
string output = "output.txt";
ifstream inf;
ofstream outf;
outf.open(output.c_str());

for (int i = 0; i < 3; i++){
	switch (i){
		case 0:
			inf.open(record0.c_str());break;
		case 1:
			inf.open(record1.c_str());break;
		case 2:
			inf.open(record2.c_str());break;
		}

	inf >> entrycount;

	for(int j=0; j < entrycount; j++){
		inf >> word;
		outf << word;
		inf >> entrynum;
		sum = sum + entrynum;
		}

	inf.close();
	}

cout << sum << endl;

outf.close();

return 0;
}
