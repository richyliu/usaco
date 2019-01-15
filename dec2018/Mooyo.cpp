#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)
#define for2(x, y) fori(x) forj(y)

#define printarr(arr, x) fori(x) cout << arr[i];
#define printarr2(arr, x, y) fori(x) {\
  forj(y) cout << arr[i][j]; \
  cout << endl; \
}
#define printmat(mat) printarr2(mat, N, 10); cout << endl;

#define checkboard(x, y, target) \
  x >= 0 && y >= 0 && x < height && y < width && !checked[x][y] && board[x][y] == target
#define checkboardif(dx, dy) \
  if (checkboard(next.first + dx, next.second + dy, match)) { \
    cells.push(loc(next.first + dx, next.second + dy)); \
    remove.push(loc(next.first + dx, next.second + dy)); \
    checked[next.first + dx][next.second + dy] = true; \
  }



short board[100][10];
bool checked[100][10];

typedef pair<short, short> loc;

bool remove_connected(int row, int col, int height, int width, int K) {
  queue<loc> cells;
  queue<loc> remove;
  short match = board[row][col];

  cells.push(loc(row, col));

  loc next;
  while (!cells.empty()) {
    next = cells.front();
    cells.pop();

    // match other contiguous region
    checkboardif(0, 1);
    checkboardif(0, -1);
    checkboardif(1, 0);
    checkboardif(-1, 0);
  }

  if ((int)remove.size() < K) return false;
  while (!remove.empty()) {
    next = remove.front();
    remove.pop();

    board[next.first][next.second] = 0;
  }

  return true;
}

void apply_gravity(int height, int width) {
  int swapwith = 0;
  for(int i = 0; i < width; i++) {
    swapwith = height - 1;
    for(int j = height - 1; j >= 0; j--) {
      if (board[j][i] != 0) {
        while (board[swapwith][i] != 0 && swapwith > 0) swapwith--;
        if (swapwith <= j) continue;
        board[swapwith][i] = board[j][i]; 
        board[j][i] = 0;
        swapwith--;
      }
    }
  }
}

int main() {
  ifstream cin; cin.open("mooyomooyo.in");
  ofstream cout; cout.open("mooyomooyo.out");

  int N = 0;
  int K = 0;
  cin >> N;
  cin >> K;
  char temp;
  for2(N, 10) {
    cin >> temp;
    board[i][j] = temp - 48;
  }

  short numRemoved = 0;
  do {
    numRemoved = 0;
    for2(N, 10) checked[i][j] = false;
    for2(N, 10)
      if (board[i][j] > 0 && !checked[i][j])
        numRemoved += remove_connected(i, j, N, 10, K);
    apply_gravity(N, 10);
  } while (numRemoved > 0);

  printarr2(board, N, 10);

  return 0;
}
