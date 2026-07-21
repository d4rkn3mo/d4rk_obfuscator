#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

int main()
{
    int key;
    std::cout << "Enter a key (integer 1-255): ";
    std::cin >> key;
    std::cin.ignore();

    std::cout << "Encode or decode? (e/d): ";
    char mode;
    std::cin >> mode;
    std::cin.ignore();

    if (mode == 'e')
    {
        std::string payload;
        std::cout << "Enter text to obfuscate: ";
        std::getline(std::cin, payload);

        std::cout << "\nObfuscated byte array: " << std::endl;
        std::cout << "{ ";
        for (size_t i = 0; i < payload.length(); i++)
        {
            char current_char = payload[i];
            char obfuscated_char = current_char ^ key;
            std::cout << "0x" << std::hex << (int)(unsigned char)obfuscated_char;
            if (i < payload.length() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << " };" << std::endl;
    }
    else if (mode == 'd')
    {
        std::string hexInput;
        std::cout << "Enter hex bytes (e.g. 5d 42 45): ";
        std::getline(std::cin, hexInput);

        std::istringstream iss(hexInput);
        std::string hexByte;
        std::string decoded;

        while (iss >> hexByte)
        {
            int byteValue = std::stoi(hexByte, nullptr, 16);
            char decoded_char = (char)byteValue ^ key;
            decoded += decoded_char;
        }

        std::cout << "\nDecoded string: " << decoded << std::endl;
    }
    else
    {
        std::cout << "Unknown mode. Use 'e' for encode or 'd' for decode." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
    return 0;
}
