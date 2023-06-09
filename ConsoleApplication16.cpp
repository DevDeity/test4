#include <iostream>
#include <string>

std::string decimalToBinary(int decimal) {
    std::string binary;

    while (decimal > 0) {
        int bit = decimal % 2;
        binary = std::to_string(bit) + binary;
        decimal = decimal >> 1;
    }

    return binary;
}

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int base = 1;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base = base << 1;
    }

    return decimal;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int conversionType;
    std::cout << "Выберите направление конверсии (10 -> 2: 1, 2 -> 10: 2): ";
    std::cin >> conversionType;

    if (conversionType == 1) {
        int number;
        std::cout << "Введите число для конверсии: ";
        std::cin >> number;
        std::string result = decimalToBinary(number);
        std::cout << "Результат конверсии: " << result << std::endl;
    }
    else if (conversionType == 2) {
        std::string binary;
        std::cout << "Введите двоичное число для конверсии: ";
        std::cin >> binary;
        int result = binaryToDecimal(binary);
        std::cout << "Результат конверсии: " << result << std::endl;
    }
    else {
        std::cout << "Некорректный выбор направления конверсии." << std::endl;
    }

    return 0;
}
