#include <iostream>
#include <algorithm>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


int main() {
  int n;
  cin >> n;

  int nums[n];
  fori(n)
    cin >> nums[i];

  sort(nums, nums + n);

  long long total = 0;
  fori(n/2) {
    total += pow(nums[i] + nums[n-i-1], 2);
  }

  cout << total << endl;

  return 0;
}
