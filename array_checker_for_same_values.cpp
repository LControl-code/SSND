#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<int> A, vector<int> B, int N) {
        //code here
        // vector<ll> temp_A = A;
        // vector<ll> temp_B = B;
        

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return A == B;
        // for (int i = 0; i < N; i++) {
        //     int counter = 0;
        //     for (int j = 0 ; j < N; j++) {
        //         if(A[i] == B[j]){
        //             counter++;
        //         }
        //         if(j == N - 1 && counter < 1){
        //             return false;
        //         }
        //     }
        // }
        // return true;
        // ! too slow

    }
};


int main(){
  vector<int> A = {5,2,3,1,4}, B = {4,2,3,1,5};
  int N = 5;
  Solution ob;
  cout << ob.check(A, B, N);
  
}
