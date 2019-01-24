#include <bits/stdc++.h>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define printarr(arr, x) fori(x) cout << arr[i];
#define printarr2(arr, x, y) fori(x) {\
  forj(y) cout << arr[i][j]; \
  cout << endl; \
}
#define printmat(mat) printarr2(mat, N, N); cout << endl;

#define checkboard(x, y) x >= 0 && y >= 0 && x < N && y < N && !checked[x][y] && board[x][y]
#define checkboardnocheck(x, y) (x < 0 || y < 0 || x >= N || y >= N) || !board[x][y]
#define checkboarddir(next, dx, dy) checkboard((next.first + dx), (next.second + dy))
#define checkboarddirnocheck(next, dx, dy) checkboardnocheck(next.first + dx, next.second + dy)

#define checkboardif(dx, dy) \
  if (checkboarddir(next, dx, dy)) { \
    cells.push(loc(next.first + dx, next.second + dy)); \
    countInArea.push(loc(next.first + dx, next.second + dy)); \
    checked[next.first + dx][next.second + dy] = true; \
  }


typedef vector<vector<bool>> boolmat;
typedef pair<short, short> loc;


int main() {
  ifstream cin; cin.open("perimeter.in");
  ofstream fout; fout.open("perimeter.out");


  // input
  int maxArea = 0;
  int minPerimeter = INT_MAX;

  int N = 0;
  cin >> N;
  char temp;

  boolmat board (N, vector<bool>(N, 0));
  boolmat checked (N, vector<bool>(N, 0));

  for2(N, N) {
    cin >> temp;
    board[i][j] = temp == '#';
  }


  // process
  queue<loc> cells;
  queue<loc> countInArea;
  loc next;
  int curArea = 0;
  int curPerimeter = 0;

  for2(N, N) {
    curArea = 0;
    curPerimeter = 0;
    if (checked[i][j] || !board[i][j]) continue;

    cells.push(loc(i, j));

    while (!cells.empty()) {
      next = cells.front();
      cells.pop();

      // match other contiguous region
      checkboardif(0, 1);
      checkboardif(0, -1);
      checkboardif(1, 0);
      checkboardif(-1, 0);

      if (countInArea.size() == 0 && cells.size() == 0)
        countInArea.push(next);
    }

    curArea = countInArea.size();
    while (!countInArea.empty()) {
      next = countInArea.front();
      countInArea.pop();

      if (checkboarddirnocheck(next, 0, 1)) curPerimeter++;
      if (checkboarddirnocheck(next, 0, -1)) curPerimeter++;
      if (checkboarddirnocheck(next, 1, 0)) curPerimeter++;
      if (checkboarddirnocheck(next, -1, 0)) curPerimeter++;
    }

    cout << curArea << " " << curPerimeter << endl;
    if (curArea == maxArea) {
      minPerimeter = min(minPerimeter, curPerimeter);
    }
    if (curArea > maxArea) {
      maxArea = curArea;
      minPerimeter = curPerimeter;
    }
  }

  /* cout << endl << "board: " << endl; */
  /* printmat(board); */
  cout << maxArea << " " << minPerimeter << endl;
  fout << maxArea << " " << minPerimeter << endl;

  return 0;
}
