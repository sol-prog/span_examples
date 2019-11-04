#include <iostream>
#include <span>
#include <iterator>
#include <algorithm>

void print_content(std::span<int> container) {
    for(const auto &e : container) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
}

int main() {
    int a[]{44, 45, -15, 89, 6, 66};
    std::cout << "Original data:\n";
    print_content(a);

    // Create a span from a C-style array
    std::span s1{a, std::size(a)};

    // Create and print a subspan from the above s1 span without the first and last elements:
    std::span s2{s1.subspan(1, s1.size() - 2)};
    std::cout << "Subspan/subview from the original data without the first and last elements:\n";
    print_content(s2);

    // Sort the s2 subspan and print the sorted subspan and the original data:
    std::sort(s2.begin(), s2.end());
    std::cout << "Sorted subspan:\n";
    print_content(s2);
    std::cout << "Original data, partially sorted:\n";
    print_content(a);
}
