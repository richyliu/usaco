#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
  /* COMMMENT BEFORE SUBMITTING */
  /* ifstream cin; cin.open("data.txt"); */
  /* COMMMENT BEFORE SUBMITTING */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  bool bulbs[m];
  for (int i = 0; i < m; i++)
    bulbs[i] = false;

  int line;
  int next;
  for (int i = 0; i < n; i++) {
    cin >> line;
    for (int j = 0; j < line; j++) {
      cin >> next;
      next--;
      bulbs[next] = true;
    }
  }

  for (int i = 0; i < m; i++) {
    if (!bulbs[i]) {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";

  return 0;
}
