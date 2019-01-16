#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) cout << "[ "; \
  fori(x) cout << arr[i] << (i == x - 1 ? "" : ", "); \
  cout << " ]\n"


int main() {
  // File input/output setup
  string name = "cbarn";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup


  // input
  int n = 0;
  cin >> n;
  int cows[n];
  fori(n) cin >> cows[i];


  // parse

  int maxI = 0;
  fori(n) if (cows[i] >= cows[maxI]) maxI = i;
  maxI = n-1;

  /* for (int i = maxI + 1; true; i++) { */
  /*   if (i == n-1) i = -1; */
  /*   if (cows[i] != 0) { */
  /*     maxI = i; */
  /*     break; */
  /*   } */
  /* } */
  /* cout << maxI << endl; */

  bool allOnes = true;
  bool first = true;
  // idx to swap with
  int total = 0;
  for (int i = maxI; i >= 0; i--) {
    if (cows[i] != 1) allOnes = false;
    // only need 0's
    if (cows[i] != 0) continue;

    printarr(cows, n);
    int j = i;
    // look for not 0
    while (cows[j] == 0) {
      // wrap around
      if (j == 0) j = n;
      j--;
    }

    cows[j]--;
    cows[i]++;
    if (j < i) total += pow(i - j, 2);
    else total += pow(i + n - j, 2);

    if (i == 0) {
      if (first) first = false;
      else {
        if (allOnes) break;
        allOnes = true;
      }
      i = n;
    }
  }

  
  // output
  cout << total << endl;
  fout << total << endl;

  return 0;
}
