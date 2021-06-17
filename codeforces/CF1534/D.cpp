#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<int> vis(n + 1, 0);

    cout << "? " << 1 << "\n";
    cout.flush();

    ll odd = 0, even = 0;

    set<pair<ll, ll>> st;
    vector<ll> check(n + 1, 0), bip(n + 1, 0);
    for (ll i = 1; i < n + 1; i++) {
        cin >> check[i];
        bip[i] = check[i] % 2;

        if (check[i] % 2)
            odd++;
        else
            even++;

        if (check[i] == 1)
            st.insert({1, i});
    }

    if (even <= odd) {
        for (ll i = 2; i < n + 1; i++) {
            if (bip[i] == 0) {
                cout << "? " << i << "\n";
                cout.flush();
                vector<ll> temp(n + 1, 0);
                for (ll j = 1; j < n + 1; j++) {
                    cin >> temp[j];
                    if (temp[j] == 1) {
                        ll x = i;
                        ll y = j;
                        if (y < x)
                            swap(x, y);
                        st.insert({x, y});
                    }
                }
            }
        }
    } else {
        for (ll i = 2; i < n + 1; i++) {
            if (bip[i] == 1) {
                cout << "? " << i << "\n";
                cout.flush();
                vector<ll> temp(n + 1, 0);
                for (ll j = 1; j < n + 1; j++) {
                    cin >> temp[j];
                    if (temp[j] == 1) {
                        ll x = i;
                        ll y = j;
                        if (y < x)
                            swap(x, y);
                        st.insert({x, y});
                    }
                }
            }
        }
    }
    cout << "!\n";
    for (auto c : st)
        cout << c.first << " " << c.second << "\n";

    cout.flush();
}