#include <iostream>
#include <vector>
#include <type_traits>


template<typename T>
T obj();

template<typename T>
auto len(T const& t)  -> decltype((void)t.size(),
                                  (void)typename std::enable_if<std::is_same<T,std::vector<int>>::value>::type(),
                                  typename T::size_type())
{
    return t.size();
}

std::size_t len(...) {
    return 0;
}

int main()
{
    int a[10];
    std::cout << len(a) << std::endl;
    std::vector<int> v;
    v.push_back(10);
    std::cout << len(v) << std::endl;
    std::allocator<int> x;
    std::cout << len(x) << std::endl;
}