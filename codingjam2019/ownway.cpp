#include <iostream>
using namespace std;

#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


int main() {
  int t = 0;
  cin >> t;

  forj(t) {
    int n = 0;
    cin >> n;
    cout << "Case #" << j + 1 << ": ";

    char temp;
    fori(2*n - 2) {
      cin >> temp;
      if (temp == 'S') cout << 'E';
      else cout << 'S';
    }

    cout << endl;
  }

  return 0;
}
