class organism
{
public:
  organism(double = 1, double = 0);
  void simulateWeek();
  void assignRate(double);
  void alterSize(double);
  void death();
  double getSize() const;
  double getRate() const;
  bool isAlive() const;
private:
  double growthRate;
  double size;
};


class plant : public organism
{
public:
  plant(double = 1, double = 0);
  void nibbledOn(double);
};


class animal : public organism
{
public:
  animal(double = 1, double = 0, double = 0);
  void assignNeed(double);
  void eat(double);
  void simulateWeek();
  double stillNeed() const;
  double totalNeed() const;
private:
  double needThisWeek;
  double eatenThisWeek;
};


class herbivore : public animal
{
public:
  static const double PORTION;
  static const double MAX_FRACTION;
  herbivore(double = 1, double = 0, double = 0);
  void nibble(plant&);
};
