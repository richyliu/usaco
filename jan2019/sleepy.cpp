#include <iostream>
#include <fstream>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define printarr(arr, x) fori(x) cout << arr[i] << ", "; cout << endl



int main() {
  ifstream cin; cin.open("sleepy.in");
  ofstream fout; fout.open("sleepy.out");


  // input

  int N = 0;
  cin >> N;

  int cows[N];
  fori(N) cin >> cows[i];

  // process
  printarr(cows, N);

  // output
  /* fout << 3 << endl; */
  /* fout << 2 << " " << 2 << " " << 3 << endl; */

  return 0;
}
