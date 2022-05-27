#include <iostream>
using namespace std;

class Book { // is the blueprint for an object, object is the instance, the physical thing
        public:
                string title;
                string author;
                int pages;
};

int main() {

        Book book1;
        book1.title = "Nothing can hurt me";
        book1.author = "Anonymous";
        book1.pages = 500;

        cout << book1.pages << endl;    

        Book book2;
        book2.title = "Harry Potter";
        book2.author = "Anonymous";
        book2.pages = 700;

        cout << book2.author << endl;
        
        return 0;
}