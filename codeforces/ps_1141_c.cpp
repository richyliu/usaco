#include <iostream>
#include <unordered_set>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n = 0;
  cin >> n;

  int nums[n];
  int min = 0;
  int max = 0;
  int cur = 0;
  nums[0] = 0;
  fori(n-1) {
    int temp = 0;
    cin >> temp;
    cur += temp;
    nums[i+1] = cur;
    if (cur < min) min = cur;
    if (cur > max) max = cur;
  }


  unordered_set<int> noduplicates(nums, nums + n);
  if (max - min >= n || noduplicates.size() != n) {
    cout << "-1\n";
    return 0;
  }

  if (min == 1) min = 0;
  fori(n) {
    if (nums[i]-min + 1 <= 0) {
      cout << "-1\n";
      return 0;
    }
  }
  fori(n) {
    cout << (nums[i] - min + 1) << " ";
  }
  cout << endl;

  return 0;
}
