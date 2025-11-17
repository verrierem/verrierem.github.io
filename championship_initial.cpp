#include <string>
#include <iostream>
#include <limits.h>

namespace meta
{
/* Implement a stack of integers */
// TODO


/* head: get the head of the stack */
template<typename S> struct head;

// TODO


/* tail: get the tail of the stack */
template<typename S> struct tail;

// TODO


/* ToString: Convert a compile-time stack to string */
template<typename S> std::string to_string(S);

// TODO


/* length: number of elements in the stack */
template<typename S> struct length;

// TODO


/* accumulate: sum the elements in the stack */
template<typename S> struct accumulate;

// TODO


/* fold_left: f(f(...f(f(init, x1), x2), ...), xn), where
 *   * x1, (x2, (..., (xn)...)) are the elements of the stack.
 *   * (f : X * int -> X) is a compile-time function, where X is any type. */
template<
  typename Stack,
  typename return_type,
  template<return_type, int> class F,
  return_type init>
struct fold_left;

// TODO


/* fold_right: f(x1, f(x2, ...f(xn, init)...)), where
 *   * x1, (x2, (..., (xn)...)) are the elements of the stack.
 *   * (f : int * X -> X) is a compile-time function, where X is any type. */
template<
  typename Stack,
  typename return_type,
  template<return_type, int> class F,
  return_type init>
struct fold_right;

// TODO


/* Generate the n-th first factorials (n!,((n-1)!, ...(0!)...))*/
template<int n> struct factorial;

// TODO



/* Reverse a stack! */
template<typename S> struct reverse;

// TODO

} // namespace meta


template<int x, int y> struct Min { static constexpr int value = (x<y)?x:y; };
template<int x, int y> struct Max { static constexpr int value = (x<y)?y:x; };
template<int x, int y> struct Sum { static constexpr int value = x+y; };
template<int x, int y> struct Inc { static constexpr int value = x+1; };
template<int x, int y> struct Sub { static constexpr int value = x-y; };

int main(void)
{
    using MyStack = /* TODO */;
    using EmptyStack = /* TODO */;
    std::cout
      << "meta::head<MyStack>::value = " << meta::head<MyStack>::value
      << std::endl
      << "meta::head<meta::tail<MyStack>::type>::value = "
      << meta::head<meta::tail<MyStack>::type>::value
      << std::endl
      << "meta::to_string(MyStack()) = " << meta::to_string(MyStack())
      << std::endl
      << "meta::to_string(EmptyStack()) = " << meta::to_string(EmptyStack())
      << std::endl
      << "meta::length<MyStack>::value = " << meta::length<MyStack>::value
      << std::endl
      << "meta::accumulate<MyStack>::value = " << meta::accumulate<MyStack>::value
      << std::endl
      << "meta::fold_left<MyStack, int, Sum, 0>::value = "
      << meta::fold_left<MyStack, int, Sum, 0>::value
      << std::endl
      << "meta::fold_left<MyStack, int, Inc, 0>::value = "
      << meta::fold_left<MyStack, int, Inc, 0>::value
      << std::endl
      << "meta::fold_left<MyStack, int, Max, INT_MIN>::value = "
      << meta::fold_left<MyStack, int, Max, INT_MIN>::value
      << std::endl
      << "meta::fold_left<MyStack, int, Min, INT_MAX>::value = "
      << meta::fold_left<MyStack, int, Min, INT_MAX>::value
      << std::endl
      << "meta::fold_left<MyStack, int, Sub, 0>::value = "
      << meta::fold_left<MyStack, int, Sub, 0>::value
      << std::endl
      << "meta::fold_right<MyStack, int, Sub, 0>::value = "
      << meta::fold_right<MyStack, int, Sub, 0>::value
      << std::endl
    ;

    using FactorialStack = typename meta::factorial<12>::type;
    using ReversedStack = typename meta::reverse<FactorialStack>::type;
    std::cout
      << "meta::factorial<12>::type = " << meta::to_string(FactorialStack())
      << std::endl
      << "meta::reverse<FactorialStack>::type = " << meta::to_string(ReversedStack())
      << std::endl
    ;
    
    return 0;
}
