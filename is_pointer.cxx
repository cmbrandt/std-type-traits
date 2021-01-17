// is_pointer.cxx

#include <iostream>
#include "include/type_traits.hxx"


int main()
{
  std::cout <<   "cmb::is_pointer<void>::value = "
            <<    cmb::is_pointer<void>::value // = 0
            << "\ncmb::is_pointer_v<int*>      = "
            <<    cmb::is_pointer_v<int*>      // = 1
            << std::endl;
}




namespace detail
{
  template <class T,
            bool = cmb::is_arithmetic_v<T>> struct is_signed_impl
  : public false_type { };

  template <class T>                        struct is_signed_impl<T, true>
  : public integral_constant<bool, T(-1) < T(0)>> { };
} // namespace detail


template <typename T> struct is_signed
: public cmb::detail::is_signed_impl<T>::type { };