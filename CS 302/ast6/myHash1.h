//Kavya Mohan AST 6
#include <iostream>
using namespace std;

template <class Type1, class Type2>
class myHash
{
public:
  myHash();
  myHash(const myHash<Type1, Type2>&);
  const myHash<Type1, Type2>& operator=(const myHash<Type1, Type2>&);
  ~myHash();
  Type2& operator[](Type1);
private:
  struct  tableItem
  {
    Type1 key;
    Type2 value;
  };

  size_t hashFunction01(const Type1&) const;
  size_t hashFunction02(const Type1&) const;
  void resize();
  size_t size;
  size_t entries;

  tableItem * table1;
  tableItem * table2;
};

//default constructor
template <class Type1, class Type2>
myHash<Type1, Type2>::myHash()
{
  //initialize table stats
  size = 10;
  entries = 0;

  //allocate memory to hash tables
  table1 = new tableItem[size];
  table2 = new tableItem[size];

  //initialize hash tables
  for (int i = 0; i < size; i++)
  {
    table1[i].key = Type1();
    table2[i].key = Type1();

    table1[i].value = Type2();
    table2[i].value = Type2();
  }
}

//copy constructor
template <class Type1, class Type2>
myHash<Type1, Type2>::myHash(const myHash<Type1, Type2>& copy)
{
  //deep copy of dynamic array
  size = copy.size;
  entries = copy.entries;

  table1 = new tableItem[size];
  table2 = new tableItem[size];

  for (int i = 0; i < size; i++)
  {
    table1[i].key = copy->table1[i].key;
    table1[i].value = copy->table1[i].value;

    table2[i].key = copy.table2[i].key;
    table2[i].value = copy.table2[i].value;
  }
}

//assignment operator
template <class Type1, class Type2>
const myHash<Type1, Type2>& myHash<Type1, Type2>::operator=(const myHash <Type1, Type2>& rhs)
{
  //deep copy of dynamic array
  if (this != & rhs)
  {
    delete [] table1;
    delete [] table2;

    size = rhs.size;
    entries = rhs.entries;

    table1 = new tableItem[size];
    table2 = new tableItem[size];

    for (int i = 0; i < rhs.size; i++)
    {
      table1[i].key = rhs->table1[i].key;
      table1[i].value = rhs->table1[i].value;

      table2[i].key = rhs->table2[i].key;
      table2[i].value = rhs->table1[i].value;
    }
  }
  return * this;
}

//destructor
template <class Type1, class Type2>
myHash<Type1, Type2>::~myHash()
{
  delete [] table1;
  delete [] table2;
}

//hash function 1
template <class Type1, class Type2>
size_t myHash<Type1, Type2>::hashFunction01(const Type1& key) const
{
  size_t sum = 0;
  size_t i;

  //adds up ASCII characters at even indices of the key item passed in
  for (i = 0; i < key.length(); i += 2)
    sum += key[i];

//  while (key[i] != '\0' )
// for (int i = 0; i < key.length(); i += 2)
//  {
//    sum += key[i];
  //  cout << endl << "sum=" << sum << endl;
//    i += 2;
//  }

  //mod the sum by the size
  return (sum % size);
}

//hash function 2
template <class Type1, class Type2>
size_t myHash<Type1, Type2>::hashFunction02(const Type1& key) const
{
  size_t sum = 0;
  size_t i;

  //if key only contains only 1 character,
  //multipy first character by 2
  if (key[i] == '\0')
    sum = key[0] * 2;

  //else add up ASCII characters at the odd indices of the key item passed in
  else
    for (i = 1; i < key.length(); i += 2)
      sum += key[i];

  //mod the sum by the size
  return (sum % size);
}

//returns the references of the value field at correct table/index based on hashfunct&key
template <class Type1, class Type2>
Type2& myHash<Type1, Type2>::operator[](Type1 key)
{
  //resize tables if load factor >= 50
  float loadFactor = float(entries) / float(size);

  if (loadFactor >= .5)
    resize();

  bool successful = false;

  //collision counter
  size_t i = 0;

  //calculate indices
  size_t index1 = hashFunction01(key);
  size_t index2 = hashFunction02(key);

  while (successful == false)
  {
    if (table1[index1].key == key)
      return table1[index1].value;

    if (table1[index1].key == Type1())
    {
      table1[index1].key = key;
      entries++;
      return table1[index1].value;
    }

    if (table1[index2].key == key)
      return table1[index2].value;

    if (table1[index2].key == Type1())
    {
      table1[index2].key = key;
      entries++;
      return table1[index2].value;
    }

    if (table2[index1].key == key)
      return table2[index1].value;

    if (table2[index1].key == Type1())
    {
      table2[index1].key = key;
      entries++;
      return table2[index1].value;
    }

    if (table2[index2].key == key)
      return table2[index2].value;

    if (table2[index2].key == Type1())
    {
      table2[index2].key = key;
      entries++;
      return table2[index2].value;
    }

   // i++;
    index1 = index1++  % size;
    index2 = index2++  % size;

  } //end while loop
}


//doubles tables and rehash entries
template <class Type1, class Type2>
void myHash<Type1, Type2>::resize()
{
  tableItem * temp1 = table1;
  tableItem * temp2 = table2;

  //larger tables allocated to tables
  size_t oldSize;
  oldSize = size;
  size *= 2;

  table1 = new tableItem[size];
  table2 = new tableItem[size];

  for (int i = 0; i < size; i++)
  {
    table1[i].key = Type1();
    table2[i].key = Type1();

    table1[i].value = Type2();
    table2[i].value = Type2();
  }

  //rehash table1
  for (int i = 0; i < oldSize; i++)
    if (temp1[i].key != Type1())
      (*this)[temp1[i].key] = temp1[i].value;

  //rehash table2
  for (int i = 0; i < oldSize; i++)
    if (temp2[i].key != Type1())
      (*this)[temp2[i].key] = temp2[i].value;

  //deallocate temp1 and temp2
  delete [] temp1;
  delete [] temp2;

  temp1 = temp2 = NULL;
}
