class sixteen
{
public:
  static const int SIZE = 3;
  static const int WIN = 16;
  sixteen();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
  int over() const;
  void output() const;
private:
  int board[SIZE][SIZE];
};
