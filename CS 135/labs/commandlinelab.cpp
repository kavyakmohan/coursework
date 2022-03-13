#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[]) {

if (argc != 3) {
cout << "Wrong number of arguments!" << endl;
return 1;
}

cout << "Hi " << argv[1] << ", " << "I see you will be " << atoi(argv[2])+10 << " in 10 years!" << endl;

return 0;
}
