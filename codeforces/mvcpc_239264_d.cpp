#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)


// friend
struct frd {
  int loc;
  int speed;
};

int n;
frd frds[60001];


bool possible(double time) {
  double lowest = 1000000000;
  double highest = 0;
  fori(n) {
    double rightMost = frds[i].loc + frds[i].speed * time;
    double leftMost = frds[i].loc - frds[i].speed * time;
    if (rightMost < lowest) lowest = rightMost;
    if (leftMost > highest) highest = leftMost;
  }

  /* cout << lowest << ' ' << highest << endl; */

  return lowest >= highest;
}


bool comp(frd a, frd b) {
  return a.loc < b.loc;
}


int main() {
  cin >> n;
  fori(n) {
    int inp;
    cin >> inp;
    frds[i].loc = inp;
  }
  fori(n) {
    int inp;
    cin >> inp;
    frds[i].speed = inp;
  }

  sort(frds, frds + n, comp);
  /* fori(n) cout << frds[i].loc << " " << frds[i].speed << endl; */
  

  double high = 1000000000;
  double low = 0;
  while (fabs(high - low) > 1e-6) {
    double mid = (high + low) / 2;
    if (possible(mid))
      high = mid;
    else
      low = mid;
    /* cout << "high: " << high << " low: " << low << endl; */
    /* cout << fabs(high-low) << endl; */
  }

  printf("%.12f", high);
  /* cout << high << endl; */


  return 0;
}
