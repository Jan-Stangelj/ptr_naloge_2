#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

void simulacija(int usi, std::vector<int>& sprememba, unsigned int i) {
    if (usi >= 1 && usi <= 3) {
        sprememba.at(i) += 1;
    }
    else if (usi >= 5) {
        if (i == sprememba.size() - 1) {
            int polovica = std::ceil(float(usi)/2);
            sprememba.at(i) -= polovica;
            sprememba.at(0) += polovica - 1;
            return;
        }

        int polovica = std::ceil(float(usi)/2);
        sprememba.at(i) -= polovica;
        sprememba.at(i+1) += polovica;
    }
}

void resetSpremembe(std::vector<int>& spremembe) {
    for (int i = 0; i < spremembe.size(); i++) {
        spremembe.at(i) = 0;
    }
}

void applySpremembe(std::vector<int>& rezultat, const std::vector<int>& spremembe) {
    for (int i = 0; i < rezultat.size(); i++) {
        rezultat.at(i) += spremembe.at(i);
        rezultat.at(i) = std::max(rezultat.at(i), 0);
    }
}

int main() {
    std::string input = "";
    std::getline(std::cin, input);

    std::vector<int> usi;
    std::vector<int> spremembe;

    // pretvori input v array stevilk
    std::string temp;
    std::stringstream tempStream(input);
    while (tempStream >> temp) {
        usi.push_back(std::stoi(temp));
        spremembe.push_back(0);
    }

    unsigned int dnevi = 0;
    std::cin >> dnevi;

    resetSpremembe(spremembe);

    for (unsigned int i = 0; i < dnevi; i++) {

        for (unsigned int j = 0; j < usi.size(); j++)
            simulacija(usi.at(j), spremembe, j);

        applySpremembe(usi, spremembe);
        resetSpremembe(spremembe);
    }

    for (unsigned int i = 0; i < usi.size(); i++) {
        std::cout << usi.at(i) << ' ';
    }

    return 0;
}