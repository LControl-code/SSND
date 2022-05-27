#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("pokladne.txt");
    if (!fin) return 1;

    double suma[10] = {}, s;
    int i, pocet[10] = {}, p;
    while (fin >> p >> s)
    {
        if (p < 10)
        {
            suma[p] += s;
            pocet[p]++;
        }
        else
            cout << "Pokladna " << p << " neexistuje!\n";    
    }
    fin.close();
    
    cout << fixed;
    cout.precision(2);
    for (i = 1; i <= 9; i++)
        if (pocet[i])
            cout << "Pokladna c. " << i << " - pocet nakupov: " << pocet[i] << ", suma: " << suma[i] << " EUR\n";
    
    return 0;    
}
