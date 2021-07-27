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

int N;

void solve(string s, int i, int diff) {
    if (i == N-1) {
        if (diff == 1) cout << s + ')' << '\n';
        return;
    }
    solve(s+'(', i+1, diff+1);
    if (diff > 0) solve(s+')', i+1, diff-1);
}

int main() {
    cin >> N;
    solve("", 0, 0);
    return 0;
}
