#include <iostream>

template<typename T>
struct BXT {
    using Mystery = T;
    template<typename U>
    struct Magic {
        U x;
    };
};

template<typename T>
struct DXTT : private BXT<T> {
    using typename BXT<T>::Mystery;
    Mystery* p;
};

template<typename T>
struct DXTM : private BXT<T> {
    template<typename U>
    using Magic = typename BXT<T>::template Magic<U>;
    Magic<T>* p;
    Magic<int>* q;
};

int main() {
    DXTT<int> d1;
    DXTM<char> d2;
    std::cout << sizeof(*d2.p) << std::endl;
    std::cout << sizeof(*d2.q) << std::endl;
    return 0;
}