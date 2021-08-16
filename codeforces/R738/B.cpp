#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int beg = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                beg = i;
                break;
            }
        }
        if (beg == -1) {
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            }
            cout << s << "\n";
        } else {
            for (int i = beg - 1; i >= 0; i--) {
                if ((beg - i) % 2 == 1) {
                    if (s[beg] == 'B') {
                        s[i] = 'R';
                    } else {
                        s[i] = 'B';
                    }
                } else {
                    if (s[beg] == 'B') {
                        s[i] = 'B';
                    } else {
                        s[i] = 'R';
                    }
                }
            }
            for (int i = beg + 1; i < n; ++i) {
                if (s[i] != '?') {
                    beg = i;
                } else {
                    if ((i - beg) % 2 == 1) {
                        if (s[beg] == 'B') {
                            s[i] = 'R';
                        } else {
                            s[i] = 'B';
                        }
                    } else {
                        if (s[beg] == 'B') {
                            s[i] = 'B';
                        } else {
                            s[i] = 'R';
                        }
                    }
                }
            }
            cout<<s<<"\n";
        }
    }
}