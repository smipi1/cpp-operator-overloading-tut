#include <iomanip>
#include <iostream>

class Printer {
public:
    template<class T>
    void print(T i) {
        std::cout << __PRETTY_FUNCTION__ << ": " << i << std::endl;
    }

    void print(const void* memory, size_t size) {
        auto byte = reinterpret_cast<const uint8_t*>(memory);

        std::cout << __PRETTY_FUNCTION__ << ":";

        for (int i = 0; i < size; i++) {
            std::cout << " " << std::hex << std::setw(2) << std::setfill('0')
                      << (int)byte[i];
        }

        std::cout << std::endl;
    }
};

int main(int argc, char const* argv[]) {
    Printer p;

    const char message[] = "something nice!";

    p.print(1);
    p.print(1.1f);
    p.print(message);
    p.print((const void*)message, sizeof(message));

    std::cout << std::endl;
    return 0;
}
