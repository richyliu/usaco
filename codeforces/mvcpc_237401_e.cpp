#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct str {
    vector<bool> letters;
    // s to total ratio
    double s;
};

bool compStr(str a, str b) {
    return a.s > b.s;
}

int main() {
    int n = 0;
    cin >> n;
    getchar();
    
    str strs[n];
    char next;
    for (int i = 0; i < n; i++) {
        strs[i].letters = vector<bool>();
        int s = 0;
        int total = 0;
        
        while ((next = getchar()) > 30) {
            bool isS = next == 's';
            strs[i].letters.push_back(isS);
            if (isS) s++;
            total++;
        }
        strs[i].s = (double)s / total;
    }
    
    sort(strs, strs + n, compStr);
    
    
    int curS = 0;
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        for (bool s : strs[i].letters) {
            if (s) curS++;
            else total += curS;
        }
    }
    
    cout << total << endl;
    
    return 0;
}