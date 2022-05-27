// DO NOT ATTEMPT TO RUN THIS!!!! 
// YOUR COMPUTER MAY COMPLETELY RUN OUT OF MEMORY
// AND FAIL TO WORK 
#include <iostream>
#include <unistd.h>


int main() {

        char answer = '\0';
        bool doom_bool = false;
        std::cout << "You are about to run a fork bomb on your computer, you are acquainted with that, right..." << std::endl;
        std::cout << "Do you want to continue? Your computer may not work after this. \n[Y/n] ";
        std::cin >> answer;
                
        switch(answer) {
                case 'Y' :
                case 'y' :
                {
                        doom_bool = true;
                        break;
                }
                case 'n' :
                case 'N' :
                {
                        doom_bool = false;
                        break;
                }
                default :
                {
                        return 0;
                }
        }

        if(doom_bool) {
                std::cout << "\nOh no...\n" << std::endl;
                sleep(10);
                std::cout << "It was nice knowing ya, now it's time to die..." << std::endl;
                sleep(3);
                system("clear");
                sleep(5);

                std::cout << "BWARH, I'M DIEING!!! WHAT HAVE YOU DONE, YOU FOOL" << std::endl;
                sleep(2);
                system("clear");

                for(int i = 10; i; i--) {
                        std::cout << "BWARH, I'M DIEING!!! WHAT HAVE YOU DONE, YOU FOOL" << std::endl;
                        std::cout << "Destruction in " << i << std::endl;
                        sleep(1.1);
                        system("clear");
                }
                std::cout << "LOL, just a joke, if you wan't to know how it's done, look into the source code" << std::endl;
                if(doom_bool == 2038923)
                        {
                                /*
                                        doom_bool = false;
                                        while(doom_bool) {
                                                // fork(); // don't even think about running it you moron. 
                                        }
                                */
                        }
        }

        return 0;
}