// test_other_transformations.cxx

#include <iostream>
#include "test_other_transformations.hxx"
#include "type_traits.hxx"


void test_other_transformations()
{
  int fail = 0;

  fail = test_conditional(fail);

  if (fail == 0)
    std::cout << "\ntest_other_transformations()   passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_other_transformations()   had " << fail << " error(s)." << std::endl;
}



//
// Helper class tests

int test_conditional(int fail)
{

  return fail;
}