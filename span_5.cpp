#include <iostream>
#include <span>
#include <string>
#include <cctype>
#include <stdexcept>

void print_content(std::span<char> container) {
    for(const auto &e : container) {
        std::cout << e;
    }
    std::cout << '\n';
}

void uppersize(std::span<char> container) {
    for(auto &e : container) {
        unsigned char tmp = static_cast<unsigned char>(e);
        if(tmp > 127) {
            throw std::runtime_error("Error! Undefined conversion for non ASCII input strings!");
        }
        e = std::toupper(tmp);
    }
}

int main() {
    std::string site_name{"Solarian Programmer"};
    std::cout << "Original string:\n";
    print_content(site_name);
    std::cout << "Uppersized string:\n";
    uppersize(site_name);
    print_content(site_name);

    std::cout << '\n';

    char site_subtitle[]{"My programming ramblings"};
    std::cout << "Original char*:\n";
    print_content(site_subtitle);
    std::cout << "Uppersized char*:\n";
    uppersize(site_subtitle);
    print_content(site_subtitle);
}
