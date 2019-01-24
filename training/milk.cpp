/*
ID: richy.l1
LANG: C++11
TASK: milk
*/

#include <bits/stdc++.h>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) fori(x) cout << arr[i] << endl

typedef pair<int, int> pii;

int main() {
  // File input/output setup
  string name = "milk";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup
  
  int m, n;
  cin >> n >> m;

  pii farmers[m];
  int a, b;
  fori(m) {
    cin >> a >> b;
    farmers[i] = {a, b};
  }

  sort(farmers, farmers + m, [](pii &left, pii &right) {
      return left.first < right.first;
      });

  long long cost = 0;
  int costPer = 0, canSell = 0;
  fori(m) {
    costPer = farmers[i].first;
    canSell = farmers[i].second;
    if (canSell < n) {
      cost += costPer * canSell;
      n -= canSell;
    } else {
      cost += costPer * n;
      break;
    }
  }

  cout << cost << endl;
  fout << cost << endl;

  return 0;
}
