// Tik = sodo
// Tak = liho

#include <iostream>
#include <string>

bool sodoStevilo(int stevilo) {
    return stevilo%2 == 0;
}

int main() {
    std::string input = "";

    while (std::cin >> input) {
        if (sodoStevilo(std::stoi(input)))
            std::cout << "Tik";
        else
            std::cout << "Tak";
    }

    return 0;
}