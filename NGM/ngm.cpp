#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  int x;
  cin >> x;
  int xx = x % 10;
  if (xx == 0) {
    cout << 2 << endl;
  } else {
    cout << 1 << endl;
    cout << xx << endl;
  }
  return 0;
}
