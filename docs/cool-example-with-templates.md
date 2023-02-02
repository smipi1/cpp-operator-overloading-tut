# A cool example when combined with templates.

In C++, templates provide a *blueprint or formula for creating generic classes or functions*. E.g.:

Consider this useful class:
```
class IntFifo() {
public:
    IntFifo() {}
    push(int value) {}
    int pop() {}
};
```

And this useful class:
```
class DoubleFifo() {
public:
    DoubleFifo() {}
    push(double value) {}
    double pop() {}
};
```

It would be really useful if the *type was parameterizable* to reduce code duplication! This is why templates exist. E.g.:
```
template<class T>
class Fifo 
public:
    Fifo()
    push(T value) {}
    T pop() {}
};
```

It would also be useful to make the *fifo depth parameterizable* to allow better compile-time code optimization. E.g.:
```
template<class T, int depth>
class Fifo {
private:
    T _values[depth];
public:
    Fifo()
    push(T value) {}
    T pop() {}
};
```

This transforms your class or function into a world of potential classes or functions:
```
int main() {
    Fifo<int> intFifo;
    intFifo.push(1);
    intFifo.push(2);
    
    Fifo<double> doubleFifo;
    doubleFifo.push(1.0f);
    doubleFifo.push(2.0f);
    
    Fifo<std::string> stringFifo;
    stringFifo.push("first");
    stringFifo.push("second");

    Fifo<Pony> ponyFifo;
    ...
}
```

Hack along with [dimensional-analysis-and-checking.cpp](../dimensional-analysis-and-checking.cpp)

---

[Previous](./dos-and-donts-of-overloading.md) | [Top](../README.md)