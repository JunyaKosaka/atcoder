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

int func(ll n) {
    int ret = 0;
    for (ll i = 2; i*i <= n; ++i) {
        if (n%i) continue;
        while (n%i == 0) {
            ret++;
            n /= i;
        }
    }
    if (n != 1) ret++;
    return ret;
}

int main() {
    ll N;
    cin >> N;
    int ans = ceil(log2(func(N)));
    cout << ans << '\n';    
    return 0;
}
