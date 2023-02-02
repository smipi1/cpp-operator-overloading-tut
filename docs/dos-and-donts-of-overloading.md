# The do's and dont's of overloading

1. Follow the [principle of least astonishment (POLA)](https://en.wikipedia.org/wiki/Principle_of_least_astonishment). I.e., [define operators to mimic conventional language](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c160-define-operators-primarily-to-mimic-conventional-usage):
   ```
   // After
   x = y;
   // This should hold
   x == y;
   ```
2. [Maintain symmetry with operators where expected](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c161-use-non-member-functions-for-symmetric-operators). E.g., to maintain symmetry, all the following should work:
   ```
   class MyInt{ ... };
   MyInt i1 = MyInt(1) + MyInt(3);  // Obvious
   MyInt i2 = MyInt(2) + 5;         // Implicit conversion kicks in
   MyInt i3 = 5 + MyInt(2);         // Extra work needed
   ```
   [KISS](http://principles-wiki.net/principles:keep_it_simple_stupid) won't get you [EUHM](http://principles-wiki.net/principles:easy_to_use_and_hard_to_misuse), so don't be lazy.
3. [Overload operations that are roughly equivalent, and *only* those](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c162-overload-operations-that-are-roughly-equivalent). E.g., the following are roughly equivalent:
   ```
   // Overloading makes sense from user perspective
   void print(int a);
   void print(int a, int base);
   void print(const string&);
   ```
   but the following likely are not equivalent:
   ```
   // Overloading would be confusing and error-prone from user perspective
   void process(int queue[], int depth);
   void process(std::string documentBody);
   void process(DnaSequence& data);
   ```
4. [Avoid implicit conversion operators.](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c164-avoid-implicit-conversion-operators) E.g.:
   ```
   // This makes sense
   double gagueValue = 6.7f;
   int lowerPrecisionGagueValue = gagueValue;

   // Here be dragons, so make sure this is not supported!
   std::string s = "...";
   char* cStyleString = s;
   ```
5. [Use using for customization points](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c165-use-using-for-customization-points)
6. [Overload unary & only as part of a system of smart pointers and references](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c166-overload-unary--only-as-part-of-a-system-of-smart-pointers-and-references)
7. [Use an operator for an operation with its conventional meaning](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c167-use-an-operator-for-an-operation-with-its-conventional-meaning)
8. [Define overloaded operators in the namespace of their operands](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c168-define-overloaded-operators-in-the-namespace-of-their-operands)
9. [If you feel like overloading a lambda, use a generic lambda](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c170-if-you-feel-like-overloading-a-lambda-use-a-generic-lambda)

Refer to [C++ Core Guidelines](https://www.modernescpp.com/index.php/c-core-guidelines-rules-for-overloading-and-overload-operators) for more information.

---

[Back](../README.md)