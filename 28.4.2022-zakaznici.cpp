#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
        ifstream zakaznik("./ZAP/zakaznik.txt");
        if(!zakaznik){
                return 1;
        }
        vector<int> z_id(100);
        vector<int> u_list(100);

        int pocet = 0;
        int max = 0;

        while(zakaznik >> z_id[pocet] >> u_list[pocet]) {
                max = (u_list[pocet] > max ? u_list[pocet] : max);
                pocet++;
        }

        for(;pocet; pocet--) {
                if(u_list[pocet] == max){
                        cout << "ID: "<< z_id[pocet] << endl;
                }
        }

        return 0;
}