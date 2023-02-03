# What is function overloading in C++, and why should you care?

In C++, two functions can have the same name **if** the *number and/or type of arguments* passed is different.

These are all different functions:
```
void function(int n) {}          // 1
void function(double d) {}       // 2
void function(int n, int m) {}   // 3
void function()                  // 4
```

And the compiler understands which one you want to use based on the type and number or arguments:
```
int main()
{
    function();                  // calls 4
    function(3.2f);              // calls 2
    function(8);                 // calls 1
    function(2, 1);              // calls 3
}
```

Hack along with [function-overloading.cpp](../function-overloading.cpp).

P.S. also have a peek at [function-overloading-with-templated-function.cpp](../function-overloading-with-templated-function.cpp), which further reduces code duplication with a C++ template function.

---

[Previous](./the-good-api.md) | [Top](../README.md) | [Next](./what-is-operator-overloading-and-why-should-you-care.md)