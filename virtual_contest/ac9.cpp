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
	int N, L, K;
	cin >> N >> L >> K;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	A.push_back(L);
	N++;
	for (int i = N-1; i > 0; i--) {
		A[i] -= A[i-1];
	}
	ll ok = 0; ll ng = 1e9 + 10;
	while (abs(ng - ok) > 1) {
		ll mid = (ok + ng) / 2;
		bool bl = [&] {
			int cnt = 0;
			int cur = 0;
			rep(i, N) {
				if (cur + A[i] >= mid) {
					cnt++;
					cur = 0;
				} else {
					cur += A[i];
				}
			}
			if (cur < mid) cnt--;
			return cnt >= K;
		}();
		if (bl) ok = mid;
		else ng = mid;
	}
	cout << ok << '\n';
	return 0;
}
