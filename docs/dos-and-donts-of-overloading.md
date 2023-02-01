# The do's and dont's of overloading

1. Define operators primarily to mimic conventional usage
2. Use nonmember functions for symmetric operators
3. Overload operations that are roughly equivalent
4. Overload only for operations that are roughly equivalent
5. Avoid conversion operators
6. Use using for customization points
7. Overload unary & only as part of a system of smart pointers and references
8. Use an operator for an operation with its conventional meaning
9. Define overloaded operators in the namespace of their operands
10. If you feel like overloading a lambda, use a generic lambda

Refer to [C++ Core Guidelines](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-overloading-and-overload-operators) for more information.

---
[Back](../README.md)