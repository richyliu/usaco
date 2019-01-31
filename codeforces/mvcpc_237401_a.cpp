#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    
    int next = -1;
    for (int i = 0; i < n; i++) {
        cin >> next;
        if (next != 0) nums.push_back(next);
    }
    
    sort(nums.begin(), nums.end());
    
    int total = 1;
    
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] != nums[i - 1]) total++;
    
    cout << total << endl;
    
    return 0;
}