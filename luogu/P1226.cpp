#include <bits/stdc++.h>
//快速幂S
using namespace std;
typedef long long ll;
ll t, b, p, k, ans = 1;
int main()
{
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=";
    while (p > 0)
    {
        if (p % 2 == 1)
            ans *= b % k;
        ans %= k;
        b = b * b % k;
        p = p >> 1;
    }
    if(b==1&&p==0&&k==1){
        cout<<0<<endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}