/*
ID: richy.l1
LANG: C++11
TASK: namenum
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) fori(x) cout << arr[i] << endl


int main() {
  // File input/output setup
  string name = "namenum";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  ifstream namesin; namesin.open("dict.txt");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup

  int numNames = 4617;
  string names[numNames];
  fori(numNames) namesin >> names[i];

  // num to match
  int digits[12];
  char c;
  int numDigits;
  for (numDigits = 0; cin >> c; numDigits++)
    digits[numDigits] = c - 48;


  string valid[100];
  int validIdx = 0;

  bool nomatch = false;
  short cur;
  fori(numNames) {
    nomatch = false;
    if ((int)names[i].length() != numDigits) continue;
    for (int j = 0; j < numDigits && !nomatch; j++) {
      // A becomes 0
      cur = names[i][j] - 65;
      if (cur < 15 && cur / 3 != digits[j] - 2) nomatch = true;
      else if (cur >= 15 && (
            digits[j] < 7 ||
            (digits[j] == 7 && (cur != 15 && cur != 17 && cur != 18)) ||
            (digits[j] == 8 && (cur < 19 && cur > 21)) ||
            (digits[j] == 9 && (cur < 22 && cur > 24))
            )) nomatch = true;
    }
    if (nomatch) continue;
    else {
      valid[validIdx] = names[i];
      validIdx++;
    }
  }

  printarr(valid, validIdx);
  
  if (validIdx == 0) fout << "NONE" << endl;
  else fori(validIdx) fout << valid[i] << endl;


  return 0;
}
