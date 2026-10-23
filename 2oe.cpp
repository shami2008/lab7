#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale.h>

bool isPalindrome(const std::string& text) {
    // Строка для хранения "очищенного" текста:
    std::string cleaned;
    // Проходим по каждому символу исходной строки.
    for (char c : text) {
        if(std::iswalnum(static_cast<unsigned char>(c))){
            // Если символ подходит — добавляем его в нижнем регистре
            // в "очищенную" строку.
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
        // Все остальные символы (пробелы, знаки препинания, апострофы)
        // просто игнорируются.
    }
    // Создаём копию очищенной строки для получения её перевёрнутой версии.
    std::string reversed = cleaned;
    // Разворачиваем строку задом наперёд с помощью std::reverse.
    std::reverse(reversed.begin(),reversed.end());
    // Сравниваем оригинал (без лишних символов) с его перевёрнутой копией.
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

    // Проходим по всем тестовым строкам.
    for (const auto& text : tests){
        // Выводим исходную строку в кавычках, затем результат проверки.
        std::cout << "'" << text << "' - "
                  << (isPalindrome(text) ? "палидром" : "не палидром")
                  << "\n";
    }
    return 0;
}
