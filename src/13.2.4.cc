#include <iostream>
#include <memory>

template<typename T>
struct C {
    C() : i(new I) {}
    struct I {
        void foo() {
            std::cout << "C<T>::I" << std::endl;
        }
    };
    std::unique_ptr<I> i;
    struct J {
        J() : i(new I) {}
        std::unique_ptr<I> i;
    } j;
};

template<>
struct C<int>::I {
    void foo() {
        std::cout << "C<int>::I" << std::endl;
    }
};

template<typename T>
void fum() {
    C<T> c1;
    c1.i->foo();
    c1.j.i->foo();
}

int main() {
    fum<char>();
    fum<int>();
    return 0;
}