#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void fastscan(int &x) {
  bool neg = false;
  register int c;
  x = 0;

  c = getchar();
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar())
    x = (x << 1) + (x << 3) + c - 48;
  if (neg)
    x *= -1;
}

int main() {
  /* COMMMENT BEFORE SUBMITTING */
  ifstream cin; cin.open("data.txt");
  /* COMMMENT BEFORE SUBMITTING */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  fastscan(b);
  cin >> a;
  cout << a+b << "\n";

  return 0;
}
