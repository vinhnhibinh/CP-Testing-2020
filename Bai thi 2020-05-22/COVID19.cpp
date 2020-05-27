#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
using namespace std;

const int N = 100005;
int n, m, R, c[N], r[N];
struct data { int q, p; } a[N];
int f[N], g[N];
int res = 0;

int32_t main(void) {
    FastIO;
    freopen("COVID19.INP","r",stdin);
    freopen("COVID19.OUT","w",stdout);
    cin >> n >> m >> R;
    for (int i=1; i<=n; i++){
        cin >> c[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> a[i].q >> a[i].p;
    }
    for (int i=1; i<=R; i++) {
        cin >> r[i];
    }

    sort(c+1, c+n+1);
    sort(r+1, r+R+1, greater<int>());
    sort(a+1, a+m+1, [](const data &u, const data &v) {
        return u.p > v.p;
    });

    int j = 1, k, l;
    for (int i=1; i<=n; i++) {
        if (i<=R) {
            g[i] = g[i-1] + r[i];
        } else {
            g[i] = g[i-1];
        }
        k = n-i+1;
        f[k] = f[k+1];
        l = c[k];
        while (l>0 && j<=m) {
            int cur_q = a[j].q;
            if (l>a[j].q) {
                f[k] += (a[j].p*a[j].q);
                l -= a[j].q;
                j++;
                continue;
            }
            f[k] += (a[j].p*l);
            a[j].q -= l;
            cur_q = a[j].q;
            break;
        }
    }
    
    for (int i=0; i<=n; i++) {
        res = max(res, g[i]+f[i+1]);
    }
    cout << res;
    return 0;
}
