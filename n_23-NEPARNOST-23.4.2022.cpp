#include <iostream>
using namespace std;

int main(){
	int num, pocet,parne = 0, neparne = 0;
	cin >> pocet;
	
	for (int i = 1; i <= pocet; i++){
		cin >> num;
		if (num % 2 == 0)
			parne++;
		else if (num % 2 != 0)
			neparne++;
	}
	
	if (parne > neparne)
		cout << "viac je parnych";
	else if (neparne > parne)
		cout << "viac je neparnych";
	else if (parne == neparne)
		cout << "rovnako";
	return 0;
}
