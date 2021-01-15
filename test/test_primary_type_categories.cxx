// test_primary_type_categories.cxx

#include <iostream>
#include "test_primary_type_categories.hxx"
#include "type_traits.hxx"


void test_primary_type_categories()
{
  int fail = 0;

  fail = test_is_void(fail);
  fail = test_is_null_pointer(fail);
  fail = test_is_integral(fail);
  fail = test_is_floating_point(fail);
  fail = test_is_array(fail);
  fail = test_is_pointer(fail);
  fail = test_is_lvalue_reference(fail);
  fail = test_is_rvalue_reference(fail);
  fail = test_is_union(fail);
  fail = test_is_class(fail);
  fail = test_is_function(fail);

  if (fail == 0)
    std::cout << "\ntest_primary_type_categories() passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_primary_type_categories() had " << fail << " error(s)." << std::endl;
}



//
// Primary type categories tests

int test_is_void(int fail)
{

  return fail;
}



int test_is_null_pointer(int fail)
{

  return fail;
}



int test_is_integral(int fail)
{

  return fail;
}



int test_is_floating_point(int fail)
{

  return fail;
}



int test_is_array(int fail)
{

  return fail;
}



int test_is_pointer(int fail)
{

  return fail;
}



int test_is_lvalue_reference(int fail)
{

  return fail;
}



int test_is_rvalue_reference(int fail)
{

  return fail;
}



int test_is_union(int fail)
{

  return fail;
}



int test_is_class(int fail)
{

  return fail;
}



int test_is_function(int fail)
{

  return fail;
}