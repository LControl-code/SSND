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
        
        string getRating() {
            return rating;
        }
        string getDirector() {
            return director;
        }
        string getTitle() {
            return title;
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
  
}