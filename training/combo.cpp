/*
ID: richy.l1
LANG: C++11
TASK: combo
*/
#include <iostream>
#include <fstream>

#define fori(x) for (int i = 0; i < x; i++)
#define forj(x) for (int j = 0; j < x; j++)

using namespace std;


int main() {
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	
	int n = 0;
	fin >> n;
	
	int combo1[3], combo2[3];
	fori(3) fin >> combo1[i];
	fori(3) fin >> combo2[i];
	
	int lock1Total = 1, lock2Total = 1, bothTotal = 1;
	fori(3) {
		int lock1 = 0;
		int lock2 = 0;
		int both = 0;
		for(int k = 1; k <= n; k++) {
			int j = (n >= 5 || k > 3) ? (k <= n/2 ? k : k - n) : k;
			int c1 = combo1[i] <= n/2 ? combo1[i] : combo1[i] - n;
			int c2 = combo2[i] <= n/2 ? combo2[i] : combo2[i] - n;
				cout << c1 << " " << j << endl;
			if (abs(combo1[i] - k) <= 2 || abs(c1 - j) <= 2) {
				lock1++;
				if (abs(combo2[i] - k) <= 2 || abs(c2 - j) <= 2)
					both++;
			}
			if (abs(combo2[i] - k) <= 2 || abs(c2 - j) <= 2) {
				//cout << j << endl;
				lock2++;
			}
		}
		cout << lock1 << " " << lock2 << " " << both << " " << "\n";
		
		lock1Total *= lock1;
		lock2Total *= lock2;
		bothTotal *= both;
	}
	
	cout << (lock1Total + lock2Total - bothTotal) << endl;
	fout << (lock1Total + lock2Total - bothTotal) << endl;
	
	return 0;
}