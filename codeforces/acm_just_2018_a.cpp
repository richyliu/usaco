#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {
  /* COMMMENT BEFORE SUBMITTING */
  ifstream cin; cin.open("data.txt");
  /* COMMMENT BEFORE SUBMITTING */

  int numTestCases = 0;
  cin >> numTestCases;
  for (int k; k < numTestCases; k++) {

    int arrSize = 0;
    int numQueries = 0;
    cin >> arrSize >> numQueries;

    int arr [arrSize];
    for (int i = 0; i < arrSize; i++) {
      cin >> arr[i];
    }

    for (int j = 0; j < numQueries; j++) {
      int type = 0;
      cin >> type;

      if (type == 1) {
        int p, v;
        cin >> p >> v;
        arr[p-1] = v;
      } else {
        /* cout << "requested" << endl; */

        // copy and sort array
        int copied [arrSize];
        for (int i = 0; i < arrSize; i++) copied[i] = arr[i];
        sort(copied, copied + sizeof(copied)/sizeof(copied[0]));

        // count unique values
        int num = 0;
        for (int i = 1; i < arrSize; i++ ) {
          if (copied[i-1] != copied[i]) num++;
        }
        cout << num + 1 << endl;

        // print array
        /* for (int i = 0; i < arrSize; i++) cout << copied[i] << " "; cout << endl; */

      }
    }

  }
  return 0;
}
