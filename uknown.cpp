#include <iostream>
#include <cmath>
#include<unistd.h>

using namespace std;

double Input(string req)
{
	bool error;
	double in;

	do
	{
		error = false;
		cout << req;
		cin >> in;
		if (cin.fail() || in <= 0)
		{
			cout << "Vstup nie je validný" << endl;
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == true);

	return in;	
}

int main()
{
	double pi = 3.1415926535897;
	double a;
	double vp;
	const double g = 9.81;
	double tf;
	double rangeX;
	double yMax;
	double L;
	string v;

  cout << fixed;
  cout.precision(2);

	

	// SetConsoleOutputCP(CP_UTF8);
	// setvbuf(stdout, nullptr, _IOFBF, 1000);


	int vyber;

	do
	{
		// system("cls");	

		bool error;
		do
		{
			error = false;
			cout << "Zadajte 1 pre výpočet šykmého vrhu, zadajte 2 pre výpočet potrebného uhlu pre zásah" << endl;
			cin >> vyber;
			if (cin.fail() || !(vyber == 1 || vyber == 2))
			{
				cout << "Vstup nie je validný" << endl;
				error = true;
				cin.clear();
				cin.ignore(80, '\n');
			}

		} while (error == true);

		switch (vyber)
		{
			case 1:				
				vp = Input("Zadajte počiatočnú rýchlosť (m/s): ");
				
				a = Input("Zadajte uhol výstrelu (v stupňoch): ");
				a = a * pi / 180;

				double t;

				tf = (2 * vp * sin(a)) / g;								//cas letu
				rangeX = (2 * vp * vp * sin(a) * cos(a)) / g;				//vzdialenost dopadu
				yMax = (pow(vp * sin(a), 2)) / (2 * g);					//max vyska
				L = (pow(vp, 2) / g) * (sin(a) + pow(cos(a), 2) * atanh(sin(a)));	//dlzka krivky / trajektorie strely

				cout << "\nČas letu je " << tf << " [s]" << endl;
				cout << "Vzdialenosť dopadu od bodu výstrelu je " << rangeX << " [m]" << endl;
				cout << "Maximálna výška letu je " << yMax << " [m]" << endl;
				cout << "Dĺzka dráhy letu je " << L << " [m]." << endl;

				do
				{		
					t = Input("\nZadajte čas od výstrelu strely o ktorej chcete bližšie informácie(s): ");

					if (t <= tf)
					{
						double vt = sqrt(pow(vp * cos(a), 2) + pow(vp * sin(a) - g * t, 2));
						double yt = vp * t * sin(a) - (g * t * t / 2);
						double xt = vp * t * cos(a);

						cout << "\nRýchlosť v čase " << t << " [s] od vystrelenia je " << vt << " [m/s] a výška je " << yt
							<< " [m] horizontálna vzdialenosť od bodu výstrelu je " << xt << " [m]." << endl;
					}

				} while (t > tf);
				break;

			case 2:
				double X, Y, D;
				vp = Input("Zadajte počiatočnú rýchlosť (m/s): ");
				
				bool error;
				do
				{
					error = false;
					cout << "Zadajte pozíciu bodu ktorý chcete trafiť v metroch [X Y]: ";
					cin >> X >> Y;
					if (cin.fail() || X <= 0 || Y <= 0)
					{
						cout << "Vstup nie je validný" << endl;
						error = 1;
						cin.clear();
						cin.ignore(80, '\n');
					}

				} while (error == true);

				D = pow(vp, 4) - g * (g * X * X + 2 * Y * vp * vp);

				if (X > 0 && Y >= 0 && D >= 0)
				{
					if (D > 0)
					{
						a = atan((vp * vp + sqrt(D)) / (g * X));
						a = a * 180 / pi;
						cout << "Prvý možný uhol výstrelu: " << a << "°" << endl;

						a = atan((vp * vp - sqrt(D)) / (g * X));
						a = a * 180 / pi;
						cout << "Druhý možný uhol výstrelu: " << a << "°" << endl;
					}
					else
					{
						a = atan((vp * vp) / (g * X));
						a = a * 180 / pi;
						cout << "Jediný možný uhol výstrelu: " << a << "°" << endl;
					}
				}
				else cout << "Pozícia nie je validná!" << endl;

				break;

			default:
				cout << "Nesprávny výber!" << endl;
				break;

		}

		cout << "Chcete pokračovať [a/n]: ";
		
		cin >> v;

	} while (v == "a");
	
	
	

	return 0;
}