#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) fori(x) cout << arr[i]


int main() {
  // File input/output setup
  string name = "template";
  ifstream cin; cin.open(name + ".in");
#ifndef COUT
  ofstream cout; cout.open(name + ".out");
#endif
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup

  int a = 0;
  cin >> a;
  cout << a + 2 << endl;

  return 0;
}
