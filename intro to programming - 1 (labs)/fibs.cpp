int fib(int n)
{
  int prev = 0, prev2 = 1, sum = 0;

  for (int i=0; i < n; i++)
    {
      sum = prev + prev2;
      prev2 = prev;
      prev = sum;
    }
  return sum;
}

bool isFib(int n)
{
  bool rval = false;
  int i = 0;

  while (fib(i) <= n)
    {
      if (fib(i) == n){
	  rval = true;
	  break;
	}
	  i = i + 1;
    }
  return rval;
}
