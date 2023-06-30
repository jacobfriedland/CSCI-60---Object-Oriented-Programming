/*
FRIEDLAND (JACOB)
LIU (AARON)
*/

#include  <iostream>
#include  <fstream>
#include  <string>
using namespace std;

class ModInt
{
private:
  int mod_;
  int value_;
public:

  ModInt(int m, int v)
  {
    mod_ = m;
    value_ = v;
  }

  ModInt()
  {
    mod_ = 0;
    value_ = 0;
  }

  int mod()
  {
    return mod_;
  }

  int value()
  {
    return value_;
  }

  void operator +=(ModInt rhs)
  {
    if(mod_ != rhs.mod_)
    {
      rhs.mod_ = -1;
      rhs.value_ = -1;
    }
    else
    {
      value_ = value_ + rhs.value_;
      value_ = value_ % mod_;
    }

  }

};

bool operator ==(ModInt lhs, ModInt rhs)
{
  return (lhs.mod() == rhs.mod()) && (lhs.value() == rhs.value());
}

/*
Question 3: += must be a member function because it modifies the object which
+= is used on. The LHS is changed when += is used.
*/

/*
Question 4:
instead of 1 argument, need 2 arguments. Returns new ModInt variable.

If mod for lhs and rhs are the same, add values, do value % mod, then
create new ModInt object by using ModInt a(mod, value);
If mod for lhs and rhs are not the same, then
create new ModInt object by using ModInt a(-1, -1;
ex. a = (b + c), (b + c) needs to return a value
*/

ModInt operator +(ModInt lhs, ModInt rhs)
{
  if(lhs.mod() == rhs.mod())
  {
    ModInt a(lhs.mod(), (lhs.value() + rhs.value()) % rhs.mod());
    return a;
  }
  else
  {
    ModInt a(-1,-1);
    return a;
  }
}

int main()
{
  ModInt modint1 = ModInt(6, 3);
  ModInt modint2 = ModInt(6, 4);
  ModInt modint3 = ModInt();
  bool comparison = modint1 == modint2;
  modint1 += modint2;
  modint3 = modint1 + modint2;
  cout << "+= Test: " << modint1.mod()<< " " << modint1.value() << endl;
  cout << "+ Test: " << modint3.mod() << " " << modint3.value() << endl;
  cout << "== Test(comparing modint1 and modint2): " << comparison << endl;
  return 0;

}
