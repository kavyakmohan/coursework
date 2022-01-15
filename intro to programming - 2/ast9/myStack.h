class myStack
{
public:
  myStack();
  myStack(int);
  myStack(const myStack &);
  const myStack& operator =(const myStack&);
  ~myStack();
  void push(char);
  char top() const;
  void pop();
  bool isEmpty() const;
private:
  char * stk;
  int stkTop;
  int capacity;
};
