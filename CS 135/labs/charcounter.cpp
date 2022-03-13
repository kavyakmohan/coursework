#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char *argv[]){
string filename = argv[1];
string word;
int charcount;
int sum = 0;

ifstream inf;

inf.open(filename.c_str());

if (inf.is_open()) {
	inf >> word;
	while (! inf.eof()) {
		charcount = word.length();
		sum = sum + charcount;
		inf >> word;
	}
	
	inf.close();
}

cout << sum << endl;

return 0;
}
