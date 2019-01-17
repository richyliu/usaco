/*
ID: richy.l1
LANG: C++11
TASK: palsquare
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
  string name = "palsquare";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup
  
  int base = 0;
  cin >> base;

  vector<pair<int, int>> results;
  int squared = 0;
  for(int i = 1; i <= 300; i++) {
    squared = pow(i, 2);
    if (isPalindromeInBase(squared, base)) {
      results.push_back({i, squared});
    }
  }

  for (auto &it : results) {
    fout << toBase(it.first, base) << " " << toBase(it.second, base) << endl;
  }

  return 0;
}
