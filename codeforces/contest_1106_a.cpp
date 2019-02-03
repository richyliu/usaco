#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


int main() {
  int n = 0;
  cin >> n;

  bool mat[n][n];
  char next;
  fori(n) {
    forj(n) {
      cin >> next;
      mat[i][j] = next == 'X';
    }
  }

  long long count = 0;
  for(int i = 1; i < n-1; i++) {
    for(int j = 1; j < n-1; j++) {
      if (mat[i][j] && mat[i-1][j-1] && mat[i-1][j+1] && mat[i+1][j-1] && mat[i+1][j+1]) {
        count++;
      }  
    }
  }

  cout << count << endl;

  return 0;
}
