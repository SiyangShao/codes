#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 1e4 + 10;
int a[N];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        bool st = true;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (a[n] == 0) {
            for (int i = 1; i <= n + 1; i++)
                cout << i << " ";
            cout << endl;
            continue;
        } else if (a[1] == 1) {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        } else {
            int pos = n;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 0 && a[i + 1] == 1) {
                    st = false;
                    pos = i;
                    break;
                }
            }

            if (!st) {
                for (int i = 1; i <= pos; i++)
                    cout << i << " ";
                cout << n + 1 << " ";
                for (int i = pos + 1; i <= n; i++) {
                    cout << i;
                    if (i != n)
                        cout << " ";
                }
                cout << endl;
            } else
                puts("-1");
        }
    }

    return 0;
}