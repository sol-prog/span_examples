#include <iostream>
#include <vector>
#include <array>
#include <span>

void print_content(std::span<int> container) {
    for(const auto &e : container) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main() {
    int a[]{23, 45, 67, 89};
    print_content(a);

    std::vector v{1, 2, 3, 4, 5};
    print_content(v);

    std::array a2{-14, 55, 24, 67};
    print_content(a2);
}
