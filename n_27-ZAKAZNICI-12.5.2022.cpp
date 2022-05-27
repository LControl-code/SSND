 // zakaznici zistovanie najvyssieho nakupu a vypisovanie ich ID
 #include <iostream>
 #include <fstream>
 #define MAX 100
 using namespace std;

 int main() {

         ifstream fin("./zakaznik.txt");
         if(!fin) return 1;
        char const* hello;

         int zakaznik[MAX] = {}, suma[MAX] = {}, pocet = 0, max = 0;

         while(fin >> zakaznik[pocet] >> suma[pocet]) {
                 int i = 0;
                 while(zakaznik[i] != zakaznik[pocet]) i++; // hladanie existencie zakaznika

                 if(i == pocet) // ak nie, tak zapisujeme do toho isteho
                        pocet++;
                else {
                        suma[i] += suma[pocet]; // pridanie ceny do stareho uctu
                }

                if(suma[i] > max){
                        max = suma[i]; // zistovanie max
                }
                 
         }

         cout << "Najvyssia suma: " << max << endl;
         cout << "Pocet zakaznikov: " << pocet << endl;
         cout << "Zakaznici s MAX: ";
         for (int i = 0; i < pocet; i++) {
                 if(suma[i] == max)
                        cout << zakaznik[i] << " ";
         }
         return 0;
 }
