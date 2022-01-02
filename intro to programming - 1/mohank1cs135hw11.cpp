/* Kavya Mohan 2001362917 CS135 SECTION 1020
 * Description: create a database using structs
 * Input: input.txt containing records
 * Output: print database and statistics to terminal*/

#include <iostream>
#include <string>
#include <iomanip>

//DEFINES
#define MAXSIZE    50 //max number of records in the file
#define LINELENGTH 80 //how wide lines are in the terminal

using namespace std;

//STRUCT DECLARATION
struct starfighter{
	string nickname;
	string manufacturer;
	string model;
	double cost;
	double length;
	long maxspeed;
	short mglt;
	int hyperdriveClass;
};

//Function Prototypes
void readData(starfighter ship[], int& listsize);
void printStarfighter(starfighter ship[], int& listsize);
void printlines(int);
void printTotalCost(starfighter ship[], int& listsize);
void printFastestMGLT(starfighter ship[], int& listsize);
void printFastestAtmospheric(starfighter ship[], int& listsize);
void printShipsWithNoHyperDrive(starfighter ship[], int& listsize);
void printShipsWithSameManufacturer(starfighter ship[], int& listsize);
void printManufacturerShips(starfighter ship[], int& listsize, string manufacturer);
void printBye();

//MAIN
int main(){
	starfighter ship[MAXSIZE]; //struct array declaration, ship is member access operator
	int listsize; //# of records in input.txt
	cout << "Starfighter Datasheet:" << endl;
	readData(ship, listsize);
	printStarfighter(ship, listsize);
	printTotalCost(ship, listsize);
	printFastestMGLT(ship, listsize);
	printFastestAtmospheric(ship, listsize);
	printShipsWithNoHyperDrive(ship, listsize);
	printShipsWithSameManufacturer(ship, listsize);
	printBye();
	return 0;
}

void readData(starfighter ship[], int& listsize){
//store data from input file into array of structs
//expects ship[] and reads in num of records
//passes on list size to other functions
	int recordnum = 0; //represents the record that is being read
	cin >> listsize;
	cin.ignore();
	while(recordnum < listsize){ //exit loop when recordnum greater than listsize
		getline(cin, ship[recordnum].nickname);
		getline(cin, ship[recordnum].manufacturer);
		getline(cin, ship[recordnum].model);
		cin >> ship[recordnum].cost;
		cin.ignore();
		cin >> ship[recordnum].length;
		cin.ignore();
		cin >> ship[recordnum].maxspeed;
		cin.ignore();
		cin >> ship[recordnum].mglt;
		cin.ignore();
		cin >> ship[recordnum].hyperdriveClass;
		cin.ignore();
		recordnum++; //increment recordnum
	}
}

void printStarfighter(starfighter ship[], int& listsize){
//print data for each of the fighters and printlines()
//expects ship[] and listsize
	for (int i=0; i < listsize; i++){
		printlines(LINELENGTH); //print line before every entry
		cout << ship[i].nickname << endl;
		cout << "Manufacturer: " << ship[i].manufacturer << endl;
		cout << "Model: " << ship[i].model << endl;
		cout << fixed << setprecision(2);
		cout << "Price: " << ship[i].cost << " credits" << endl;
		cout << "Length: " << ship[i].length << " meters" << endl;
		cout << "Megalight per hour: " << ship[i].mglt << " MGLT" << endl;
		cout << "Max Atmospheric Speed: " << ship[i].maxspeed << " km/h" << endl;
		if (ship[i].hyperdriveClass == 0){
			cout << "Hyperdrive Class: None" << endl;
		}
		else
			cout << "Hyperdrive Class: " << ship[i].hyperdriveClass << endl; //if 0, print none
	}
	printlines(LINELENGTH); //print line after last entry
	cout << endl;
}

void printlines(int num_dashes){
//print out a line of dashes
//expects number of times to print a dash
	cout << setfill('-') << setw(num_dashes) << "-" << endl;
}

void printTotalCost(starfighter ship[], int& listsize){
//calculate the total sum and prints
//expects ship[] and listsize
	int total=0;
	for (int i = 0; i < listsize; i++){
		total = total + ship[i].cost; //adds the cost of each ship to the sum
	}
	cout << "Total cost to purchase all ships: " << total << " credits" << endl;
	cout << endl;
}

void printFastestMGLT(starfighter ship[], int& listsize){
//find and print fastest ship in megalights and its speed
//expects ship[] and listsize
	string fastestnickname = ship[0].nickname;
	short fastestmglt = ship[0].mglt;
	
	for (int i = 0; i < listsize; i++){ //loop checks for the fastest ship and assigns to the new variables
		if (ship[i].mglt > fastestmglt){
			fastestnickname=ship[i].nickname;
			fastestmglt = ship[i].mglt;
		}
	}
	cout << "Fastest Ship in the Galaxy  (MGLT): " << fastestnickname << " (" << fastestmglt <<") !" << endl;
	cout << endl;
}

void printFastestAtmospheric(starfighter ship[], int& listsize){
//find and print fastest ship in atmospheric speed and its stats
//expects ship[] and listsize
	string fastestnickname = ship[0].nickname;
	long fastestmaxspeed = ship[0].maxspeed;

	for (int i = 0; i < listsize; i++){ //loop checks for the fastest ship and assigns to the new variables
		if (ship[i].maxspeed > fastestmaxspeed){
			fastestnickname = ship[i].nickname;
			fastestmaxspeed = ship[i].maxspeed;
		}
	}
	cout << "Fastest Ship in the Galaxy  (Atmospheric): " << fastestnickname << " (" << fastestmaxspeed <<" km/h) !"<< endl;
	cout << endl;
}

void printShipsWithNoHyperDrive(starfighter ship[], int& listsize){
//print ships with hyperdrive class 0
//expects ship[] and listsize
	string shiplist;
	for (int i = 0; i < listsize; i++){
		if (ship[i].hyperdriveClass == 0){
			shiplist = shiplist + ship[i].nickname;
		}
	}
	cout << "Ships with no Hyperdrive: " << shiplist <<  endl;
	cout << endl;
}

void printShipsWithSameManufacturer(starfighter ship[], int& listsize){
//print out manufacturers that make more than one ship
//call printManufacturerShips() and expects ship[] and listsize
	cout << "Manufacturers that make more than one ship: " << endl;
	int shipCount = 0;
	for (int i = 0; i < listsize; i++){
		shipCount = 1;
		for (int j=0; j < listsize; j++){
			if (ship[j].manufacturer == ship[i].manufacturer){
				if ( j > i )
					shipCount++;
				if ( j < i )
					break;
			}
		}
		if (shipCount > 1)
			printManufacturerShips(ship, listsize, ship[i].manufacturer);
	}
	cout << endl;
}

void printManufacturerShips(starfighter ship[], int& listsize, string manufacturer){
//print list of ships with same manufacturer
//expects ship[], listsize, and manufacturer
//passes list to printShipsWithSameManufacturer
	bool firstShip = true;
	cout << manufacturer << ": ( ";

	for (int i=0; i < listsize; i++){
		if (ship[i].manufacturer == manufacturer){
			if (firstShip)
				firstShip = false;
			else
				cout << ", ";

			cout << ship[i].nickname;
		}
	}
	cout << " )";
	cout << endl;
}

void printBye(){
//prints goodbye message
	cout << "May The Force Be With You, Always." << endl;
}

