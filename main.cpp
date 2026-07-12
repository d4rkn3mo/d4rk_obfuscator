#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    int key;
    std::cout << "Enter a key( integer 1-255 ): ";
    std::cin >> key;
    std::cin.ignore();

    std::string payload;
    std::cout << "Enter text to obfuscate: ";
    std::getline(std::cin, payload);

    std::cout << "\n[*] Obfuscated byte array: " << std::endl;
    std::cout << "{ ";

    for (size_t i =0; i < payload.length(); i++)
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
    std::cout << "\n\n[*] Done." <<std::endl;
    return 0;
}