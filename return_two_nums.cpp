#include <tuple>

std::tuple<int, int> divide(int dividend, int divisor) {
    return  {dividend / divisor, dividend % divisor};
}

#include <iostream>

int main() {
    using namespace std;

    auto [quotient, remainder] = divide(14, 3);

    cout << quotient << " , " << remainder << endl;
}