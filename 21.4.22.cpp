#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream pokladna("./fstream/items/pokladne/pokladne.txt");
    float suma1 = 0.0, suma2 = 0.0, suma3 = 0.0, p  = 0, s = 0, pocet1 = 0, pocet2 = 0, pocet3 = 0;
    vector<double> suma(3);
    vector<int> pocet(3);
    while (pokladna >> p >> s)
    {  
            
        if(p <= 3) {
            suma[s] += s;
            pocet[p]++;
        }
        else {
            cout << "Pokladna " << p << " neexistuje";
        }
    }
    for (int i = 0; i < pocet1; i++)
    return 0;
}
