/* ************************************************************
Password Decryptor 1.0
Author: Adam Stratilik, 2022
 email: adam.stratilik@student.ssnd.sk

Changes:
2022-02-11: Adam Stratilik: Initial program
************************************************************ */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    std::ifstream raw;
    raw.open("./Work_Fun/encryption.txt");
    string array[93] = {}, string_encrypted;
    for (int i = 0; !raw.eof(); i++)
    {
        raw >> array[i];
    }

    cout << "Zadajte vaše zabezpečené heslo: ";
    cin >> string_encrypted;
    string str_encrypted[string_encrypted.length() / 4] = {};
    system("clear");
    for (int i = 0; i < string_encrypted.length(); i += 4)
    {
        str_encrypted[i / 4] = string_encrypted.substr(i, 4);
    }

    cout << "Vaše pôvodné slovo bolo: ";

    for (int e = 0; e < string_encrypted.length() / 4; e++)
        for (int i = 0; i <= 126; i++)
        {
            if (str_encrypted[e] == array[i])
                cout << static_cast<char>(i + 33);
        }
    return 0;
}
