#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream in("average.data");;
    double sum = 0;
    int n = 0;
    std::string s;
    while (std::getline(in, s)) {
        sum += std::stoi(s);
        n++;
    } 

    std::cout << "average = " << sum/n << std::endl;
    std::cout << "n = " << n << std::endl;
}
