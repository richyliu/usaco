#include <iostream>
using namespace std;

#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


int main() {
  int t = 0;
  int a = 0;
  cin >> t;
  forj(t) {
    cin >> a;
    cout << "Case #" << j + 1 << ": ";

    long outA = 0;
    long outB = 0;
    int digits[15];

    int i = 0;
    while(a > 0) {
      digits[i] = a % 10;
      a /= 10;
      i++;
    }

    for(int k = i-1; k >= 0; k--) {
      outA *= 10;
      outB *= 10;
      switch(digits[k]) {
        case 0:
          outA += 0;
          outB += 0;
          break;
        case 1:
          outA += 1;
          outB += 0;
          break;
        case 2:
          outA += 1;
          outB += 1;
          break;
        case 3:
          outA += 1;
          outB += 2;
          break;
        case 4:
          outA += 2;
          outB += 2;
          break;
        case 5:
          outA += 3;
          outB += 2;
          break;
        case 6:
          outA += 3;
          outB += 3;
          break;
        case 7:
          outA += 2;
          outB += 5;
          break;
        case 8:
          outA += 2;
          outB += 6;
          break;
        case 9:
          outA += 3;
          outB += 6;
          break;
      }
    }

    cout << outA << " " << outB << endl;
  }

  return 0;
}
