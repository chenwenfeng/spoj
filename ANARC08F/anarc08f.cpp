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

map<string, int> locations;

int totalCost;
int N;
int C;
int R;


int main() {
  char s[11];
  char n1[11];
  char n2[11];
  char c1, c2;
  int cost;
  int caseIndex = 0;
  while(true) {
    totalCost = 0;
    int nindex = 0;
    scanf("%d %d %d\n", &N, &C, &R);
    string cars[C];
    // cout << N << ":" << C << ":" << R << endl;
    if(N == 0 && C == 0 && R == 0) {
      // cout << "break"<< endl;
      break;
    }
    caseIndex++;

    int dis[N][N];
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        dis[i][j] = inf;
      }
    }

    for(int i = 0; i < N; i++) {
      dis[i][i] = 0;
    }

    scanf("%s", s);
    locations.insert(pair<string, int>(s, nindex));
    nindex++;
    // cout << "source:" << s << endl;
    for(int i = 0; i < C; i++) {
      scanf("%s", s);
      if (!locations.count(s)) {
        locations.insert(pair<string, int>(s, nindex));
        nindex++;
      }
      cars[i] = s;
      // cout << "car" << i << ": " << s << endl;
    }

    for(int i = 0; i < R; i++) {
      scanf("%s %c-%d-%c %s\n", n1, &c1, &cost, &c2, n2);
      // cout << n1 << c1 << "-" << cost << "-" << c2 << n2 << endl;
      if(!locations.count(n1)) {
        locations.insert(pair<string, int>(n1, nindex));
        nindex++;
      }
      if(!locations.count(n2)) {
        locations.insert(pair<string, int>(n2, nindex));
        nindex++;
      }
      if(c1 == '<') {
        dis[locations[n2]][locations[n1]] = min(dis[locations[n2]][locations[n1]], cost);
      }
      if(c2 == '>') {
        dis[locations[n1]][locations[n2]] = min(dis[locations[n1]][locations[n2]], cost);
      }
    }
    for(int k = 0; k < N; k++) {
      for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
          if (dis[i][k] + dis[k][j] < dis[i][j]) {
            dis[i][j] = dis[i][k] + dis[k][j];
          }
        }
      }
    }
    for(int i = 0; i < C; i++) {
      totalCost += dis[0][locations[cars[i]]];
      totalCost += dis[locations[cars[i]]][0];
    }
    cout << caseIndex << ". " << totalCost << endl;
    locations.clear();
    // delete[] cars;
  }
  return 0;
}

