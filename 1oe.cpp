#include <iostream>
#include <string>
#include <sstream>
#include <locale.h>


int countWords(const std::string& text){
    setlocale(LC_ALL,"Russian");
    std::istringstream iss(text);
    std::string word;
    int count = 0;
    while (iss >> word) {
        ++count;
    }
    return count;

}
int main() {
    std::string text;
    std::cout << "введите текст:";
    std::getline(std::cin,text);

    std::cout << "колличество:" << countWords(text) << "\n";
    return 0;
}