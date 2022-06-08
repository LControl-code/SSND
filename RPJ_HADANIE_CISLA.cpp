/*************************************************************
Random number guessing game 1.0
Author: Adam Stratilik, 2022
Gmail: adam.stratilik@student.ssnd.sk

Changes:
12-01-2022: Adam Stratilik: Initial program
14-03-2022: Adam Stratilik: Bigger improvements
************************************************************ */
#ifdef _WIN32
#include <Windows.h> // sleep for windows
#else
#include <unistd.h> // sleep for Linux
#endif

#include <iostream> //input and output (cin, cout)
#include <ctime>    // used for the srand and rand function
using namespace std;

namespace tools {

    void handler() {
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "\nZadané číslo je buď moc veľké/malé. Možno ste použili neznámy znak.\nOpakujte Váš pokus, prosím.\n\n" << endl;
    }

    bool statement_handler(int option, int handler_min, int handler_max) {
        bool resolve = false;

        if (option < handler_min || option > handler_max){
            resolve = true;
        }
        return resolve;
    }
    void clear_screen() {
        cout << "\033[2J\033[1;1H";
        cout.flush();
    }

    namespace headers {
        void greeting(int a) {
            if( a == 1){
                cout << "    .-\"^`\\                                        /`^\"-\n";
                cout << "  .'   ___\\                                      /___   `.\n";
                cout << " /    /.---.                                    .---.\\    \\\n";
                cout << "|    //     '-.  ___________________________ .-'     \\\\    |\n";
                cout << "|   ;|         \\/--------------------------//         |;   |\n";
                cout << "\\   ||       |\\_)        Arch Linux        (_/|       ||   /\n";
                cout << " \\  | \\  . \\ ;  |     Enterprise Linux     || ; / .  / |  / \n";
                cout << "  '\\_\\ \\\\ \\ \\ \\ |                          ||/ / / // / _/'\n";
                cout << "        \\\\ \\ \\ \\|      Guess game 1.0      |/ / / //\n";
                cout << "         `'-\\_\\_\\     Codename RPJ-ZAP     /_/_/-'`\n";
                cout << "                '--------------------------'" << endl;
            }

            if (a == 2) {
                cout << "__     _____ _____  _       _ _____ _____ _\n";
                cout << "\\ \\   / /_ _|_   _|/ \\     | |_   _| ____| |\n";
                cout << " \\ \\ / / | |  | | / _ \\ _  | | | | |  _| | |\n";
                cout << "  \\ V /  | |  | |/ ___ \\ |_| | | | | |___|_|\n";
                cout << "   \\_/  |___| |_/_/   \\_\\___/  |_| |_____(_) \n" << endl;
            }

        }
        void goat_talk(){
            tools::clear_screen();
            cout << "\n ___________\n";
            cout << "< Nesprávne >\n";
            cout << " -----------\n";
            cout << "        \\   ^__^\n";
            cout << "         \\  (oo)\\_______\n";
            cout << "            (__)\\       )\\/\\\n";
            cout << "                ||----w |\n";
            cout << "                ||     ||" << endl;
        }

        void computer_talk(int rel_number){
            cout << "\n       ___________\n";
            cout << "      |.---------.|\n";
            cout << "      ||         ||\n";
            cout << "      ||   " << rel_number << "    ||\n";
            cout << "      ||         ||\n";
            cout << "      |'---------'|\n";
            cout << "       `)__ ____('\n";
            cout << "       [=== -- o ]\n";
            cout << "       '---------'" << endl;
        }
    }

}

