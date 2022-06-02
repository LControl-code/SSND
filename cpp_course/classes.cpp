#include <cstdint>
#include <iostream>
using namespace std;

// creates a class named "Book" with the following attributes:
// - title
// - author
// - pages
// - price
class Book {
  public:
    Book(string title, string author, int pages, double price) {
      this->title = title; // could be without this-->
      this->author = author;
      this->pages = pages;
      this->price = price;
    }

    void print() {
      cout << "Title: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "Pages: " << pages << endl;
      cout << "Price: " << price << endl;
    }

  private:
    string title;
    string author;
    int pages;
    double price;
};
int main() {


  Book book1("The Hobbit", "J.R.R. Tolkien", 295, 25.00);
  Book book2("The Lord of the Rings", "J.R.R. Tolkien", 463, 30.00);
  Book book3("The Catcher in the Rye", "J.D. Salinger", 220, 15.00);
  Book book4("The Grapes of Wrath", "John Steinbeck", 463, 20.00);

  book1.print();
  
  }

  // This is how you create an object of the class "Book"