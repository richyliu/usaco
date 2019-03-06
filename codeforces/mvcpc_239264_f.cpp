#include <iostream>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)


void fastscan(int &number) {
    bool negative = false;
    int c;
    number = 0;

    c = getchar();
    if (c=='-')  {
        negative = true;
        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)  number *= -1;
}


int n, k, a, m;
int moves[200001];


// int move : index of the move (within the moves array)
bool canFit(int move) {
  bool noShip[n];
  fori(n) noShip[i] = false;
  fori(move) noShip[moves[i]] = true;

  /* fori(n) cout << noShip[i] << " "; cout << endl; */

  // check if "k" ships of size "a" can fit
  int cur = 0;
  // have already fit this many ships in
  int fit = 0;
  while (cur < n) {
    /* cout << cur << endl; */
    if (noShip[cur]) {
      cur++;
      continue;
    }

    bool goOutOuter = false;
    for (int i = cur; i < cur + a; i++) {
      if (i >= n || noShip[i]) {
        cur++;
        goOutOuter = true;
        break;
      }
    }
    if (goOutOuter) continue;

    fit++;
    cur += a + 1;

    /* cout << "fit: " << fit << endl; */
    if (fit >= k) return true;
  }

  return false;
}


int main() {
  fastscan(n);
  fastscan(k);
  fastscan(a);
  fastscan(m);
  fori(m) fastscan(moves[i]);
  fori(m) moves[i]--;

  int high = m;
  int low = 0;
  while (high > low) {
    int mid = (high + low) / 2;
    if (canFit(mid))
      low = mid + 1;
    else
      high = mid;
    /* cout << "mid: " << mid << " " << high << " " << low << endl; */
  }

  if (canFit(high))
    cout << "-1\n";
  else
    cout << high << endl;

  return 0;
}
