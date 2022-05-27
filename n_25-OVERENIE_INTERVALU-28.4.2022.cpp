/*
        Vytvorte program, ktorý načíta 3 celé čísla: A, B, C a overí, či číslo C patrí do intervalu <A, B> a vypíše výsledok
*/
#include <iostream>
using namespace std;

int main() {

        int A = 0;
        int B = 0;
        int C = 0;

        cin >> A >> B >> C;
        cout << (C<=B && C>=A ? "patrí" : "nepatrí"); 

        return 0;
}
