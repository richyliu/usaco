#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
  /* COMMMENT BEFORE SUBMITTING */
  ifstream cin; cin.open("data.txt");
  /* COMMMENT BEFORE SUBMITTING */
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 0;
  int k = 0;
  cin >> n >> k;
  
  int towers[n];
  int tallest = -1;
  int target = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> towers[i];
    if (towers[i] > tallest)
      tallest = towers[i];
    if (towers[i] < target)
      target = towers[i];
  }
  
  // the answer (minimum good slices)
  int ans = 0;
  // current sliced top
  int top = 1e9;
  // try a bunch of slices
  for (int slice = tallest; slice > 0; slice--) {
    // running total of cost
    int curtotal = 0;
    
    // loop through towers, slicing them at height "slice" up to top
    for (int i = 0; i < n; i++) {
      if (towers[i] > slice) {
        curtotal += min(towers[i], top) - slice;
      }
    }
    
    if (curtotal > k) {
      ans++;
      top = slice - 1;
    }
    
    cout << curtotal << endl;
  }
  
  cout << ans << endl;
  
  return 0;
}
