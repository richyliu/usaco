#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define println cout << endl
#define printarr(arr, x) cout << "[ "; \
  fori(x) cout << arr[i] << (i == x - 1 ? "" : ", "); \
  cout << " ]\n"


int cows[1000][2];
short n = 0;


// count max cows in each division with the lines x and y
int countcows(int x, int y) {
  int topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
  bool left = false, top = false;
  fori(n) {
    left = cows[i][0] < x;
    top = cows[i][1] < y;
    if (left && top) topLeft++;
    else if (!left && top) topRight++;
    else if (left && !top) bottomLeft++;
    else if (!left && !top) bottomRight++;
  }

  return max(max(topLeft, topRight), max(bottomLeft, bottomRight));
}


int countcowssection(int x, int y, short sec) {
  int topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
  bool left = false, top = false;
  fori(n) {
    left = cows[i][0] < x;
    top = cows[i][1] < y;
    if (left && top) topLeft++;
    else if (!left && top) topRight++;
    else if (left && !top) bottomLeft++;
    else if (!left && !top) bottomRight++;
  }

  switch(sec) {
    case 0: return topLeft;
    case 1: return topRight;
    case 2: return bottomLeft;
    case 3: return bottomRight;
    default:
      cout << "ERR ccs: " << sec << endl;
      return 0;
  }
}


int main() {
  // File input/output setup
  string name = "balancing";
  ifstream cin; cin.open(name + ".in");
  ofstream fout; fout.open(name + ".out");
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // End setup


  // input
  cin >> n;

  int maxX = 0, maxY = 0;
  {
    int first, second;

    fori(n) {
      cin >> first >> second;
      cows[i][0] = first;
      cows[i][1] = second;
      if (first > maxX) maxX = first;
      if (second > maxY) maxY = second;
    }
    /* cout << maxX << " " << maxY << endl; */
  }


  // parse

  // binary search for middle y value
  int midY = 0;
  {
    // low always 0 (high is maxY + 1 to make it even)
    int low = 0, high = maxY+1, top = 0, bottom = 0, target = 0;

    while (low < high) {
      if (abs(high-low) == 2) break;

      target = (high+low) / 2;
      if (target % 2 != 0) target++;

      top = countcowssection(0, target, 1);
      bottom = countcowssection(0, target, 3);

      if (top == n/2 || top == n/2 + 1) break;

      if (top < bottom) low = target;
      else if (top == bottom) break;
      else high = target;
    }
    /* cout << target << endl; */
    midY = target;
  }
  // b. search middle x val
  int midX = 0;
  {
    // low always 0 (high is maxY + 1 to make it even)
    int low = 0, high = maxX+1, top = 0, bottom = 0, target = 0;

    while (low < high) {
      if (abs(high-low) == 2) break;

      target = (high+low) / 2;
      if (target % 2 != 0) target++;

      top = countcowssection(target, 0, 2);
      bottom = countcowssection(target, 0, 3);

      /* cout << top << " " << bottom << " " << target << endl; */
      if (top == n/2 || top == n/2 + 1) break;

      if (top < bottom) low = target;
      else if (top == bottom) break;
      else high = target;
    }
    /* cout << target << endl; */
    midX = target;
  }


  cout << countcows(midX, midY) << endl;
  
  
  // output

  return 0;
}
