#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {
  /* cout << "start" << endl << endl; */
  int t = 0;
  cin >> t;
  int nums[200];
  int primes[200];
  int copied[200];

  forj(t) {
    int n = 0;
    int l = 0;
    cin >> n;
    cin >> l;
    cout << "Case #" << j + 1 << ": ";
    unordered_set<int> copiedSet;

    fori(l)
      cin >> nums[i];

    int key = 0;
    fori(l-1) {
      cout << "loop\n";
      if (nums[i] != nums[i+1]) {
        key = gcd(nums[i], nums[i+1]);
        break;
      }
    }
    // reason it doesn't work: key might not be for the first element
    cout << "key: " << key;
    key = nums[0] / key;
    primes[0] = key;
    copiedSet.insert(primes[0]);
    fori(l) {
      primes[i+1] = nums[i] / key;
      copiedSet.insert(primes[i+1]);
      key = primes[i+1];
    }
    int k = 0;
    for(unordered_set<int> :: iterator itr = copiedSet.begin(); itr != copiedSet.end(); itr++, k++)
      copied[k] = (*itr);

    sort(copied, copied+k);

    unordered_map<int, int> lookup;
    fori(k)
      lookup[copied[i]] = i;

    fori(l + 1) {
      cout << (char)(lookup[primes[i]] + 65);
    }

    /* cout << endl; */
    /* fori(l+1) cout << nums[i] << " "; */
    /* cout << endl; */
    /* fori(l+1) cout << primes[i] << " "; */
    /* cout << endl; */
    /* fori(k) cout << copied[i] << " "; */

    cout << endl;
  }

  return 0;
}
