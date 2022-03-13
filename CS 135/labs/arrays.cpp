#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[]) {

int max_size = atoi(argv[1]);
int max_value = atoi(argv[2]);
int a[1000000];
srand(135);

for (int i = 0; i < max_size; i++){
	a[i]=rand() % max_value +1;
}

int min = a[0];
int min_pos;
for (int j = 0; j < max_size; j++) {
	if (a[j] < min){
		min = a[j];
		min_pos = j;
	}
}

int max = a[0];
int max_pos;
for (int k = 0; k < max_size; k++) {
	if (a[k] > max){
		max = a[k];
		max_pos = k;
	}
}

cout << "Min is " << min << " at position " << min_pos << endl;
cout << "Max is " << max << " at position " << max_pos << endl;

return 0;
}
