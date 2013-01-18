#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> v1;
vector<string> v;

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
  int length = sub.length();
  if (length == size) {
    for(int i = size; i <= length + size - 1; i++) {
      stringstream ss;
      string ts;
      char c = sub[length + size - i - 1];
      ss << c;
      ss >> ts;
      sub.append(ts);
    }
  } else {
    for(int i = length; i <= length + size - 1; i++) {
      stringstream ss;
      string ts;
      char c = sub[length + size - i - 1];
      ss << c;
      ss >> ts;
      sub.append(ts);
    }
  }
  v.push_back(sub);
}

void transfor(string s, int start) {
  // cout << s << "xx" << start << endl;
  int st = (s.length() % 2 == 0) ? s.length() / 2 : s.length() / 2 + 1;
  if (s.length() % 2 == 0) {
    if (start < st) {
      string sub = s.substr(0, start + 1);
      sub = add(sub);
      bu(sub, start + 1);
    } else if(start == st) {
      string sub = s.substr(0, start + 1);
      sub = add(sub);
      bu(sub, s.length() - start - 1);
    } else {
      bu(s.substr(0, s.length() / 2), s.length() / 2);
    }
  } else {
    if (start < st) {
      string sub = s.substr(0, start + 1);
      sub = add(sub);
      bu(sub, s.length() - start - 1);
    } else {

      bu(s.substr(0, s.length() / 2 + 1), s.length() - start);
    }
  }
}

void deal(string n) {
  bool f = true;
  if (n.length() == 1) {
    v.push_back(n);
  } else {
    int start = (n.length() % 2 == 0) ? n.length() / 2 : n.length() / 2 + 1;
    for(int i = start; i < n.length(); i++) {
      if (n[i] > n[n.length() - i - 1]) {
        if (i == n.length() - 1) {
          int tt = (n.length() % 2 == 0) ? n.length() / 2 : n.length() / 2;
          transfor(n, tt);
          f = false;
          break;
        } else {
          transfor(n, i - 1);
          f = false;
          break;
        }
      }
    }
    if (f) {
      if (n.length() % 2 == 0) {
        bu(n.substr(0, n.length() / 2), n.length() - start);
      } else {
        bu(n.substr(0, n.length() / 2 + 1), n.length() - start);
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
    v1.push_back(t);
  }
  for (int i = 0; i < v1.size(); i++) {
    deal(v1[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
  return 0;
}
