#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void fastscan(ll &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 


int main() {
	//fstream cin; cin.open("data.txt");
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
	ll n = 0;
	cin >> n;
	
	char next;
	// height and width, a supposed to be greater than b
	ll h = 0, w = 0, a = 0, b = 0, swp = 0;
	
	for(int i = 0; i < n; i++) {
	  cin >> next;
	  fastscan(a);
	  fastscan(b);
		if (a < b) {
		  swp = a;
		  a = b;
		  b = swp;
		}
		if (next == '+') {
	    if (b > h) h = b;
	    if (a > w) w = a;
		} else {
			cout << (a >= w && b >= h ? "YES" : "NO") << "\n";
		}
	}

	return 0;
}