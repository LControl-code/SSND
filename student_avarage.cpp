#include <iostream>
#include <vector>
using namespace std;

vector<vector<float>> sort_simple(vector<vector<float>> grade_not_sorted,int r) {
  // r is the number of students
  // grade_not_sorted is the unsorted grade vector
  // sorting in ascending order
  for (int i = 1; i < r; i++) {
    // float current = grade_not_sorted[i][5];
    // insertion sort
    vector<float> current_arr(r);
    current_arr = grade_not_sorted[i];
    int j = i - 1;
    while (j >= 0 && grade_not_sorted[j][5] > current_arr[5]) {
      grade_not_sorted[j + 1] = grade_not_sorted[j];

      j--;
    }
    grade_not_sorted[j + 1] = current_arr;
  }
  return grade_not_sorted;
}

void list_ranking(vector<vector<float>> grade_to_rank, int r) {
  cout << "RANKS  STUDENT NO.  AVERAGE" << endl;
  int rank = 1;
  for (int i = r - 1; i >= 0; i--) {
    cout << rank << "\t" << grade_to_rank[i][0] << "\t     "
         << grade_to_rank[i][5] << endl;
    rank++;
  }
}
int main() {
  int student_count;
  cout << "How many students do you want to input? ";
  cin >> student_count;

  vector<vector<float>> grade(student_count, vector<float>(5));
  for (int i = 0; i < student_count; i++) {
    cout << "\nInput Average Grade of Student #" << i + 1 << endl;
    grade[i][0] = i + 1;

    cout << "First Grading Period: ";
    cin >> grade[i][1];

    cout << "Second Grading Period: ";
    cin >> grade[i][2];

    cout << "Third Grading Period: ";
    cin >> grade[i][3];

    cout << "Fourth Grading Period: ";
    cin >> grade[i][4];

    grade[i].push_back((grade[i][1] + grade[i][2] + grade[i][3] + grade[i][4]) / 4);

    cout << "=============================" << endl;
    cout << "Average of Student #" << i + 1 << ": " << grade[i][5] << endl;
    system("clear");
  }

  grade = sort_simple(grade, student_count);
  list_ranking(grade, student_count);
  return 0;
}
