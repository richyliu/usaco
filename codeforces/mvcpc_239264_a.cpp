#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


int main() {
  int t = 0;
  cin >> t;

  fori(t) {
    int target;
    double high, low;
    cin >> target;

    if (target == 0) {
      printf("Y 0.000000000 0.000000000\n");
      continue;
    }

    high = target;
    low = 0;
    double cur;
    while (abs(high-low) > 1e-10) {
      cur = (high+low) / 2.0;
      double a = cur * (target - cur);
      if (abs(a - target) < 1e-10)
        break;
      else if (a > target)
        high = cur;
      else
        low = cur;
    }
    if (abs((target - cur) * cur - target) < 1e-6)
      printf("Y %.9f %.9f\n", (target - cur), cur);
    else
      printf("N\n");
  }

  return 0;
}
