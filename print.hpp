#include <iostream>
#include <string>
#include <type_traits>
#include <sstream>

template <typename T>
class has_print_method {
private:
    template <typename U>
    static auto test(int) -> decltype(std::declval<U>()._print(), std::true_type());

    template <typename>
    static std::false_type test(...);
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

template <typename T>
typename std::enable_if<has_print_method<T>::value, std::string>::type
getPrintable(const T& obj) {
    return obj._print();
}

template <typename T>
typename std::enable_if<!has_print_method<T>::value, std::string>::type
getPrintable(const T& obj) {
    // Using stringstream to capture the output of std::cout-like objects
    std::ostringstream oss;
    oss << obj;
    return oss.str();
}

inline void print() {
    std::cout << std::endl;
}

template <typename T, typename... Args>
void print(const T& first, const Args&... args) {
    std::cout << getPrintable(first);
    if (sizeof...(args) > 0) {
        std::cout << " ";
    }
    print(args...); // Recursive call
}
