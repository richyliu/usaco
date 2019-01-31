/*
ID: richy.l1
LANG: C++11
TASK: wormhole
*/
#include <iostream>
#include <fstream>
#include <vector>

#define fori(x) for (int i = 0; i < x; i++)
#define forj(x) for (int j = 0; j < x; j++)

using namespace std;

typedef pair<int, int> ipair;


void printPair(ipair pair) {
	cout << pair.first << ", " << pair.second << endl;
}

int main() {
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");
	
	/* Input */
	int n = 0;
	fin >> n;
	
	int a, b;
	vector<ipair> holes;
	fori(n) {
		fin >> a >> b;
		holes.push_back(ipair(a, b));
	}
	
	/* Parsing */
	// remove pairs with unique y values
	for (vector<ipair>::size_type i = 0; i != holes.size(); i++) {
		bool unique = true;
			cout << holes[i].second << " =? " << endl;
		for (auto const &b : holes) {
			if (holes[i].second == b.second) {
				unique = false;
				break;
			}
		}
		
		if (unique) {
			cout << "uni" << endl;
			holes.erase(holes.begin() + i);
		}
	}
	
	fori(n)
		printPair(holes[i]);
	
	int num = 0;
	
	
	cout << n << endl;
	cout << num << endl;
	
	return 0;
}
