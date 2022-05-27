#include <iostream>
#include <string>
std::string doubleChar(std::string str) {
	// x y // x, 2, xx => r = y >> yy => r = e ...
	std::string back;
	for(int i=0; i <= str.length(); i++){
//		char r = str[i+1];
//		str[i+1] = str[i];
		for(int e=0; e<2; e++)
		back[i+e] += str[i];
	}
    std::cout << back;
    return back;
}
int main(){
    doubleChar("Hello");
    return 0;
}