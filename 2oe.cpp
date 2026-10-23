#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale.h>
bool isPalindrome(const std::string& text) {
    std::string cleaned;
    for (char c : text) {
        if(std::iswalnum(static_cast<unsigned char>(c))){
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }
    std::string reversed = cleaned;
    std::reverse(reversed.begin(),reversed.end());
    return cleaned == reversed;
}
int main() {
    setlocale(LC_ALL,"Russian");
    std::string tests[] = {
        "а роза упала на лапу азора",
        "Madam, i'm Adam",
        "12321",
        "racecar",
        "Hello,World!"

    };
    for (const auto& text : tests){
        std::cout << "'" << text << "' - "
                  << (isPalindrome(text) ? "палидром" : "не палидром")
                  << "\n";
    }
    return 0;
}
