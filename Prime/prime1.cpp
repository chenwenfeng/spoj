#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

#define COUNT 31628 // sqrt(1000000000)

bool v[COUNT];
int v2[3402];
int v3[3402];

void a() {
  memset(v,true, COUNT * sizeof(bool));
  for(int i = 2; i < COUNT; i++) {
        // cout << "i=" << i << endl;
    if(v[i]) {
      int x = i * i;
      // cout << x << endl;
      while(x <= COUNT) {
        // cout << "i=" << i << "; " << x << "<=" << COUNT << "=" << (x <= COUNT) << endl;
        v[x] = false;
        x += i;
      }
    }
  }
  int c = 0;
  for(int i = 2; i < COUNT; i++) {
    if(v[i]) {
      v2[c] = i;
      v3[c] = i * i;
      c++;
      // cout << i << ":" << i * i << endl;
    }
  }
  // cout << "c:" << c << endl;
}

void c(int m, int n) {
  if (m <= 2 && n>=2) {
    cout << 2 << endl;
    m = 3;
  }
  if (m % 2 == 0) {
    m++;
  }
  // int c = 0;
  for(int i = m; i <= n; i+=2) {
    bool f = true;
    // cout << "xx" <<endl;
    for(int j = 0; j < 3402; j++) {
      // c++;
      if(i % v2[j] == 0) {
        f = false;
        break;
      }
      if (i <= v3[j]) {
        break;
      }
    }
    // int j = 0;
    // while(i >= v3[j]) {
    //   cout << i << ":" << v3[j] << endl;
    //   if(i % v2[j] == 0) {
    //     f = false;
    //   }
    //   j++;
    // }
    if (f) {
      cout << i << endl;
    }
  }
  // cout << c << endl;
  cout << endl;
}

int main() {
  int count;
  string t;
  getline(cin, t);
  stringstream ss;
  ss << t;
  ss >> count;
  a();
  for(int i = 0; i < count; i++) {
    getline(cin, t);
    int x = t.find(" ");
    int m = atoi(t.substr(0, x).c_str());
    int n = atoi(t.substr(x + 1, t.length()).c_str());
    c(m, n);
  }
  return 0;
}
