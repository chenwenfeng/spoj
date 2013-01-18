#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int* table(int nl, string needle) {
  int *T = new int[nl];
  int index;
  T[0] = -1;
  for(int i=1;i<nl;++i) {
    index = T[i-1];
    while(index>=0 && needle[i]!=needle[index+1]) {
      index = T[index];
    }
    if(needle[i]==needle[index+1]) {
      T[i] = index + 1;
    } else {
      T[i] = -1;
    }
  }
  // cout << "next:";
  // for(int i=0;i<nl;++i) {
  //   cout<<" " << T[i];
  // }
  // cout << endl;
  return T;
}

void cacu(int nl, string W, const int* T) {
  int m = 0;
  int i = 0;
  char c = getchar();
  while((c != '\n') && i < nl) {
    if (W[i] == c) {
      m++;
      i++;
      c = getchar();
    } else if(i == 0) {
      c = getchar();
      m++;
    } else {
      i = T[i - 1] + 1;
    }
    if(i == nl) {
      cout << m - i << endl;
      i = T[i - 1] + 1;
    }
  }
  cout << endl;
}

int main() {
    int length;
  while(cin >> length) {
    string needle;
    getline(cin, needle);
    getline(cin, needle);
    int* t = table(length, needle);
    cacu(length, needle, t);
    delete[] t;
  }
  return 0;
}
