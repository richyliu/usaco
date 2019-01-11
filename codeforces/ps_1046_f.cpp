#include <iostream>
#include <fstream>

using namespace std;


int main() {
  /* COMMMENT BEFORE SUBMITTING */
  //fstream cin; cin.open("data.txt");
  /* COMMMENT BEFORE SUBMITTING */

  long long n = 0;
  cin >> n;
  long long wallets[n]; 

  for (int i = 0; i < n; i++)
    cin >> wallets[i];

  long long maxPer = 0;
  cin >> maxPer;
  long long fee = 0;
  cin >> fee;

  long long total = 0;
  for (int i = 0; i < n; i++) {
    if (wallets[i] > maxPer) {
      if (wallets[i] <= maxPer + fee)
        total += fee;
      else {
        if (wallets[i] % (maxPer+fee) > maxPer)
          total += fee;
        total += (wallets[i]/(maxPer+fee)) * fee;
      }
    }
  }
  
  cout << total << endl;

  return 0;
}