int main()
{
    srand(time(0)); // so that the rand gives always random numbers
    unsigned short Rand_Number = 0, Guess_num = 0, Tries_var_num = 1, diff_R_G = 0, life = 3, Guess_All[4] = {}, i = 0, min_machine = 0, max_machine = 0; 
    // vsetko mame zadefinovane aby sa preslo problemom

    // system vytvorenia, nazov projektu a codename
    tools::headers::greeting(1);
    sleep(3);
     // funguje pre Linux aj pre Windows
    tools::clear_screen();
        // toto nizsie by som vyuzil, no existuje a jednoduchsia cesta
        // #ifdef WIN32
        // system("cls");
        // #endif
        // #ifdef linux 
        // system("clear");
        // #endif

    // privitanie
    tools::headers::greeting(2);
    cout << "Nachádzate sa v hre \"Hádaj na aké číslo myslím\"\nVašou úlohu je uhádnuť náhodné číslo, pokým máte stále životy\nalebo naopak, nechať počítač hádať vaše náhodné číslo.\n";
    cout << "Predtým budeme samozrejme potrebovať pár nastavení, pre Váš optimálny zážitok." << endl;
    sleep(10); // nezabudni vypnut po testovani

    // pretty dots >:DDD
    for(int dot_time = 1; dot_time <= 3; dot_time++) {
        cout << "•\n";
        sleep(1);
    }
    
    int option_pc_human = true;    
    tools::clear_screen();
    cout << "Prajete si hádať číslo (1) alebo by ste radšej nechali hádať číslo počítač (0)? [1 / 0] ";
    cin >> option_pc_human;

    while (cin.fail() || tools::statement_handler(option_pc_human, 0, 1)){
        tools::handler();
        cout << "[ hádať (1) / počítač (0) ] ";
        cin>>option_pc_human;
        tools::clear_screen();
    }

    cout << "Výborne, mód hry ste vybrali!\n\nTeraz Vás požiadame aby ste zadali interval v ktorom sa bude hádať (2 celé čísla) <a; b> ";
    cin >> min_machine >> max_machine;
    while(cin.fail())
    {
        tools::handler();
        cout << "<a; b> ";
        cin >> min_machine >> max_machine;
        tools::clear_screen();
    }
    Rand_Number = min_machine + rand() % (max_machine - min_machine + 1); 
    cout << "Ďakujeme za trpezlivosť, užite si Vašu hru :)\n";
    tools::clear_screen();

    // rozdelovanie programu na 2, dal by som to do viacerych suborov no to by nebolo vyhodne pre prezentovanie na inom pc
    switch (option_pc_human)
    {
    case 1:
    {
        cout << "Na aké číslo myslím? \nPomôcka: zadávajte interval od " << min_machine << " - " << max_machine <<" (len celé čísla)\nMáte 3 životy\n- Za každý zlý pokus sa Vám odoberie 1 život, ak sa vytratia všetky, hra končí.\n\n";

        do
        {
        // selection:
                // tools::clear_screen();
            cout << "Tip: ";
            cin >> Guess_num;

            while (cin.fail() || tools::statement_handler(Guess_num, min_machine, max_machine)) // stopping humans from entering a number too big -- predtym som mal "abs(Guess_num) > (2 ^ 16) / 2"
            {
                tools::clear_screen();
                tools::handler(); // ignoruje 100 riadkov čo by používateľ zadal, je ich 100 pretože nikomu by sa nechcelo písať 100 riadkov niečoho aby pokazil program..
               cout << "Tip: ";
               cin >> Guess_num;
                // goto selection; // viem ze by sme ho nemali pouzivat ale tu je to vyhodne
            }

            diff_R_G = abs(Rand_Number - Guess_num); // changes the diff of R and G to a positive integer

            if (Guess_num <= max_machine && Guess_num >= min_machine)   // goes trough an interval
            {
                Guess_All[i] = Guess_num; // zapisat miesto v array na kazdy pokus

                if (Guess_num == Rand_Number) // we suppose they guessed the number first
                {
                    tools::clear_screen();
                    cout << "\nGratulujem Vám, uhádli ste moje číslo.\n";

                    if (Tries_var_num >= 5 && Tries_var_num <= 10 || Tries_var_num == 0) // len kvôli skloňovaniu, nepotrebné
                    {
                        cout << "Uhádli ste ho na " << Tries_var_num << " pokusov.";
                    }
                    else if (Tries_var_num > 1)
                    {
                        cout << "Uhádli ste ho na " << Tries_var_num << " pokusy.";
                    }
                    else
                    {
                        cout << "Uhádli ste ho na " << Tries_var_num << " pokus.";
                    }
                    cout << "\nOstali Vám " << life << " životy\nVaše odhady boli: ";
                    for (int i = 0; i < Tries_var_num; i++)
                    {
                        cout << Guess_All[i] << "  ";
                    }
                    break;
                }
                life--;
                i++;
                if (life <= 0) // also there are lives, if it drops to -1, the game ends
                {
                    tools::clear_screen();
                    cout << "Nesprávny odhad.\nVypršali Vám už životy, budete musieť, bohužiaľ, opakovať hru odznova.\n\n";
                    cout << "Myslel som si číslo: " << Rand_Number;
                    return 0;
                }

                // cout << "Nesprávny odhad, skús znova.\n";
                // cout << "- život\n";
                switch (diff_R_G) // different cases for the distance of the diif between R and G
                {
                case 1:
                case 2:
                    if (Rand_Number - Guess_num > 0)
                    {
                        tools::headers::goat_talk();    
                        cout << "- si nižšie \n- Priam horíš.\n";
                    }
                    else
                    {
                        tools::headers::goat_talk();    
                        cout << "+ si vyššie \n- Priam horíš.\n";
                    }

                    break;

                case 3:
                    if (Rand_Number - Guess_num > 0)
                    {
                        tools::headers::goat_talk();    
                        cout << "- si nižšie \n- Prihorieva.\n";
                    }
                    else
                    {
                        tools::headers::goat_talk();    
                        cout << "+ si vyššie \n- Prihorieva.\n";
                    }
                    break;

                default:
                    if (Rand_Number - Guess_num > 0)
                    {
                        tools::headers::goat_talk();    
                        cout << "- si nižšie \n- Malý tip: moje číslo je 4 alebo viac čísel od tvojho odhadu.\n";
                    }
                    else
                    {
                        tools::headers::goat_talk();    
                        cout << "+ si vyššie \n- Malý tip: moje číslo je 4 alebo viac čísel od tvojho odhadu.\n";
                    }
                    break;
                }
                ++Tries_var_num;
                cout << "- život\n\n";
                // sleep(2);
            }
            else
            {
                tools::clear_screen();
                cout << "Číslo nie je v zadanom intervale, opakujte svoj pokus.\n\n";
            }

        } while (Rand_Number != Guess_num); // repeat it
            break;
    }
    case 0: 
    {
        int rel_number, tries_machine = 0;
        char choice_evaluation, choice_number_position;
        cout << "V tejto hre Vám budu prezentované čísla počítačom a pomocou volieb bude počítač hľadať vaše číslo.\nJednoduché, nie?\n";
        do
        {
            rel_number = max_machine + (min_machine - max_machine) / 2; // algorythmus

            // cout << "Je vaše číslo " << rel_number << "? [y / n] "; // operation

            tools::headers::computer_talk(rel_number);
            cout << "\nJe " << rel_number <<" vaše číslo? [ y / n ] ";
            cin >> choice_evaluation;

            while(cin.fail() || choice_evaluation != 'y' && choice_evaluation != 'n')
            {
                tools::clear_screen();
                tools::handler();
                cout << "[ y / n ] ";
                cin >> choice_evaluation;
            }

            tries_machine++; // pocet pokusov
            if (choice_evaluation == 'y')
                break;

            cout << "\nJe " << rel_number << " väčšie alebo menšie od Vášho čísla ? [+ / -] ";
            cin >> choice_number_position;

            while(cin.fail() || choice_number_position != '-' && choice_number_position != '+')
            {
                tools::handler();
                cout << "[ + / - ] ";
                cin >> choice_number_position;
                tools::clear_screen();
            }

            if (choice_number_position == '-')
                min_machine = rel_number;

            else
                max_machine = rel_number;
            
            tools::clear_screen();
        } while (choice_evaluation == 'n');
        tools::clear_screen();
        cout << "\n\nŤažké číslo, no uhádol som ho!\n";
        cout << "Vaše číslo bolo: " << rel_number << "\nPočítač ho uhádol na " << tries_machine << " pokusov";

        break;
        }
        default:
        {
            cerr << "Niečo sa pokazilo, ups...";
            break;
        }
        
    }

    return 0;
}

// This code is contributed by Adam Stratilik
