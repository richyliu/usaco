#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef queue<int> qi;

struct lookable {
  int index;
  vi pathTo;
};

int N;
vi paths[100001];


vi dijkstra(int start, int end) {
  bool lookedAt[N];
  fori(N) lookedAt[i] = false;

  // indicies to search
  queue<lookable> look;
  look.push({ start, vi(1, start) });
  lookedAt[start] = true;

  while(!look.empty()) {
    /* cout << "look size: " << int(look.size()) << "\n"; */

    lookable cur = look.front();
    look.pop();

    vi newVec;
    for(int el : paths[cur.index]) {
      if (!lookedAt[el]) {
        if (el == end) {
          cur.pathTo.emplace_back(end);
          return cur.pathTo;
        } else {
          /* cout << "el: " << el << "\n"; */
          newVec = cur.pathTo;
          newVec.emplace_back(el);
          look.push({ el, newVec });
          lookedAt[el] = true;
        }
      }
    }
  }

  return vi();
}


ifstream fin;
void fastscan(int &number) {
  bool negative = false;
  int c;
  number = 0;

  c = fin.get();
  if (c == '-') {
    negative = true;
    c = fin.get();
  }

  for (; (c>47 && c<58); c=fin.get())
    number = number *10 + c - 48;

  if (negative) number *= -1;
}


int main() {
  fin.open("cowland.in");
  ofstream fout; fout.open("cowland.out");

  ios_base::sync_with_stdio(false);


  /* Input */

  int Q = 0;
  fastscan(N);
  fastscan(Q);

  int enjoyments[N];
  fori(N) fastscan(enjoyments[i]);

  int from = 0, to = 0;
  fori(N-1) {
    fastscan(from);
    fastscan(to);
    from--;
    to--;
    paths[from].emplace_back(to);
    paths[to].emplace_back(from);
  }


  /* Processing */

  int type = 0;
  from = 0;
  to = 0;
  fori(Q) {
    fastscan(type);
    fastscan(from);
    fastscan(to);
    if (type == 2) {
      from--; to--;
      vi route = dijkstra(from, to);
      int cur = 0;
      for (int el : route)
        cur ^= enjoyments[el];
      /* cout << cur << "\n"; */
      fout << cur << "\n";
    } else {
      from--;
      enjoyments[from] = to;
    }
  }



  /* Output */


  return 0;
}
