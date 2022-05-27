#include <iostream>
#include <vector>
using namespace std;

int main() {

    string sentence;
    getline(cin, sentence);
    vector<char> char_sentence(sentence.length());

    for (int i = 0; i < sentence.length(); i++){

    if (int(sentence[i]) >= 97 && int(sentence[i]) <=172) {
      char_sentence[i] = sentence[i] - 32;
      cout << char_sentence[i];
    }

    else {
        char_sentence[i] = sentence[i];
        cout << char_sentence[i];
    }

    }
    

    return 0;
}