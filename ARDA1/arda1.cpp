#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int N1, N2, M1, M2;

// int* table(int nl, string needle) {
//   int *T = new int[nl];
//   int index;
//   T[0] = -1;
//   for(int i=1;i<nl;++i) {
//     index = T[i-1];
//     while(index>=0 && needle[i]!=needle[index+1]) {
//       index = T[index];
//     }
//     if(needle[i]==needle[index+1]) {
//       T[i] = index + 1;
//     } else {
//       T[i] = -1;
//     }
//   }
//   // cout << "next:";
//   // for(int i=0;i<nl;++i) {
//   //   cout<<" " << T[i];
//   // }
//   // cout << endl;
//   return T;
// }

// void cacu(int nl, string W, const int* T) {
//   int m = 0;
//   int i = 0;
//   char c = getchar();
//   while((c != '\n') && i < nl) {
//     if (W[i] == c) {
//       m++;
//       i++;
//       c = getchar();
//     } else if(i == 0) {
//       c = getchar();
//       m++;
//     } else {
//       i = T[i - 1] + 1;
//     }
//     if(i == nl) {
//       cout << m - i << endl;
//       i = T[i - 1] + 1;
//     }
//   }
//   cout << endl;
// }

int main() {
  scanf("%d %d\n", &N1, &N2);
  char N[N1][N2];
  char t;
  for(int i = 0; i < N1; i++) {
    for(int j = 0; j < N2; j++) {
      scanf("%c", &t);
      N[i][j] = t;
    }
    scanf("\n");
  }
  scanf("%d %d\n", &M1, &M2);
  char M[M1][M2];
  for(int i = 0; i < M1; i++) {
    for(int j = 0; j < M2; j++) {
      scanf("%c", &t);
      M[i][j] = t;
    }
    scanf("\n");
  }

  // table
  int T[N1][N2];
  int index;
  T[0][0] = -1;
  for(int i = 0; i < N1; i++) {
    for(int j = 0; j < N2; j++) {
      if(i == 0 && j == 0) {
        continue;
      }
      int y = j == 0 ? N2 - 1 : j - 1;
      int x = y == N2 - 1 ? i - 1 : i;
      index = T[x][y];
      while(index >= 0 && N[i][j] != N[(index+1) / N2][(index + 1) % N2]) {
        index = T[index/N2][index%N2];
      }
      if(N[i][j] == N[(index+1) / N2][(index + 1) % N2]) {
        T[i][j] = index + 1;
      } else {
        T[i][j] = -1;
      }
    }
  }
  // for(int i = 0; i < N1; i++) {
  //   for(int j = 0; j < N2; j++) {
  //     cout << T[i][j];
  //   }
  //   cout << endl;
  // }

  // caculate
  int m = 0;
  int i = 0;
  int xx = 0;
  char c = M[0][0];
  while((m < M1*M2) && i < N1*N2) {
    cout << "N[" << i/N2 << "][" << i%N2 << "]=" << N[i/N2][i%N2]<< endl;
    cout << "M["<<m/M2<<"]["<<m%M2<<"]="<<c<<endl;
    cout << "-------------"<<endl;
    if (N[i/N2][i%N2] == c) {
      i++;
      if(i/N2 == (i-1)/N2) {
        m++;
      } else {
        m = (m/M2 + 1)*M2 + m%M2 -N2 + 1;
      }
      // cout << "m=" << m << endl;
      c = M[m/M2][m%M2];
    } else if(i == 0) {
      if(i/N2 == (i+1)/N2) {
        m++;
      } else {
        m = (m/M2 + 1)*M2 + m%M2 -N2 + 1;
      }
      c = M[m/M2][m%M2];
    } else {
      i = T[(i - 1)/N2][(i-1)%N2] + 1;
    }
    if(i == N2*N1) {
      cout << i << ":" << m << endl;
      cout << "(" << m/M2 - N2 + 2 << "," << (m - i)%M2+1 << ")" << endl;
      i = T[(i - 1)/N2][(i-1)%N2] + 1;
    }
  }


  // cout << N1 << " " << N2 << endl;
  // for(int i = 0; i < N1; i++) {
  //   for(int j = 0; j < N2; j++) {
  //     cout << N[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << M1 << " " << M2 << endl;
  // for(int i = 0; i < M1; i++) {
  //   for(int j = 0; j < M2; j++) {
  //     cout << M[i][j];
  //   }
  //   cout << endl;
  // }
  return 0;
}
