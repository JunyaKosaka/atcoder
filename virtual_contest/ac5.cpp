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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int main() {
    ll A, B;
    cin >> A >> B;
    const ll INF = 1e18;
    ll g = gcd(A, B);
    ll C = A / g;
    if (INF / C < B) puts("Large");
    else cout << C * B << '\n';
    return 0;
}
