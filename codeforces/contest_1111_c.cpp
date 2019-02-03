#include <iostream>
#include <algorithm>

using namespace std;


typedef long long ll;

#define fori(x) for(ll i = 0; i < x; i++)

ll pos[100000];
ll n, k, A, B;



// start inclusive, end exclusive
ll power2(ll start, ll end) {
  // num avengers in range
  ll sum = 0;
  fori(k) {
    if (pos[i] > start && pos[i] <= end)
      sum++;
  }

  /* cout << sum << "  " << start << ", " << end << endl; */

  // can no longer split
  if (end - start < 2) {
    if (sum > 0)
      return sum * B * (end - start);
    else
      return A;
  }

  if (sum > 0) {
    // have to use power or split
    ll left = power2(start, (start+end)/2);
    ll right = power2((start+end)/2, end);

    return min(left + right, sum * (ll)B * (end - start));
  } else {
    return A;
  }
}


int main() {
  cin >> n >> k >> A >> B;

  fori(k)
    cin >> pos[i];
  sort(pos, pos + k);

  cout << power2(0, pow(2, n)) << endl;

  return 0;
}
