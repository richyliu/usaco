#include <iostream>
#include <algorithm>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)


typedef pair<int, int> pii;


bool comp(pii a, pii b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n = 0, q = 0;
  cin >> n >> q;

  pii sections[q];
  fori(q) {
    int a, b;
    cin >> a >> b;
    sections[i] = pii(a, b);
  }
  sort(sections, sections + q, comp);


  // print sections
  fori(q) cout << "(" << sections[i].first << ", " << sections[i].second << ")" << endl;

  int maximum = 0;
  for(int a = 0; a < q; a++) {
    for (int b = 0; b < q; b++) {
      if (b == a) continue;
      cout << "a: " << a << " b: " << b << endl;

      int cur = 0;
      int ptr = -1;

      fori(q) {
        if (i != a && i != b) {
          if (ptr == -1) ptr = sections[i].first - 1;
          if (sections[i].second > ptr)
            cur += sections[i].second - max(ptr, sections[i].first);
          if (sections[i].first > ptr)
            cur++;
          ptr = max(ptr, sections[i].second);
          cout << ptr << "-" << cur << ", ";
        }
      }

      cout << endl << endl;
      if (cur > maximum) maximum = cur;
    }
  }

  cout << maximum << endl;

  return 0;
}
