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

ll digsum(ll n){
    ll a = 0;
    while (n) {
        a += n%10;
        n /= 10;
    }
    return a;
}

int cal(int x) {
    int ret = (x + digsum(x)) % 100000;
    return ret;
}

int cycle_move(int start, ll k, int(*func)(int)) {
    // 循環する数列のk番目を返す
    vector<int> A;
    map<int, int> mp;
    int cur = start, ind = 0;
    while (!mp.count(cur)) {
        A.push_back(cur);
        mp[cur] = ind++;
        cur = func(cur);
    }
    if (sz(A) > k) return A[k];
    k -= mp[cur];
    k %= ind - mp[cur];
    return A[mp[cur] + k];
}

int main() {
    int N;
    ll k;
    cin >> N >> k;
    int ans = cycle_move(N, k, cal);
    cout << ans << '\n';
    return 0;
}
