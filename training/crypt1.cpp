/*
ID: richy.l1
LANG: C++11
TASK: crypt1
*/
#include <bits/stdc++.h>

using namespace std;

int nums[10];
int n;

bool checkDigit(int a) {
  for (int i = 0; i < n; i++)
    if (nums[i] == a) return true;
  return false;
}

bool checkDigits(int num) {
  while (num > 0) {
    int digit = num % 10;
    if (!checkDigit(digit)) return false;
    num /= 10;
  }

  return true;
}

int main() {
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");

  fin >> n;
  for (int i = 0; i < n; i++)
    fin >> nums[i];

  int total = 0;
  for (int i1 = 0; i1 < n; i1++)
    for (int i2 = 0; i2 < n; i2++)
      for (int i3 = 0; i3 < n; i3++)
        for (int i4 = 0; i4 < n; i4++)
          for (int i5 = 0; i5 < n; i5++)
            if (
                checkDigit(nums[i1]) && checkDigit(nums[i2]) && checkDigit(nums[i3]) &&
                checkDigit(nums[i4]) && checkDigit(nums[i5]) &&
                ((nums[i1]*100 + nums[i2]*10 + nums[i3]) * nums[i5]) < 1000 && 
                ((nums[i1]*100 + nums[i2]*10 + nums[i3]) * nums[i4]) < 1000 &&
                checkDigits((nums[i1]*100 + nums[i2]*10 + nums[i3]) * nums[i5]) &&
                checkDigits((nums[i1]*100 + nums[i2]*10 + nums[i3]) * nums[i4]) &&
                checkDigits((nums[i1]*100 + nums[i2]*10 + nums[i3]) * (nums[i4]*10 + nums[i5]))
               ) {
              /* cout << nums[i1] << nums[i2] << nums[i3] << " x " << nums[i4] << nums[i5] << endl; */
              total++;
            }

  fout << total << endl;

  return 0;
}
