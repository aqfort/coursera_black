#include "test_runner.h"
#include "profile.h"
#include "sum.h"

void Test()
{
  ASSERT_EQUAL(3, Sum(1, 2));
}

int main(int argc, const char *const *const argv, const char *const *const envp)
{
  printf("argc = %d\n", argc);
  {
    LOG_DURATION("Section: argv");
    int i = 0;
    char **pointer = const_cast<char **>(argv);
    while (*pointer)
    {
      printf("argv[%d] = %s\n", i++, *pointer++);
    }
  }
  {
    LOG_DURATION("Section: envp");
    int i = 0;
    char **pointer = const_cast<char **>(envp);
    while (*pointer)
      printf("envp[%d] = %s\n", i++, *pointer++);
  }
  {
    LOG_DURATION();
    TestRunner test_runner;
    RUN_TEST(test_runner, Test);
  }
  return 0;
}
