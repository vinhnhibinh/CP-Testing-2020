#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const int N=300005;
int n, k, a[N];
double psum[N], res = 0.0;

bool check(double x) {
    for (int i=1;i<=n;i++) {
        psum[i] = psum[i-1] + a[i] - x;
    }
    double cur = 0;
    for (int i=k; i<=n; i++) {
        if (psum[i]>=cur) {
            return true;
        }
        cur = min(cur,psum[i-k+1]);
    }
    return false;
}

int32_t main(void) {
    FastIO;
    freopen("SELL.INP","r",stdin);
    freopen("SELL.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    
    double l = 0, r = 1e6, mid;
    while (r-l>1e-6) {
        double mid=(l+r)/2;
        if (check(mid)) {
            l = mid;
        }
        else r = mid;
    }
    res = l;

    cout<<fixed<<setprecision(6)<<res;
    return 0;
}