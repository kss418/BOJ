#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX], tc;
class _es { // flag (1 == prime / 2 == phi / 4 == mobius)
public:
    ll n; vector <ll> pv, pn, mov, phiv;
    vector <bool> v;
    _es(){}
    _es(ll n, ll flag = 1) {
        this->n = n;

        if(flag & 1){
            pv.resize(n + 1, -1); pv[1] = 1;
            for (ll i = 2;i <= n;i++) {
                if(pv[i] != -1) continue; pv[i] = i;
                pn.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    if(pv[j] == -1) pv[j] = i;
                }
            }
        }

        if(flag & 2){
            phiv.resize(n + 1); iota(all(phiv), 0);
            v.resize(n + 1);
            for(ll i = 2;i <= n;i++){
                if(v[i]) continue;
                for(ll j = i;j <= n;j += i){
                    phiv[j] /= i; phiv[j] *= (i - 1); v[j] = 1;
                }
            }
        }

        if(flag & 4){
            mov.resize(n + 1, -2);
            mov[0] = 0; mov[1] = 1;
            for(ll i = 2;i <= n;i++){
                if(mov[i] != -2) continue; mov[i] = -1;
                for(ll j = 2 * i;j <= n;j += i) {
                    if(mov[j] == -2) mov[j] = 1;
                    mov[j] *= -1;
                }
                for(ll j = i * i;j <= n; j += i * i) mov[j] = 0;
            }
        }
    }

    ll mp(ll n) { return pv[n]; } // 최소 소인수 반환
    vector<ll>& ret() { return pn; } // 소수 벡터 반환
    bool prime(ll n) { // 소수 판별
        if (n == 1) return 0;
        return pv[n] == n;
    }
    ll mobius(ll n){ return mov[n]; }
    ll phi(ll n){ return phiv[n]; }
}; _es es;

ll cnt[1010];
map <ll, ll> mp;

class _pow {
public:
    _pow() {}

    ll ret(ll a, ll b){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a;
            a *= a; b >>= 1;
        }      
        return ret;
    }

    ll ret(ll a, ll b, ll p){
        ll ret = 1;
        while(b){
            if(b & 1) ret *= a % p, ret %= p;
            a *= a; a %= p; b >>= 1;
        }      
        return ret;
    }
};

void run(){
    cin >> n >> m; mp.clear();
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];

    for(int i = 1;i <= n;i++){
        for(auto& j : es.ret()){
            if(j * j > a[i]) break;
            while(a[i] % j == 0) a[i] /= j, cnt[j]++;
        }

        if(a[i] <= 1000) cnt[a[i]]++;
        else mp[a[i]]++;
    }

    for(int i = 1;i <= m;i++){
        for(auto& j : es.ret()){
            if(j * j > b[i]) break;
            while(b[i] % j == 0) b[i] /= j, cnt[j]--;
        }

        if(b[i] <= 1000) cnt[b[i]]--;
        else mp[b[i]]--;
    }

    ll a = 1, b = 1; _pow pow;
    for(int i = 2;i <= 1000;i++){
        if(cnt[i] > 0) a *= pow.ret(i, cnt[i]);
        else if(cnt[i] < 0) b *= pow.ret(i, -cnt[i]);
    }

    for(auto& [v, c] : mp){
        if(c > 0) a *= pow.ret(v, c);
        else if(c < 0) b *= pow.ret(v, -c);
    }

    cout << "Case #" << ++tc << ": " << a << " / " << b << "\n";
}

int main() {
    fastio; cin >> t;
    es = {1010101};
    while(t--) run(); 

    return 0;
}