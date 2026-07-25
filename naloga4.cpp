#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> osnovneStevke = {"", "ena", "dve", "tri", "stiri", "pet", "sest", "sedem", "osem", "devet", "deset", "enajst", "dvanajst", "trinajst", "stirinajst", "petnajst", "sesnajst", "sedemnajst", "osemnajst", "devetnajst", "dvajset"};
    std::vector<std::string> desetice = {"", "deset", "dvajset", "trideset", "stirideset", "petdeset", "sestdeset", "sedemdeset", "osemdeset", "devetdeset"};
    std::vector<std::string> stotice = {"", "sto", "dvesto", "tristo", "stiristo", "petsto", "seststo", "sedemsto", "osemsto", "devetsto"};

    int stevilka = 0;
    std::string stevilkaStr;
    std::cin >> stevilka;
    stevilkaStr = std::to_string(stevilka);

    if (stevilka < 0 || stevilka > 999) {
        std::cerr << "ERROR: number in invalid range, terminating program\n";
        return -1;
    }

    if (stevilka == 0) {
        std::cout << "nic\n";
        return 0;
    }

    if (stevilka > 99) {
        int stotica = stevilkaStr.at(0) - '0';
        int desetica = stevilkaStr.at(1) - '0';
        int enica = stevilkaStr.at(2) - '0';

        std::cout << stotice.at(stotica);

        if (desetica > 0 && enica > 0) {
            std::cout << ' ' << osnovneStevke.at(enica) << "in" << desetice.at(desetica) << '\n';
            return 0;
        }

        if (desetica > 0)
            std::cout << ' ' << desetice.at(desetica) << '\n';

        if (enica > 0)
            std::cout << ' ' << osnovneStevke.at(enica) << '\n';

        return 0;
    }

    if (stevilka > 20) {
        int desetica = stevilkaStr.at(0) - '0';
        int enica = stevilkaStr.at(1) - '0';

        if (desetica > 0 && enica > 0) {
            std::cout << osnovneStevke.at(enica) << "in" << desetice.at(desetica) << '\n';
            return 0;
        }

        if (desetica > 0)
            std::cout << desetice.at(desetica) << '\n';

        return 0;

    }

    std::cout << osnovneStevke.at(stevilka) << '\n';

    return 0;

}