#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define fori(x) for(int i = 0; i < x; i++)


int main() {
  string a = "";
  getline(cin, a);
  string b = "";
  getline(cin, b);

  if (a.size() != b.size()) {
    cout << "No\n";
    return 0;
  }

  fori(a.length()) {
    if ((a[i] == 'a' || a[i] == 'o' || a[i] == 'i' || a[i] == 'e' || a[i] == 'u') ==
        !(b[i] == 'a' || b[i] == 'o' || b[i] == 'i' || b[i] == 'e' || b[i] == 'u')) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}
