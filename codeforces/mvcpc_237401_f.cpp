#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + n);
    
    int pa = n-1;
    int pb = n-1;
    bool turnA = true;
    long long scorea = 0;
    long long scoreb = 0;
    
    while (pa >= 0 && pb >= 0) {
        if (a[pa] > b[pb]) {
            if (turnA) scorea += a[pa];
            pa--;
        } else {
            if (!turnA) scoreb += b[pb];
            pb--;
        }
        turnA = !turnA;
    }
    if (pa >= 0) {
        for (; pa >= 0; pa--) {
            if (turnA) scorea += a[pa];
            turnA = !turnA;
        }
    } else if (pb >= 0) {
        for (; pb >= 0; pb--) {
            if (!turnA) scoreb += b[pb];
            turnA = !turnA;
        }
    }
    
    cout << (scorea - scoreb) << endl;
    
    return 0;
}