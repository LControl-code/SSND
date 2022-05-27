#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
        float trajektoria_x = 1000, gravitacne_zrychlenie = 10, vysledok, trajektoria_y = 10, uhol = 25;
        
        int test1 = sqrt(trajektoria_x * trajektoria_x * gravitacne_zrychlenie);
        int test2 = (trajektoria_x * 2 * sin(uhol)) - 2*(trajektoria_y * cos(uhol) * cos(uhol));

        vysledok =  sqrt(trajektoria_x * trajektoria_x * gravitacne_zrychlenie)/ (trajektoria_x * 2 * sin(uhol) -2 * trajektoria_y * cos(uhol) * cos(uhol));
        cout << isnan(vysledok);
        return 0;
}