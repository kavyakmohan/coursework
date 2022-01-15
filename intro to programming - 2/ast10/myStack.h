class myStack
{
public:
  myStack();
  myStack(int);
  myStack(const myStack&);
  const myStack& operator=(const myStack&);
  ~myStack();
  void push(int);
  int top() const;
  void pop();
  bool isEmpty() const;
private:
  struct node
  {
    int item;
    node * link;
  };

  node * head;
};
