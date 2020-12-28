#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll N = 1e5 + 7;
ll n;
ll h[N], to[N], lef[N], rig[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    h[n + 1] = INT_MAX;
    stack<ll> st;
    st.push(1);
    for (int i = 2; i <= n + 1; ++i) {
        while (!st.empty() && h[i] > h[st.top()]) {
            to[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; ++i) {
        lef[i + 1]++;
        if (to[i] != n) {
            lef[(i + to[i]) / 2 + 1]--;
        }
    }
    for (int i = 1; i <= n; ++i) {
        lef[i] += lef[i - 1];
    }
    while (!st.empty()) {
        st.pop();
    }
    h[0] = INT_MAX;
    st.push(n);
    for (auto i = n - 1; i >= 0; --i) {
        while (!st.empty() && h[i] > h[st.top()]) {
            to[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    for (auto i = 1; i <= n; ++i) {
        rig[i - 1]++;
        if (to[i] != 1) {
            rig[(i + to[i] + 1) / 2 - 1]--;
        }
    }
    for (auto i = n; i >= 1; --i) {
        rig[i] += rig[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        cout << lef[i] + rig[i] << " ";
    }
}