# The do's and dont's of overloading

1. Follow the [principle of least astonishment (POLA)](https://en.wikipedia.org/wiki/Principle_of_least_astonishment), which includes:
   - [defining operators to mimic conventional language (maintain logic consistency)](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c160-define-operators-primarily-to-mimic-conventional-usage):
     ```
     // After
     x = y;
     // This should hold
     x == y;
     ```
   - [using an operator for an operation with its conventional meaning](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c167-use-an-operator-for-an-operation-with-its-conventional-meaning)
     ```
     X operator+(X a, X b) { return a.v - b.v; }
     ```
   - [Maintain symmetry with operators where expected](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c161-use-non-member-functions-for-symmetric-operators). E.g., to maintain symmetry, **all the following should work**:
     ```
     class MyInt{ ... };
     MyInt i1 = MyInt(1) + MyInt(3);  // Obvious to implement
     MyInt i2 = MyInt(2) + 5;         // Often for free due to implicit conversion, better defined explicitly
     MyInt i3 = 5 + MyInt(2);         // Requires extra work to support
     ```
     Note: [KISS](http://principles-wiki.net/principles:keep_it_simple_stupid) won't get you [EUHM](http://principles-wiki.net/principles:easy_to_use_and_hard_to_misuse), so don't be lazy.
   - [Overload operations that are roughly equivalent, and *only* those](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c162-overload-operations-that-are-roughly-equivalent). E.g., the following are roughly equivalent, so **overoading makes sense**:
     ```
     void print(int a);
     void print(int a, int base);
     void print(const string&);
     ```
     but the following are not equivalent, so **overloading is confusing**:
     ```
     void process(int queue[], int depth);
     void process(std::string documentBody);
     void process(DnaSequence& data);
     ```
   Hack along with [good-api-bad-api.cpp](../good-api-bad-api.cpp)
2. [Avoid implicit conversion operators.](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c164-avoid-implicit-conversion-operators) E.g., the following implicit conversions are either **essential**, or **fundamental in the application domain**:
   ```
   double gagueValue = 6.7f;
   int lowerPrecisionGagueValue = gagueValue;

   double realValue = 5.1f;
   ComplexNumber complexValue = realValue;
   ```
   where the following causes **surprises and programming errors**, and should be prevented with **compile errors**:
   ```
   std::string s = "...";
   char* cStyleString = s;
   ```
3. [Use '`using`' for customization points](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c165-use-using-for-customization-points)
4. [Overload unary '`&`' only as part of a system of smart pointers and references](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c166-overload-unary--only-as-part-of-a-system-of-smart-pointers-and-references)
5. [Define overloaded operators in the namespace of their operands](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c168-define-overloaded-operators-in-the-namespace-of-their-operands)
6. [If you feel like overloading a lambda, use a generic lambda](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c170-if-you-feel-like-overloading-a-lambda-use-a-generic-lambda)

Refer to [C++ Core Guidelines](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-overloading-and-overload-operators) for more information.

---

[Back](../README.md)