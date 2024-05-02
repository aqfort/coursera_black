#include "test_runner.h"
#include "profile.h"

#include <iostream>
#include <vector>

using namespace std;

// default debugging
// -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC

// memory leaks
// -fsanitize=address

void f1()
{
  vector<int> v{8};
  v.reserve(2);
  size_t i = 2;
  cout << v[i] << endl;
}

const string &MakeString()
{
  const vector<string> v = {
      "C++",
      "Python"};
  return v[0];
}

void f2()
{
  const auto &ref = MakeString();
  cout << ref << endl;
}

void f3()
{
  int *p = new int;
}

int main()
{
  // f1();
  // f2();
  // f3();

  cout << "hello" << endl;

  return 0;
}
