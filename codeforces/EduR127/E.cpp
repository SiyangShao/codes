// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define caseT                                                                  \
    int CaseT;                                                                 \
    cin >> CaseT;                                                              \
    for (int _Case = 1; _Case <= CaseT; _Case++)
#define IOS                                                                    \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);                                                                \
    cout.tie(0);                                                               \
    cout << fixed << setprecision(12)

using LL = long long;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using ULL = unsigned long long;

mt19937 mrand(random_device{}());
LL rnd(LL x) { return mrand() % x; }
LL power(int a, int b, int p = 998244353) {
    LL ret = 1;
    for (; b; b >>= 1, a = 1ll * a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
constexpr int P = 998244353;

// assume -p <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template <class T> T power(T a, int b) {
    T res = 1;
    for (; b; b >>= 1, a *= a)
        if (b & 1)
            res *= a;
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    [[nodiscard]] int val() const { return x; }
    Z operator-() const { return (norm(P - x)); }
    [[nodiscard]] Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (long long)(x)*rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend istream &operator>>(istream &input, Z &lhs) {
        input >> lhs.x;
        return input;
    }
    friend ostream &operator<<(ostream &output, const Z &lhs) {
        output << lhs.val();
        return output;
    }
};

int multi_cases = 0;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int tot = 1 << n;
    vector<Z> f(1 << (n + 1), 1LL);

    function<string(int)> dfs = [&](int u) -> string {
        if (u >= (1 << n))
            return "";
        if (u * 2 >= tot)
            return string("") + s[u];

        string lson = dfs(u << 1);
        string rson = dfs(u << 1 | 1);
        f[u] = f[u << 1] * f[u << 1 | 1] * (lson != rson ? 2 : 1);
        if (lson > rson)
            swap(lson, rson);
        return string("") + s[u] + lson + rson;
    };

    dfs(1);
    cout << f[1] << endl;
}

int main() {

    IOS;
    int _ = 1;
    if (multi_cases)
        cin >> _;
    for (; _; _--)
        solve();
    return 0;
}