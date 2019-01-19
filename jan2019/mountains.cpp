#include <bits/stdc++.h>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define printarr(arr, x) fori(x) cout << arr[i];
#define printarr2(arr, x, y) fori(x) {\
  forj(y) cout << arr[i][j]; \
  cout << endl; \
}
#define printlocs(arr, n) fori(n) \
  cout << "( " << arr[i].first << ", " << arr[i].second << " )" << endl


typedef pair<int, int> loc;


/**
 * Checks if mountain b is hidden by mountain a.
 * Precondition: y value of a is > y value of b
 */
bool hidden(loc a, loc b) {
  return abs(a.first - b.first) <= a.second - b.second;
}


int main() {
  ifstream cin; cin.open("mountains.in");
  ofstream fout; fout.open("mountains.out");


  // input

  int N = 0;
  cin >> N;

  vector<loc> mountains (N, loc(0, 0));

  int tempa, tempb;
  fori(N) {
    cin >> tempa >> tempb;
    mountains[i] = loc(tempa, tempb);
  }


  // process
  // start by assuming she can see all
  int seeable = N;
  // sort by y value
  sort(mountains.begin(), mountains.end(), [](loc a, loc b) {
      return a.second < b.second;
      });
  printlocs(mountains, N);
  // decrement from seeable if she cannot see it
  fori(N-1) {
    for(int j = i+1; j < N; j++) {
      if (mountains[j].second <= mountains[i].second) continue;
      if (hidden(mountains[j], mountains[i])) {
        seeable--;
        break;
      }
    }
  }

  // output
  cout << seeable << endl;
  fout << seeable << endl;


  return 0;
}
