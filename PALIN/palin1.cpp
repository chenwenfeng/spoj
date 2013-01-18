#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string add(string s) {
  bool f = true;
  int length = s.length();
  for(int i = length - 1; i >= 0; i--) {
    if (f) {
      if (s[i] == '9') {
        if (i == 0) {
          s[i] = '0';
          s = "1" + s;
          f = false;
        } else {
          s[i] = '0';
          f = true;
        }
      } else {
        stringstream ss;
        stringstream ss1;
        ss << s[i];
        int a;
        ss >> a;
        a++;
        ss1 << a;
        s.replace(i, 1, ss1.str());
        f = false;
      }
    }
  }
  return s;
}

void bu(string sub, int size) {
  int l = sub.length();
  for (int i = l; i < l + size; i++) {
    stringstream ss;
    string ts;
    char c = sub[l + size - i - 1];
    ss << c;
    ss >> ts;
    sub.append(ts);
  }
  cout << sub << endl;
}

bool comp(string l, string r) {
  int le = l.length();
  for (int i = 0; i < le; i++) {
    if (l[le - i - 1] < r[i] ) {
      return false;
    } else if (l[le - i - 1] > r[i] ) {
      return true;
    }
  }
  return true;
}

void deal(string n) {
  int le = n.length();
  if (le == 1) {
    cout << n << endl;
  } else {
    if (le % 2 == 0) {
      if (comp(n.substr(0, le / 2), n.substr(le / 2, le / 2))) {
        bu(n.substr(0, le / 2), le / 2);
      } else {
        string ss = add(n.substr(0, le / 2));
        bu(ss, le / 2);
      }
    } else {
      if (comp(n.substr(0, le / 2), n.substr(le / 2 + 1, le / 2))) {
        bu(n.substr(0, le / 2 + 1), le / 2);
      } else {
        string ss = add(n.substr(0, le / 2 + 1));
        bu(ss, le / 2);
      }
    }
  }
}


int main() {
  int count;
  string t;
  getline(cin, t);
  stringstream ss;
  ss << t;
  ss >> count;
  for(int i = 0; i < count; i++) {
    getline(cin, t);
    t = add(t);
    deal(t);
  }
  return 0;
}
