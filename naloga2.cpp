#include <iostream>
#include <string>

int main() {
    thread_local std::string samoglasniki = "aeiou";

    std::string input = "";
    std::cin >> input;

    int moc = 0;

    for (int i = 0; i < input.length(); i++) {
        for (int j = 0; j < samoglasniki.length(); j++) {
            if (input.at(i) == samoglasniki.at(j))
                moc++;
        }
    }

    std::cout << moc << '\n';

    return 0;
}