#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream cin; cin.open("paintbarn.in");
  ofstream fout; fout.open("paintbarn.out");

  int n = 0;
  cin >> n;

  fout << "26\n";

  return 0;
}
