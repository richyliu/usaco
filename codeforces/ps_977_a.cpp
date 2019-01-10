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

  long long n;
  int k;
  cin >> n >> k;

  for (int i = 0; i < k; i++)
    if (n % 10 == 0)
      n /= 10;
    else
      n--;

  cout << n << "\n";

  return 0;
}
