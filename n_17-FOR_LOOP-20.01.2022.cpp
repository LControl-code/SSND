#include <iostream>
using namespace std;

int main()
{
    int s, j, p;
    cin >> s >> r;
    j = 1;
    cout << endl;
    stvorec
    for (int s = 1; s <= n; s++)
    {
        for (int r = 1; r <= p; r++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    trojuholnik
    for (int s = 1; s <= n; s++)
    {
        for (int r = 1; r <= j; r++)
        {
            cout << "* ";
        }
        cout << endl;
        j--;
    }
    
            /*
            nepodarene obdlznik
            for (int i = 1; i <= n; i++)
            {
                for (int e = 1; e <= j; e++)
                {

                    cout << "* ";
                    if (n - 2 != 0)
                    {
                        cout << "* ";
                    }
                    for (int r = 1; r <= n - 2; r++)
                    {
                        cout << " ";
                    }
                    j++;
                    if (j == n)
                    {
                        for (int e = 1; e <= j; e++)
                        {

                            cout << "* ";
                        }
                    }
                    cout << "*" << endl;
                }
            */
    
    for (int i = 0; i <= s; i++)
    {

        for (int r = 0; r <= p; r++)
        {
            if (i == 0 || r == p ||)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
    }

    return 0;
}
