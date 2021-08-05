#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i:x){cout << i << " ";} cout << endl;}
#define isin(x,l,r) ((l)<=(x) && (x)<(r))
using namespace std;
using ll=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using tii=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template<typename T>bool chmin(T&x,const T&y) {if(x>y){x=y;return true;} else return false;}
template<typename T>bool chmax(T&x,const T&y) {if(x<y){x=y;return true;} else return false;}

const int MOD = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    ll val() const { return x;}
    mint inv() const { return pow(MOD-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
// combination MOD prime
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
    mint p(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[n-k];
    }
}; //comb(10000007); // ←MOD-1が上限
// comb(5, 2) → 10, comb.p(5, 2) → 20
// comb.fact[4] → 24, 2のN乗 → mint(2).pow(N)

int numberOfDigits(ll x) {
    // 自然数の桁数を返す
    int res = 0;
    if (x == 0) return 1;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

ll pow(ll a,ll n){ll x=1;for(;n;n/=2)n&1?x=x*a:0,a=a*a;return x;}
ll pom(ll a,ll n,int m = MOD){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}

mint sum(ll x, ll y) {
    mint ret = mint(x + y) * mint(y - x + 1) / 2;
    return ret;
}

int main() {
    ll L, R;
    cin >> L >> R;
    int dL = numberOfDigits(L);
    int dR = numberOfDigits(R);
    mint ans = 0;
    for (int i = dL; i <= dR; i++) {
        mint left = pom(10, i-1);
        mint right = pom(10, i) - 1;
        if (i == dL) left = L;
        if (i == dR) right = R;
        ans += (left + right) * (right - left + 1) * i / 2;
    }
    cout << ans.val() << '\n';
    return 0;
}
