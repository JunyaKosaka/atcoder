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
ll pow(ll a,ll n){ll x=1;for(;n;n/=2)n&1?x=x*a:0,a=a*a;return x;}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    bool bl = A < pow(C, B);
    puts(bl ? "Yes" : "No");
    return 0;
}
