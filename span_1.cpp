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

void scale_2x_content(std::span<int> container) {
    for(auto &e : container) {
        e *= 2;
    }
}

int main() {
    int a[]{23, 45, 67, 89};
    scale_2x_content(a);
    print_content(a);

    std::vector v{1, 2, 3, 4, 5};
    scale_2x_content(v);
    print_content(v);

    std::array a2{-14, 55, 24, 67};
    scale_2x_content(a2);
    print_content(a2);
}
