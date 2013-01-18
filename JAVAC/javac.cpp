#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void covertToJava(string c) {
  char a[1000];
  int index = 0;
  bool f = false;
  for(int i = 0; i < c.length(); i++) {
    if ((c[i] > 64) && c[i] < 91) {
      cout << "Error!" << endl;
      return;
    }
    if (f && (c[i] == '_')) {
      cout << "Error!" << endl;
      return;
    }
    if (f && (96 < c[i]) && (c[i] < 123)) {
      a[index] = c[i] - 32;
      index++;
      f = false;
    } else if (c[i] == '_') {
      if (i == c.length() - 1) {
        a[index] = c[i];
        index++;
      } else {
        f = true;
      }
    } else {
      a[index] = c[i];
      index++;
    }
  }
  a[index] = '\0';
  cout << a << endl;
}

void covertToC(string c) {
  char a[1000];
  int index = 0;
  for(int i = 0; i < c.length(); i++) {
    if ((c[i] > 64) && c[i] < 91) {
      a[index] = '_';
      index++;
      a[index] = c[i] + 32;
      index++;
    } else {
      a[index] = c[i];
      index++;
    }
  }
  a[index] = '\0';
  cout << a << endl;
}

void transfor(string c) {
  if (c.length() == 0) {
    return;
  }
  if (c[0] > 122 || c[0] < 97) {
    cout << "Error!" << endl;
    return;
  }
  if (c[c.length() - 1] == '_') {
    cout << "Error!" << endl;
    return;
  }
  if (c.find("_") != string::npos) {
    covertToJava(c);
  } else {
    covertToC(c);
  }
}


int main() {
  string s;
  while(!cin.eof()) {
    getline(cin, s);
    transfor(s);
  }
  return 0;
}

