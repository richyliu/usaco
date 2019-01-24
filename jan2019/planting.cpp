#include <bits/stdc++.h>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define printarr(arr, x) fori(x) cout << arr[i];
#define printarr2(arr, x, y) fori(x) {\
  forj(y) cout << arr[i][j]; \
  cout << endl; \
}
#define printlocs(arr, n) fori(n) \
  cout << "( " << arr[i].first << ", " << arr[i].second << " )" << endl


typedef pair<int, int> loc;



int main() {
  ifstream cin; cin.open("planting.in");
  ofstream fout; fout.open("planting.out");


  // input

  int N = 0;
  cin >> N;
  N--;
  int N2 = N * 2;

  int pairs[N2];

  int tempa, tempb;
  for (int i = 0; i < N2; i += 2) {
    cin >> tempa >> tempb;
    pairs[i] = tempa;
    pairs[i+1] = tempb;
  }


  // process
  sort(pairs, pairs + N2);
  fori(N2) cout << pairs[i] << ", ";
  cout << endl;

  int mostConnection = 0;
  int cur = 0;
  int previous = 0;
  fori(N2) {
    if (pairs[i] != previous) {
      previous = pairs[i];
      cur = 0;
    }
    cur++;
    if (cur > mostConnection) mostConnection = cur;
  }

  cout << mostConnection + 1 << endl;
  fout << mostConnection + 1 << endl;


  // output

  return 0;
}
