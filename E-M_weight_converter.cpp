#include <iostream>
#include <iomanip>
using namespace std;

int E_Mcalculator()
{
    double weightE = 0.1, weightM = 0.1;
    std::cout << "Enter a weight of something you like (in kg): ";
    std::cin >> weightE;
    weightM = weightE / 2.66;
    std::cout << "Your item would weight " << fixed << setprecision(2) << weightM << " kg on Mars.\n";
    return weightM;
}

int M_Kconverter()
{
    double mil = 0, km = 0;
    std::cout << "Enter a distance in miles: ";
    std::cin >> mil;
    km = mil * 1.60934;
    std::cout << "That is " << fixed << setprecision(2) << km << " km in distance.";
    return km;
}

int main()
{
    E_Mcalculator();
    M_Kconverter();
    return 0;
}