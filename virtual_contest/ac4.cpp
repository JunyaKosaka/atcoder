#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i:x){cout << i << " ";} cout << endl;}
#define isin(x,l,r) ((l)<=(x) && (x)<(r))
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using tii=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template<typename T>bool chmin(T&x,const T&y) {if(x>y){x=y;return true;} else return false;}
template<typename T>bool chmax(T&x,const T&y) {if(x<y){x=y;return true;} else return false;}

int main() {
    long double T, L, X, Y;
    cin >> T >> L >> X >> Y;
    long double PI = acos(-1);
    int Q;
    cin >> Q;
    rep(i, Q) {
        long double E;
        cin >> E;
        long double x = 0, y, z;
        y = L / 2 * cos(- PI / 2 - PI * 2 * E / T);
        z = L / 2 + L / 2 * sin(- PI / 2 - PI * 2 * E / T);
        long double ans = atan2(z, sqrt((X-x) * (X-x) + (Y-y) * (Y-y))) * 180 / PI;
        printf("%.10Lf\n", ans);
    }
    return 0;
}
