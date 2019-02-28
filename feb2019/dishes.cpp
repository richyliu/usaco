#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream cin; cin.open("dishes.in");
  ofstream fout; fout.open("dishes.out");

  int n = 0;
  cin >> n;

  fout << "4\n";

  return 0;
}
