#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>

using namespace std;

const int inf = INT_MAX >> 1;

int cl;
vector<pair <int, int> > * vmap;
map<string, int> cities;
int * dis;
int disL;
bool * mark;

int lowbit(int x){
  return x&(-x);
}

void si(int c) {
  while(lowbit(c) != c) {
    c += lowbit(c);
  }
  disL = c;
}

void createIndex() {
  for(int i = 0; i < 2 * disL - 1; i++) {
    dis[i] = inf;
  }
}

void updateIndex(int index, int value) {
  int i = index + disL - 1;
  dis[i] = value;

  while (i) {
    int pi = (i - 1) / 2;
    int pv = min(dis[pi * 2 + 1], dis[pi * 2 + 2]);
    if (dis[pi] == pv) break;
    dis[pi] = pv;
    i = pi;
  }

  // cout<< "x"<<endl;
  // for(int i = 0; i < disL * 2; i++) {
  //   cout << dis[i] << endl;
  // }
}

int getMinIndex() {
  int x = 0;
  while(x < disL - 1) {
    if(dis[x] == dis[x * 2 + 1]) {
      x = x * 2 + 1;
    } else {
      x = x * 2 + 2;
    }
  }
  return x - (disL - 1);
}

void dijkstra(int src, int tar) {
  createIndex();
  updateIndex(src, 0);
  while(true) {
    int k = getMinIndex();
    int v = dis[0];
    if (v == inf) {
      exit(1);
    }
    mark[k] = true;
    updateIndex(k, inf);
    if (k == tar) {
      cout << v << endl;
      break;
    }
    vector<pair<int, int> >::iterator iter;
    for( iter = vmap[k].begin(); iter != vmap[k].end(); iter++ ) {
      if (mark[iter->first] == false) {
        int vv = iter->first;
        int ccc = iter->second;
        int t = ccc + v;
        if (dis[vv + disL - 1] > t) {
          updateIndex(vv, t);
        }
      }
    }
  }

}

int main() {
  int count;
  char t[11];
  scanf("%d\n", &count);
  // int f = 2;
  for(int i = 0; i < count; i++) {
    int c;
    scanf("%d\n", &c);
    cl = c;
    vmap = new vector<pair<int, int> >[cl];
    si(cl);
    dis = new int[disL * 2 - 1];
    for(int j = 0; j < c; j++) {
      scanf("%s\n", t);
      cities.insert(pair<string, int>(t, j));
      int p;
      scanf("%d\n", &p);
      for(int m = 0; m < p; m++) {
        int nr, cost;
        scanf("%d %d\n", &nr, &cost);
        vmap[j].push_back(pair<int, int>(nr - 1, cost));
      }
    }
    int r;
    scanf("%d\n", &r);
    for(int n = 0; n < r; n++) {
      mark = new bool[cl];
      memset(mark, false,sizeof(bool)*cl);
      char name1[11], name2[11];
      scanf("%s %s\n", name1, name2);
      int index1 = cities[name1];
      int index2 = cities[name2];
      // if (f > 0) {
        dijkstra(index1, index2);
        // f--;
      // }
      delete[] mark;
    }
    delete[] vmap;
    delete[] dis;
    cities.clear();
    scanf("\n");
  }
  return 0;
}
