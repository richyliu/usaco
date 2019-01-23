/*
ID: richy.l1
LANG: C++11
TASK: combo
*/
#include <iostream>
#include <fstream>

using namespace std;

#define fori(x) for(int i = 0; i < x; i++)

int main() {
  ifstream fin("combo.in");
  ofstream fout("combo.out");

  int n;
  fin >> n;

  int combo1[3];
  int combo2[3];
  fori(3) fin >> combo1[i];
  fori(3) fin >> combo2[i];

  int sub = 1;
  fori(3) sub *= max(5 - abs(combo1[i] - combo2[i]), 1);

  fout << (250 - sub) << endl;

  return 0;
}
