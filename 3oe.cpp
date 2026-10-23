#include <iostream>
#include <string>
#include <locale.h>

std::string caesarCipher(const std::string& text,int shift){
    std::string result = text;
    for (char& c : result){
        if (std::isalpha(static_cast<unsigned char>(c))){
            char base = std::isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
            c= (c - base + shift %26 + 26)%26 + base;
        }
    }
    return result;
}
int main() {
    setlocale(LC_ALL,"Russian");
    std::string original = "Hello World!";
    std::string encrypted = caesarCipher(original,3);
    std::string decrypted = caesarCipher(original,-3);

    std::cout << "Оригинал:" << original << "\n";
    std::cout <<"Зашифровано:" << encrypted << "\n";
    std::cout << "Расшифровано:" << decrypted << "\n";

    return 0;
}
