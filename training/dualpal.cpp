/*
ID: richy.l1
LANG: C++11
TASK: dualpal
*/

#include <bits/stdc++.h>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) fori(x) cout << arr[i] << endl


string toBase(int num, int base) {
  string ret = "";
  
  char add = ' ';
  short remainder = 0;
  while (num > 0) {
    remainder = num % base;
    if (remainder < 10) add = remainder + 48;
    else add = remainder + 55;
    ret = add + ret;
    num /= base;
  }
  return ret;
}

bool isPalindromeInBase(int num, int base) {
  string numStr = toBase(num, base);
  int len = numStr.length();
  fori(len / 2)
    if (numStr[i] != numStr[len - i - 1]) return false;
  return true;
}


int main() {
  // File input/output setup
  string name = "dualpal";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup
  
  int firstN = 0;
  cin >> firstN;
  int start = 0;
  cin >> start;

  int results[firstN];
  int resultsIdx = 0;

  int numPalindromicBases = 0;
  for(int i = start+1; resultsIdx < firstN; i++) {
    numPalindromicBases = 0;
    for (int base = 2; base <= 10; base++)
      if (isPalindromeInBase(i, base))
        numPalindromicBases++;
    if (numPalindromicBases >= 2) {
      results[resultsIdx] = i;
      resultsIdx++;
    }
  }

  fori(firstN)
    fout << results[i] << endl;
  fori(firstN)
    cout << results[i] << endl;

  return 0;
}
