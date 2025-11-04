#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll a[MAX], b[MAX], fac[MAX];

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

void run(){
    cin >> n >> m; _comb c(MAX, MOD); fac[0] = 1;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];
    for(int i = 1;i < MAX;i++) fac[i] = (fac[i - 1] * i) % MOD;

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    ll mn = INF, result = 1, cnt = m;
    for(int i = m;i >= 1;i--){
        if(m - i + 1 > n) break;
        mn = min(mn, a[m - i + 1] + b[i]);
    }

    for(int i = m + 1;i <= n;i++) mn = min(mn, a[i]);
    for(int i = 1;i <= n;i++){
        if(a[i] < mn){ 
            ll lb = lower_bound(b + 1, b + m + 1, mn - a[i]) - b;
            result *= cnt - lb + 1; cnt--; 
            result %= MOD;
        }
        else{
            ll sum = 0, all = n - i + 1;
            for(int j = 0;j <= min(all, cnt);j++){
                ll mul = c.ret(all, j), now = c.ret(cnt, j);
                ll f = fac[j];
                sum += ((mul * now) % MOD * f) % MOD;
                sum %= MOD; 
            }

            result *= sum; result %= MOD;
            break;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}
