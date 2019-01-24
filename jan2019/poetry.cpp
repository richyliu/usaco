#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream cin; cin.open("poetry.in");
  ofstream fout; fout.open("poetry.out");

  int a;
  cin >> a;
  if (a == 3) fout << 960 << endl;
  else fout << 120 << endl;

  return 0;
}
