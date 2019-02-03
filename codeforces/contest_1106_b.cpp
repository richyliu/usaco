#include <iostream>
#include <algorithm>
using namespace std;


#define fori(x) for(int i = 0; i < x; i++)
#define forj(x) for(int j = 0; j < x; j++)


struct Dish {
  int num;
  int cost;
  int i;
};

bool comp(Dish a, Dish b) {
  return a.cost < b.cost;
}


int main() {
  int n, m;
  cin >> n >> m;

  Dish dishes[n];
  fori(n)
    cin >> dishes[i].num;
  fori(n) {
    cin >> dishes[i].cost;
    dishes[i].i = i;
  }

  Dish sortedDishes[n];
  fori(n)
    sortedDishes[i] = dishes[i];
  
  sort(sortedDishes, sortedDishes + n, comp);

  int sorted[n];
  fori(n)
    sorted[i] = sortedDishes[i].i;

  /* fori(n) */
  /*   cout << dishes[sorted[i]].cost << " " << dishes[sorted[i]].i << endl; */


  int cheapest = 0;
  fori(m) {
    // dish customer wants to buy
    int dish = -1;
    // number of dishes to buy
    int num = -1;
    long long total = 0;

    cin >> dish >> num;
    dish--;

    if (cheapest >= n) {
      cout << 0 << endl;
      continue;
    }
    if (dishes[dish].num > 0) {
      if (num > dishes[dish].num) {
        total += dishes[dish].cost * dishes[dish].num;
        num -= dishes[dish].num;
        dishes[dish].num = 0;
        // bought out cheapest
        if (dish == sorted[cheapest]) {
          while (cheapest < n && dishes[sorted[cheapest]].num == 0)
            cheapest++;
        }
      } else {
        total += dishes[dish].cost * num;
        dishes[dish].num -= num;
        num = 0;
      }
    }
    while (cheapest < n && dishes[sorted[cheapest]].num == 0)
      cheapest++;
    // while customer still wants to buy dishes (cheap ones)
    while (num > 0) {
      if (cheapest >= n) {
        total = 0;
        break;
      }
      if (num > dishes[sorted[cheapest]].num) {
        total += dishes[sorted[cheapest]].cost * dishes[sorted[cheapest]].num;
        num -= dishes[sorted[cheapest]].num;
        dishes[sorted[cheapest]].num = 0;
      } else {
        total += dishes[sorted[cheapest]].cost * num;
        dishes[sorted[cheapest]].num -= num;
        num = 0;
      }
      while (cheapest < n && dishes[sorted[cheapest]].num == 0)
        cheapest++;
    }

    cout << total << endl;
  }

  return 0;
}
