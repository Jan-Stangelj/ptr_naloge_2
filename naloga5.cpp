#include <iostream>
#include <string>

int main() {
    int width = 0;
    int height = 0;

    std::cin >> height >> width;

    int minX = width;
    int maxX = 0;
    int minY = height;
    int maxY = 0;

    std::cin.ignore();

    for (unsigned int y = 0; y < height; y++) {
        std::string vrstica;
        std::getline(std::cin, vrstica);
        
        if (vrstica.find_first_of('#') < minX && vrstica.find('#') != std::string::npos)
            minX = vrstica.find_first_of('#');

        if (vrstica.find_last_of('#') > maxX && vrstica.find('#') != std::string::npos)
            maxX = vrstica.find_last_of('#');

        if (vrstica.find('#') != std::string::npos && y < minY)
            minY = y;

        if (vrstica.find('#') != std::string::npos && y > maxY)
            maxY = y;
    }

    int obseg = (maxX - minX +1)*2 + (maxY-minY+1)*2;

    std::cout << obseg;

    return 0;
}