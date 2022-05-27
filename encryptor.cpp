/* ************************************************************
Password Encryptor 1.0
Author: Adam Stratilik, 2022
 email: adam.stratilik@student.ssnd.sk

Changes:
2022-02-11: Adam Stratilik: Initial program

TO-DO:
Make it harder to reverse your passwords
************************************************************ */
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    time_t now = time(0);
    char* date = ctime(&now);

    ofstream pwd;
    ifstream raw;
    pwd.open("./Work_Fun/encryption-raw.txt", ios::app);
    raw.open("./Work_Fun/encryption.txt");
    string array[93] = {}, string_value;
//     int i = 0;

    for (int i = 0; !raw.eof(); i++) {
        raw >> array[i];
    }
//     while(raw >> array[i]) {
//             raw >> array[i];
//             i++;
//     }

    cout << "Zadajte slovo alebo vetu na zabezpečenie (bez medzier): ";
    cin >> string_value;

    char str_var[string_value.length()] = {};
    system("clear");

    cout << "Vaše zabezpečené heslo je: ";
    pwd << "\nEncrypted password: ";

    for (int i = 0; i < string_value.length(); i++) {
        str_var[i] = string_value[i];
        cout << array[static_cast<int>(str_var[i]) - 33];
        pwd << array[static_cast<int>(str_var[i]) - 33];
    }

    pwd << "\t" << date << endl;
    pwd << "Original password: ";

    for (int i = 0; i < string_value.length(); i++) {
        pwd << static_cast<int>(str_var[i]) << ".";
    }

    pwd << "\n\n";
    pwd.close();
    return 0;
}
