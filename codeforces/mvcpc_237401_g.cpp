#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define pn 300005
#define bignum 1000000007

long long powers[pn];

long long pow2(long long to) {
	return powers[to];
}

int main() {
	long long ctr = 1;
	for (int i = 0; i < pn; i++) {
		powers[i] = ctr;
		ctr *= 2;
		ctr %= bignum;
	}
	
	int n = 0;
	cin >> n;

	long long coords[n];

	for (int i = 0; i < n; i++)
		cin >> coords[i];

	sort(coords, coords + n);

	long long diffs[n-1];
	for (int i = 0; i < n-1; i++)
		diffs[i] = coords[i+1] - coords[i];
	
	int m = n-1;
	int o = m-1;

	long long total = 0;
	long long powerCtr = 0;
	// cout << "m: " << m << endl;
	
	for (int i = 0; i < m/2; i++) {
		powerCtr += pow2(m-i) - pow2(i);
		powerCtr %= bignum;
		total += diffs[i] * powerCtr;
		total %= bignum;
		total += diffs[m-i-1] * powerCtr;
		total %= bignum;
		// cout << total << ", " << powerCtr << endl;
	}
	if (m % 2 == 1) {
		int i = m/2;
		powerCtr += pow2(m-i) - pow2(i);
		powerCtr %= bignum;
		total += diffs[i] * powerCtr;
		total %= bignum;
		// cout << total << ", " << powerCtr << endl;
	}
	
	cout << (total >= 0 ? total : bignum + total) << endl;

	return 0;
}