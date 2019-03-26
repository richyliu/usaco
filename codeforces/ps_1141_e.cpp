#include <iostream>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  long H = 0;
  int n = 0;
  cin >> H >> n;
  int hits[n];
  fori(n)
    cin >> hits[i];

  int roundHit = 0;
  // best hit per round
  int low = 0;
  int cur = 0;
  fori(n) {
    cur += hits[i];
    roundHit += hits[i];
    if (cur < low) low = cur;
    cout << cur << endl;
  }
  cout << low << endl;

  if (-low < H && roundHit >= 0) {
    cout << "-1\n";
    return 0;
  }


  // roundHit should be negative
  int need = 0;
  int i = 0;

  while (H >= 0) {
    need++;
    H += hits[i];
    if (H <= 0) {
      cout << need << endl;
      return 0;
    }

    i++;
    if (i == n) i = 0;
  }

  cout << need << endl;
  return 0;
}
