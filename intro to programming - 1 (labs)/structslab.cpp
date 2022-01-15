//Kavya Mohan

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//struct declaration
struct workerdata{
	string name;
	string jobtitle;
	float salary;
	string responsibility;
};

const int MAXSIZE = 20;
int main(int argc, char* argv[]){
int workernum = 0;
workerdata worker[MAXSIZE];
ifstream inf;
ofstream outf;
string file = argv[1];
inf.open(file.c_str());

if (inf.is_open()){
	while(! inf.eof()){
		getline(inf, worker[workernum].name);
		getline(inf, worker[workernum].jobtitle);
		inf >> worker[workernum].salary;
		inf.ignore();
		getline(inf, worker[workernum].responsibility);
		workernum++;
	}
	inf.close();
}

for (int i = 0; i < workernum - 1; i++){
	cout << "Name: " << worker[i].name << endl;
	cout << "Job Title: " << worker[i].jobtitle << endl;
	cout << "Salary: $" << fixed << setprecision(2) << worker[i].salary << endl;
	cout << "Responsibility: " << worker[i].responsibility << endl;
	cout << endl;
}	

return 0;
}

