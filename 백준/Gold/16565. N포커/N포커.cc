#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 61;
constexpr ll MOD = 10007;

class _comb{
public:
    vector <ll> fac, inv; ll n, mod;
    _comb(ll n, ll m = 998244353){ // m == MOD && m == prime
        fac.resize(n + 1); inv.resize(n + 1);
        this->mod = m; this->n = n;

        fac[0] = 1; 
        for(int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i % mod;
        inv[n] = pow(fac[n], mod - 2, mod);
        for(int i = n - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    }

    ll pow(ll a, ll p, ll mod) {
		if (!p) return 1;
		if (p == 1) return a % mod;

		ll cur = pow(a, p / 2, mod);
		cur = cur * cur % mod;
		if (p % 2 == 0) return cur % mod;
		return (cur * a) % mod;
	}

    ll ret(ll n, ll m){ // return nCm
        if(n < 0 || m < 0 || n < m) return 0;
        return fac[n] * inv[m] % mod * inv[n - m] % mod;
    }
};

int main() {
    fastio;

    cin >> n; _comb comb(MAX, MOD);

    ll result = 0;
    for(int i = 1;i <= n / 4;i++){
        ll pair = comb.ret(13, i);
        ll ot = comb.ret(52 - 4 * i, n - 4 * i);

        ll now = (pair * ot) % MOD;
        if(i % 2) result += now;
        else result -= now;

        result %= MOD;
        if(result < 0) result += MOD; 
    }

    cout << result;


    return 0;
}

