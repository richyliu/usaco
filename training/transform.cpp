/*
ID: richy.l1
LANG: C++11
TASK: transform
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define FOR(x)  for(int i = 0; i < x; i++)
#define FORJ(x) for(int j = 0; j < x; j++)
#define FOR2(x) for(int i = 0; i < x; i++) \
                            for (int j = 0; j < x; j++)
#define PRINT2(arr, len) FOR(len) { \
  for (int j = 0; j < len; j++) cout << arr[i][j]; \
  cout << endl; \
} \
cout << endl;

typedef vector< vector<bool> > boolmat;
typedef vector<bool> boolvec;


bool match(boolmat one, boolmat two, int size) {
  FOR2(size)
    if (one[i][j] != two[i][j]) return false;
  return true;
}

int main() {
  ifstream fin; fin.open("transform.in");
  ofstream cout; cout.open("transform.out");

  // input
  int n = 0;
  fin >> n;

  boolmat original(n, boolvec(n));
  boolmat target(n, boolvec(n));
  FOR2(n) {
    char next;
    fin >> next;
    original[i][j] = next == '@';
  }
  FOR2(n) {
    char next;
    fin >> next;
    target[i][j] = next == '@';
  }

  // processing
  boolmat temp(n, boolvec(n));

  // 90 deg
  FOR2(n)
    temp[j][n-i-1] = original[i][j];
  if (match(target, temp, n)) {
    cout << 1 << endl;
    return 0;
  }

  // 270 deg
  FOR2(n)
    temp[n-j-1][i] = original[i][j];
  if (match(target, temp, n)) {
    cout << 3 << endl;
    return 0;
  }

  // 180 deg
  FOR2(n)
    temp[n-i-1][n-j-1] = original[i][j];
  if (match(target, temp, n)) {
    cout << 2 << endl;
    return 0;
  }

  // reflection
  FOR2(n)
    temp[i][n-j-1] = original[i][j];
  if (match(target, temp, n)) {
    cout << 4 << endl;
    return 0;
  }

  // reflection + 90 deg
  boolmat temp2(n, boolvec(n));
  boolmat temp3(n, boolvec(n));
  boolmat temp4(n, boolvec(n));
  
  FOR2(n)
    temp2[j][n-i-1] = temp[i][j];
  FOR2(n)
    temp3[n-j-1][i] = temp[i][j];
  FOR2(n)
    temp4[n-i-1][n-j-1] = temp[i][j];
  if (
      match(target, temp2, n) ||
      match(target, temp3, n) ||
      match(target, temp4, n)
      ) {
    cout << 5 << endl;
    return 0;
  }

  if (match(target, original, n)) {
    cout << 6 << endl;
    return 0;
  }

  cout << 7 << endl;

  return 0;
}
