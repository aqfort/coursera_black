#include <iostream>

using namespace std;

/*
template <typename T>
T Sum(const T &x)
{
  return x;
}

template <typename T, typename... Args>
T Sum(const T &x, const Args &...args)
{
  return x + Sum(args...);
}
*/

template <typename... Args>
auto Sum(const Args &...args)
{
  return (args + ...);
}

#include <vector>
#include <string>

template <typename... Args>
void PrintSizes(const Args &...args)
{
  ((cout << args.size() << endl), ...);
}

template <typename... Args>
void Clear(Args &...args)
{
  (args.clear(), ...);
}

int main()
{
  cout << Sum(1, 2, 3) << endl;
  cout << Sum(1.5, 2.5, 10.0, 0.7, 0.3) << endl;

  vector v = {1, 2, 3};
  string s = "Hello";

  PrintSizes(v, s);
  Clear(v, s);
  PrintSizes(v, s);

  return 0;
}
