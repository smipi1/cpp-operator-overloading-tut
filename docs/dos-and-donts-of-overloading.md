# The do's and dont's of overloading

1. Follow the [principle of least astonishment (POLA)](https://en.wikipedia.org/wiki/Principle_of_least_astonishment). E.g.,
   ```
   // After
   x = y;
   // This should hold
   x == y;
   ```
2. Maintain symmetry with operators where expected. E.g., to maintain symmetry, all the following should work:
   ```
   class MyInt{ ... };
   MyInt i1 = MyInt(1) + MyInt(3);  // Obvious
   MyInt i2 = MyInt(2) + 5;         // Implicit conversion kicks in
   MyInt i3 = 5 + MyInt(2);         // Extra work needed
   ```
   [KISS](http://principles-wiki.net/principles:keep_it_simple_stupid) won't get you [EUHM](http://principles-wiki.net/principles:easy_to_use_and_hard_to_misuse), so don't be lazy.
3. Overload operations that are roughly equivalent
4. Overload only for operations that are roughly equivalent
5. Avoid conversion operators
6. Use using for customization points
7. Overload unary & only as part of a system of smart pointers and references
8. Use an operator for an operation with its conventional meaning
9.  Define overloaded operators in the namespace of their operands
10. If you feel like overloading a lambda, use a generic lambda

Refer to [C++ Core Guidelines](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-overloading-and-overload-operators) for more information.

---

[Back](../README.md)