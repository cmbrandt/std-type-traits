// type_traits.hxx

#ifndef TYPE_TRAITS_HXX
#define TYPE_TRAITS_HXX



namespace cmb {


//
// Declarations


// Helper class
template <class T, T v> struct integral_constant;

template <bool B>
  using bool_constant = integral_constant<bool, B>;
using true_type  = bool_constant<true>;
using false_type = bool_constant<false>;


// Primary type categories
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

//template <class T>
//  using inline constexpr bool is_void_v           = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_null_pointer_v   = is_null_pointer<T>::value;
//template <class T>
//  using inline constexpr bool is_integral_v       = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_floating_point_v = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_array_v          = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_pointer_v        = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_lvalue_v         = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_rvalue_v         = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_union_v          = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_class_v          = is_void<T>::value;
//template <class T>
//  using inline constexpr bool is_function_v       = is_void<T>::value;


// Type relationships
template <class T, class U> struct is_same;

template <class T, class U>
  constexpr bool is_same_v = is_same<T,U>::value;


// Const-volatile specifiers
template <class T> struct remove_const;
template <class T> struct remove_volatile;
template <class T> struct remove_cv;

template <class T>
  using remove_const_t    = typename remove_const<T>::type;
template <class T>
  using remove_volatile_t = typename remove_volatile<T>::type;
template <class T>
  using remove_cv_t       = typename remove_cv<T>::type;


// Other transformations
template <bool B, class T, class F> struct conditional;

template <bool B, class T, class F>
  using conditional_t = typename conditional<B,T,F>::type;


//
// Implementations


// integral_constant

template <class T, T v>
struct integral_constant {

  static constexpr T value = v;

  using value_type = T;
  using type       = integral_constant; // using injected-class-name

  constexpr operator   value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};


// Primary type categories

// ----
// TODO
// ----


// is_same

template <class T, class U> struct is_same      : cmb::false_type { };
template <class T>          struct is_same<T,T> : cmb::true_type  { };


// remove_const, remove_volatile, remove_cv

template <class T> struct remove_const<const T>       { using type = T; };
template <class T> struct remove_volatile<volatile T> { using type = T; };
template <class T> struct remove_cv<const T>          { using type = T; };
template <class T> struct remove_cv<volatile T>       { using type = T; };
template <class T> struct remove_cv<const volatile T> { using type = T; };


// conditional

template <bool B, class T, class F>
struct conditional { using type = T; };

template <class T, class F>
struct conditional<false, T, F> { using type = F; };


} // namespace cmb


#endif