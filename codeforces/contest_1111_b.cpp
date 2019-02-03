#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define fori(x) for(int i = 0; i < x; i++)


int main() {
  int n, k, m;
  cin >> n >> k >> m;

  int powers[n];
  fori(n) cin >> powers[i];

  sort(powers, powers + n);

  // can remove all superheros but 1
  if (m >= n-1) {
    // increment power of best superhero
    int remainingMoves = min(m-(n-1), k);

    powers[n-1] += remainingMoves;

    cout << powers[n-1] << endl;
    return 0;
  } else {
    // remove as many as possible
    int remaining = n - m;

    long long total = 0;
    for (int i = m; i < n; i++)
      total += powers[i];

    cout << setprecision(20) << (total / (double)remaining) << endl;
    return 0;
  }
}
