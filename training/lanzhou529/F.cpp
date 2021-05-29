#include <bits/stdc++.h>
using namespace std;
int _, n;
string s;
int F, e, i, M, a;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--) {
        cin >> n >> s;
        F = 0, e = 0, i = 0, M = 0, a = 0;
        int t = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == 'F') {
                F++;
            } else if (s[j] == 'e') {
                if (F)
                    e++;
            } else if (s[j] == 'i') {
                if (F && e)
                    i++;
            } else if (s[j] == 'M') {
                if (F && e && i)
                    M++;
            } else if (s[j] == 'a') {
                if (F && e && i && M) {
                    F=0,e=0,i=0,M=0;
                    t++;
                }
            }
        }
        cout << t << "\n";
    }
}