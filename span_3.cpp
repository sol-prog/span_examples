#include <iostream>
#include <span>
#include <iterator>

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
    int a[]{44, -15, 45, 67, 89, 66};
    std::cout << "Original data:\n";
    print_content(a);

    // Create a span from a C-style array
    std::span s1{a, std::size(a)};

    // Double the subview/subspan elements created from the first 4 elements of the above s1 span
    scale_2x_content(s1.first(4));
    std::cout << "Double the first 4 elements:\n";
    print_content(a);

    // Double the subview/subspan elements created from the last 3 elements of the above s1 span
    scale_2x_content(s1.last(3));
    std::cout << "Double the last 3 elements:\n";
    print_content(a);
}
