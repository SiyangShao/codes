#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string solve() {
    queue<string> q;
    for (int i = 0; i <= 25; ++i) {
        char ch = 'a' + i;
        string _;
        _.push_back(ch);
        q.push(_);
    }
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        if (s.find(u) == string::npos)
            return u;
        for (int i = 0; i <= 25; ++i) {
            char ch = 'a' + i;
            u.push_back(ch);
            q.push(u);
            u.pop_back();
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        cout << solve() << endl;
    }
    return 0;
}
