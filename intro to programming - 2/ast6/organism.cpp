#include <iostream>
#include "organism.h"
using namespace std;

//ORGANISM CLASS FUNCTIONS
/**************************************************
 FUNCTION NAME: organism
 PARAMETERS: double initSize and double initRate
 RETURN TYPE: none
 DESCRIPTION: constructor sets growthRate and size
***************************************************/
organism::organism(double initSize, double initRate)
{
  size = initSize;
  growthRate = initRate;
}


/***************************************************
 FUNCTION NAME: simulateWeek()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: increments size by growthRate
***************************************************/
void organism::simulateWeek()
{
  size = size + growthRate;
//  cout << "size after simulateWeek() is " << size << endl;
}


/****************************************************
 FUNCTION NAME: assignRate()
 PARAMETERS: double newRate
 RETURN TYPE: void
 DESCRIPTION: assings newRate to growthRate
*****************************************************/
void organism::assignRate(double newRate)
{
  growthRate = newRate;
//  cout << "growth rate after assignRate is " << growthRate << endl;
}


/******************************************************
 FUNCTION NAME: alterSize()
 PARAMETERS: double amount
 RETURN TYPE: void
 DESCRIPTION: increases size by amount
********************************************************/
void organism::alterSize(double amount)
{
  size = size + amount;
//  cout << "size after alterSize is " << size << endl;
}


/********************************************************
 FUNCTION NAME: death()
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: sets growthRate and size to 0
**********************************************************/
void organism::death()
{
  growthRate = 0.0;
  size = 0.0;
//  cout << "growth rate is " << growthRate << " and size is " << size << " after death()" << endl;
}


/***********************************************************
 FUNCTION NAME: getSize() const
 PARAMETERS: none
 RETURN TYPE: double
 DESCRIPTION: returns size
************************************************************/
double organism::getSize() const
{
  return size;
}


/***********************************************************
 FUNCTION NAME: getRate() const
 PARAMETERS: none
 RETURN TYPE: double
 DESCRIPTION: returns growthRate
************************************************************/
double organism::getRate() const
{
  return growthRate;
}


/************************************************************
 FUNCTION NAME: isAlive() const
 PARAMETERS: none
 RETURN TYPE: bool
 DESCRIPTION: returns true if size is > 0 and false otherwise
*************************************************************/
bool organism::isAlive() const
{ 
  if (size > 0.0)
  {
//    cout << "organism alive" << endl;
    return true;
  }
  else
  {
//    cout << "organism dead" << endl;
    return false;
  }
}


//PLANT MEMBER FUNCTIONS
/**********************************************************
 FUNCTION NAME: plant
 PARAMETERS: doublt initSize, double initRate
 RETURN TYPE: none...constructor
 DESCRIPTION: sets growthRate and size using parameters
***********************************************************/
plant::plant(double initSize, double initRate)
{
  alterSize(initSize);
//  cout << "size of plant is " << getSize() << endl;
  assignRate(initRate);
//  cout << "growth rate of plant is " << getRate() << endl;
}


/***********************************************************
 FUNCTION NAME: nibbledOn
 PARAMETERS: double amount
 RETURN TYPE: void
 DESCRIPTION: decreases size by amount. if amount is larger than size, sets size to 0
************************************************************/
void plant::nibbledOn(double amount)
{
  if (amount > getSize())
    alterSize(0.0);
  else
    alterSize(getSize() - amount);

//  cout << "size of plant is now " << getSize() << endl;
}


//ANIMAL MEMBER FUNCTIONS
/***********************************************************
 FUNCTION NAME: animal
 PARAMETERS: double initSize, double initRate, double initNeed
 RETURN TYPE: none...constructor
 DESCRIPTION: sets size, growthRate, and needThisWeek using parameters. eatenThisWeek is set to 0
*************************************************************/
animal::animal(double initSize, double initRate, double initNeed)
{
  alterSize(initSize);
  assignRate(initRate);
  //assignNeed(initNeed);
  needThisWeek = initNeed; 
  eatenThisWeek = 0.0;
}


/*************************************************************
 FUNCTION NAME: assignNeed
 PARAMETERS: double newNeed
 RETURN TYPE: void
 DESCRIPTION: assigns parameter to needThisWeek
*************************************************************/
void animal::assignNeed(double newNeed)
{
  needThisWeek = newNeed;
}


/*************************************************************
 FUNCTION NAME: eat
 PARAMETERS: double amount
 RETURN TYPE: void
 DESCRIPTION: increments eatenThisWeek by amount
**************************************************************/
void animal::eat(double amount)
{
  eatenThisWeek = eatenThisWeek + amount;
}


/**************************************************************
 FUNCTION NAME: simulateWeek
 PARAMETERS: none
 RETURN TYPE: void
 DESCRIPTION: increments size by growthRate IF eatenThisWeek is >= needThisWeek. otherwise sets size, growthRate, and eatenThisWeek to 0
*****************************************************************/
void animal::simulateWeek()
{
  if (eatenThisWeek >= needThisWeek)
    alterSize(getSize() + getRate());
  else
  {
    alterSize(0.0);
    assignRate(0.0);
    eatenThisWeek = 0.0;
  }
}


/***************************************************************
 FUNCTION NAME: stillNeed
 PARAMETERS: none
 RETURN TYPE: double
 DESCRIPTION: returns 0 if eatenThisWeek >= needThisWeek. otherwise returns difference between needThisWeek and eatenThisWeek
****************************************************************/
double animal::stillNeed() const
{
  if (eatenThisWeek >= needThisWeek)
    return 0.0;
  else
    return needThisWeek - eatenThisWeek;
}


/*******************************************************************
 FUNCTION NAME: totalNeed
 PARAMETERS: none
 RETURN TYPE: double
 DESCRIPTION: returns needThisWeek
*********************************************************************/
double animal::totalNeed() const
{
  return needThisWeek;
}


//HERBIVORE MEMBERS AND FUNCTIONS

//regulates how big of a portion of plant the herbivore consumes
const double herbivore::PORTION = 0.5;

//regulates how big of a portion the herbivore can consumbe in one feeding when nibble is called
const double herbivore::MAX_FRACTION = 0.1;

/*********************************************************************
 FUNCTION NAME: herbivore
 PARAMETERS: double initSize, double initRate, double initNeed
 RETURN TYPE: none...constructor
 DESCRIPTION: sets size, growthRate, needThisWeek using parameters and eatenThisWeek to 0
**********************************************************************/
herbivore::herbivore(double initSize, double initRate, double initNeed)
{
//  animal(initSize, initRate, initNeed);
  alterSize(initSize);
  assignRate(initRate);
  assignNeed(initNeed);
//  eatenThisWeek = 0;
}

/***********************************************************************
 FUNCTION NAME: nibble
 PARAMETERS: plant& meal
 RETURN TYPE: void
 DESCRIPTION: consumes a portion of plant object
************************************************************************/
void herbivore::nibble(plant& meal)
{
  //amount = PORTION times plant object(meal)'s size
  double amount = PORTION * meal.getSize();

  if (amount > MAX_FRACTION * totalNeed())
    amount = MAX_FRACTION * totalNeed();

//  double valueReturnedbystillNeed = stillNeed();
  else if (amount > stillNeed())
    amount = stillNeed();

  //call eat and the meal object's nibbledOn and pass the same amount into both functions
  eat(amount);
  meal.nibbledOn(amount);
}

