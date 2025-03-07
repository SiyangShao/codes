#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << 15 << "\n";
  for (int i = 0; i < (1 << 15); i++) {
    cout << rand() % 2;
  }
  cout << "\n";
}
