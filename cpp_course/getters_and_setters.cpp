#include <iostream>
using namespace std;

// create a class called "Movie" with these parameters:
// - title
// - rating
// - director

class Movie {
public:
  Movie(string title, string rating, string director) {
    this->title = title;
    this->rating = rating;
    this->director = director;
  }

  // create a method called "getRating" that returns the rating
  string getRating() { return rating; } // getter for rating

  // create a method called "getDirector" that returns the director
  string getDirector() { return director; }

  // create a method called "getTitle" that returns the title of the movie
  string getTitle() { return title; }

  // create a method called "setRating" that sets the rating of the movie
  void setRating(string rating) { // setter for rating
    if (rating == "G" || rating == "PG" || rating == "PG-13" || rating == "R" ||
        rating == "NR") {
      this->rating = rating;
    } else {
      this->rating = "NR";
    }
  }

private:
  string title;
  string rating;
  string director;
};

int main() {
  Movie movie1("The Matrix", "R", "Wachowski");

  cout << "Movie title: " << movie1.getTitle() << endl;
  cout << "Movie rating: " << movie1.getRating() << endl;
  cout << "Movie director: " << movie1.getDirector() << endl;

  movie1.setRating("PG-13");
  cout << "Movie rating after setRating call: " << movie1.getRating() << endl;
}