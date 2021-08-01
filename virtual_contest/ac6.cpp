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

int conv(int x, int right) {
    return (x - right + N) % N;
}

int main() {
    int Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int right = 0;
    rep(i, Q) {
        int t, x, y;
        cin >> t >> x >> y;
        --x; --y;
        if (t == 1) {
            x = conv(x, right);
            y = conv(y, right);
            swap(A[x], A[y]);
        } else if (t == 2) {
            right = (right + 1) % N;
        } else if (t == 3) {
            x = conv(x, right);
            cout << A[x] << '\n';
        }
    }
    return 0;
}
