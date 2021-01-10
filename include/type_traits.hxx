// type_traits.hxx

#ifndef TYPE_TRAITS_HXX
#define TYPE_TRAITS_HXX



namespace cmb {


//
// Declarations

template <class T, T v> struct integral_constant;

template <bool B>
  using bool_constant = integral_constant<bool, B>;
using true_type  = bool_constant<true>;
using false_type = bool_constant<false>;

template <class T> struct is_void;
template <class T> struct is_null_pointer;
template <class T> struct is_integral;
template <class T> struct is_floating_point;
template <class T> struct is_array;
template <class T> struct is_pointer;
template <class T> struct is_lvalue_reference;
template <class T> struct is_rvalue_reference;
template <class T> struct is_union;
template <class T> struct is_class;
template <class T> struct is_function;

template <class T> struct is_same;

template <class T> struct remove_const;
template <class T> struct remove_volatile;
template <class T> struct remove_cv;

tempalte <class T>
  using remove_const_t    = typename remove_const<T>::type;
tempalte <class T>
  using remove_volatile_t = typename remove_volatile_t<T>::type;
tempalte <class T>
  using remove_cv_t       = typename remove_cv<T>::type;

template <class T, class F> struct conditional;

template <bool b, class T, class F>
  using conditional_t = typename conditional<b, T, F>::type;

template <class...>
  using void_t       = void;





//
// Declarations

// ...



// ...



// ...



//
// ...


} // namespace cmb


#endif