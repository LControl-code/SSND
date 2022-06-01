#include <ios>
#include <iostream>
using namespace std;

class Book { // class declaration
public: // public members of the class are accessible from outside the class
  Book(string title, string author, int pages, double price, int sold, int available) {
    // constructor of the class
    this->title = title; // (this-> is a pointer to the object of the class "Book")
    this->author = author; // it
    this->pages = pages;
    this->price = price;
    this->sold = sold;
    this->available = available;
  }

  void print() { // method declaration (object function)
    cout << "* " << title << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Pages: " << pages << endl;
    cout << "Price: " << price << endl;
    cout << "Sold: " << sold << endl;
    cout << "Available: " << available << (available>0 ? " (in stock)" : " (out of stock)") << endl;

    cout << endl;
  }

private: // private attributes (variables)
  string title;
  string author;
  int pages;
  double price;
  int sold;
  int available;
};

int main() { // main function that runs the program and calls the class and its functions

  Book book1("The Hobbit", "J.R.R. Tolkien", 295, 25.00, 15, 100);
  // object creation
  Book book2("The Lord of the Rings", "J.R.R. Tolkien", 463, 30.00, 2, 20);
  // the constructor is called automatically, it takes the
  // values from the parameters and assigns them to the private
  // attributes of the class
  Book book3("The Catcher in the Rye", "J.D. Salinger", 220, 15.00, 50, 0);
  Book book4("The Grapes of Wrath", "John Steinbeck", 463, 20.00, 11, 10);

  book1.print();
  book2.print();
  book3.print();
  book4.print();
  return 0;
}