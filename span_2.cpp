#include <iostream>
#include <vector>
#include <array>
#include <span>
#include <memory>

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

    // Allocate space for 10 integers on the heap
    size_t sz{10};
    auto p = std::make_unique<int[]>(sz);
    // Fill the previously allocated space
    for(size_t i = 0; i < sz; ++i) {
        p[i] = static_cast<int>(i);
    }
    // Pass a pointer/size pair to functions allow a std::span as the first argument
    scale_2x_content({p.get(), sz});
    print_content({p.get(), sz});
}
