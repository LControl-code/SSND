#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>


void doSomeWork(std::string name, int pid) {
        const int NUM_TIMES = 5;
        
        for(int i = 0; i < NUM_TIMES; i++){
                sleep(rand() % 4);
                if((int) pid == 0)
                        std::cout << "\t";
                std::cout << "Done pass " << i << " for " << name << std::endl;
        }
        std::cout << std::endl;

}

int main (int argc, char *argv[])
{
        std::cout << "I am: " <<  (int) getpid() << std::endl;

        pid_t pid = fork();

        srand(int(pid));
        
        std::cout << "fork returned: " << (int) pid << std::endl;


        if (pid < 0) {
                std::cerr << "Fork failed" << std::endl;
        }
    
        if (pid == 0) {

                std::cout << "I am the child with pid: " << (int) getpid() << std::endl << std::endl;
                doSomeWork("Child", pid);
                exit(50);
        }

   
                std::cout << "I am the parent, waiting for the child to end\n";
                doSomeWork("Parent", pid);

                int status = 0;
                pid_t childpid = wait(&status);
                std::cout << "Parent knows child " << (int) childpid << " is ending with status " << status << std::endl;

                int childReturnValue = WEXITSTATUS(status);

                std::cout << "\tReturn value is " << childReturnValue;

        return EXIT_SUCCESS;
}

