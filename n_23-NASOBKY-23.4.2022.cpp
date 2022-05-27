#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	for (a; a <= b; a++){
		if(a % c == 0){
			cout << a << " ";
		}
	}
	return 0;
}
