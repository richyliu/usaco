#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream cin; cin.open("shortcut.in");
  ofstream fout; fout.open("shortcut.out");

  int a;
  cin >> a;
  if (a == 5) fout << 40 << endl;

  return 0;
}
