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
    int N;
    cin >> N;
    vector<int> D(3);
    rep(i, 3) cin >> D[i];
    sort(D.begin(), D.end());
    int A = D[0], B = D[1], C = D[2];
    int ans = 1e4;
    for (int i = 0; i < 10000; i++) {
        if (i * A > N) break;
        for (int j = 0; i + j < 10000; j++) {
            if (i * A + j * B > N) break;
            if ((N - (i*A + j*B)) % C == 0){
                int temp = i + j + (N - (i*A + j*B)) / C;
                chmin(ans, temp);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
