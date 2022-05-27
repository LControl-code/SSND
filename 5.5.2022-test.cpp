// vytvorte program, ktory nacita dve hodnoty, kolko ziakov chodi do triedy a druha, kolko deti dany den chyba, vypocita percentualnu ucast na hodine
#include <iostream>
using namespace std;

int main(void) {

        int deti = 0;
        int chyba_deti = 0;

        cout << "Zadajte pocet deti v triede: ";
        cin >> deti;
        cout << "Chyba: ";
        cin >> chyba_deti;

        cout << fixed;
        cout.precision(2);
        
        cout << "Ucast v triede: " << (float(chyba_deti) / deti)*100 << "% dochadzka" << endl;


        return 0;
}