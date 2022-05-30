// #include <iostream>
// using namespace std;
// int addition(int a, int b) {
// 	cin>>a>>b;
// 	return a + b;
// }
// int main() {
//     int a, b;
//     addition(a,b);
//     return 0;

// }
#include <iostream>
#include <string>
// #include <vector>
// #include <algorithm> what even is this????

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

// int main()
// {
//     string s;
//     char min = 'z';
//     getline(cin, s);

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] <= min && int(s[i])>=65){
//             min = s[i];
//         }

//     }

//     for(int i = 0; i < s.length(); i++)
//     {
//         if (s[i] != min)
//             cout << s[i];
//     }
// }
// function that return the number of odd numbers
int odd_count(long long n) {
  // return n/2; // is also the number of even numbers
  return n / 2; // is the number of odd numbers rounded down
}
int main() { odd_count(101285326932); }