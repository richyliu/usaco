#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef queue<int> qi;

unordered_map<string, int> cache;

struct lookable {
  int index;
  vi pathTo;
};

int N;
vi paths[100001];
int enjoyments[100000];


string hash2(int a, int b) {
  ostringstream stringStream = ostringstream();
  stringStream << a << " " << b;
  return stringStream.str();
}


int bfs(int start, int end) {
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

          int result = 0;
          for (int el : cur.pathTo)
            result  ^= enjoyments[el];
          return result;
        } else {
          /* cout << "el: " << el << "\n"; */
          cout << "req: " << el << " -> " << end << endl;
          if (cache.find(hash2(el, end)) != cache.end()) {
            cout << "cache req: " << cache[hash2(el, end)] << endl;
            int result = 0;
            for (vi::size_type i = 0; i < cur.pathTo.size(); i++) {
              result ^= enjoyments[cur.pathTo[i]];
              cout << "OOO " << enjoyments[cur.pathTo[i]] << endl;
            }
            result ^= enjoyments[el];
            cout << "OOO " << enjoyments[el] << endl;
            result ^= cache[hash2(el, end)];
            cout << "OOO " << cache[hash2(el, end)] << endl;
            return result;
          }

          newVec = cur.pathTo;
          newVec.emplace_back(el);
          look.push({ el, newVec });
          lookedAt[el] = true;
        }
      }
    }
  }

  cout << "oh no!\n";
  return -1;
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
      int result = bfs(from, to);

      cache[hash2(from, to)] = result;
      cout << "path " << from << " -> " << to << " ...";
      cout << result << "\n";
      /* fout << result << "\n"; */
    } else {
      from--;
      enjoyments[from] = to;
    }
  }



  /* Output */


  return 0;
}
