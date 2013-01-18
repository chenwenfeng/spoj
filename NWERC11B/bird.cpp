#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

void c(int a, int b) {
  if (a > b) {
    cout << "R";
    c(b, a - b);
  } else if (a < b) {
    cout << "L";
    c(b - a, a);
  } else {
    cout << endl;
    return;
  }
}

int main() {
  int count;
  string s;
  getline(cin, s);
  stringstream ss;
  ss << s;
  ss >> count;
  for(int i = 0; i < count; i++) {
    getline(cin, s);
    int t = s.find("/");
    int a = atoi(s.substr(0, t).c_str());
    int b = atoi(s.substr(t + 1, s.length()).c_str());
    c(a, b);
  }
  return 0;
}
