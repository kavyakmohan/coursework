#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "organism.h"
using namespace std;

int main()
{
  const int numFish = 200;
  const int numPlants = 2000;

  //create two arrays
  herbivore fish[numFish];
  plant plants[numPlants];

  //other variables
  double initPlantSize, initPlantRate;
  double initFishSize, initFishRate;
  int weeks;

  //read in number of weeks to simulate
  cout << endl;
  cout << "How many weeks would you like to simulate? ";
  cin >> weeks;

  //read in size and rate for each plant
  cout << "Enter initial plant size and rate: ";
  cin >> initPlantSize >> initPlantRate;

  //read in size and rate for each fish
  cout << "Enter initial fish size and rate: ";
  cin >> initFishSize >> initFishRate;

  //create temp object of type herbivore
  herbivore tempHerbivore(initFishSize, initFishRate, initFishSize * 0.1);

  //create temp object of type plant
  plant tempPlant(initPlantSize, initPlantRate);

  //assign elements from tempHerbivore to fish[]
  for (int i = 0; i < numFish; i++)
  {
    fish[i] = tempHerbivore;
  }

  //assign elements from tempPlant to plants[]
  for (int i = 0; i < numPlants; i++)
  {
    plants[i] = tempPlant;
  }

  //WEEKLY LOOP
  for (int i = 1; i < weeks + 1; i++)
  {
    double plantMass = 0;
    double fishPopulation = 0;

    //LOOPS RUNS AMOUNT OF PLANTS
    //randomly pick a fish and a plant
    //fish will call its nibble function and pass in chosen plant
    for (int a = 0; a < numPlants; a++)
    {
      int randFish, randPlant;
      randFish = rand() % numFish;
      randPlant = rand() % numPlants;
      fish[randFish].nibble(plants[randPlant]);
    }
 
    //calls each plant's simulateWeek()
    for (int b = 0; b < numPlants; b++)
    {
      plants[b].simulateWeek();
    }

    //calls each fish's simulateWeek()
    for (int c = 0; c < numFish; c++)
    {
      fish[c].simulateWeek();
    }

    //add up masses of all plants
    for (int d = 0; d < numPlants; d++)
    {
      plantMass = plantMass + plants[d].getSize();
    }

    //add up all living fish
    for (int e = 0; e < numFish; e++)
    {
      if (fish[e].isAlive() == true)
        fishPopulation++;
    }

    //output amount of living fish and total mass of plants
    //"Week #" ...8 characters
    cout << "Week " << left << setw(3) << setfill(' ') << i;
    //25 characters...8 periods
    cout << "Amount of fish" << right << setw(11) << setfill('.') << fixed << setprecision(0) << fishPopulation << "     ";
    //30 characters...set precision
    cout << "Mass of plants" << right << setw(17) << setfill('.') << setprecision(2) << plantMass << endl;
  }

  cout << endl;
  return 0;
}
