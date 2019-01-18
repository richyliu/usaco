/*
ID: richy.l1
LANG: C++11
TASK: barn1
*/
#include <bits/stdc++.h>

using namespace std;


int main() {
	ifstream cin; cin.open("barn1.in");
	ofstream fout; fout.open("barn1.out");
	
	int m, s, c;
	cin >> m >> s >> c;
	
	// length from 1st to last cow
	int len = 0;
	int cows[c];
	// diffs in stall numbers
	int diffs[c-1];
	for (int i = 0; i < c; i++)
		cin >> cows[i];
	sort(cows, cows + c);
	len = cows[c-1] - cows[0];
	
	for (int i = 0; i < c-1; i++)
		diffs[i] = cows[i+1] - cows[i];
	
	for (int i = 0; i < c-1; i++)
		cout << diffs[i] << " ";
	cout << endl;
	sort(diffs, diffs + c - 1);
	
	for (int i = 0; i < m-1; i++){
		len -= diffs[c-1-i-1];
		cout << diffs[c-1-i-1] << endl;
	}
	
	cout << len + m << endl;
	if (m >= c) fout << c << endl;
	else fout << len + m << endl;

	return 0;
}