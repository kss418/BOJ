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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 1e9 + 7;
ll a[MAX], cnt[10];

class _inv {
public:
    _inv() {}
    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll ret(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }
}; _inv inv;

class _matrix{ //0-based index
public:
    ll n, m, mod;
    vector <vector<ll>> arr;

    _matrix(){}
    _matrix(ll n, ll m, ll mod = 998244353){
        this->n = n; this->m = m; this->mod = mod;
        arr.resize(n, vector<ll>(m));
    }
    void add(ll n, ll m, ll num){ 
        arr[n][m] += num % mod; 
        arr[n][m] %= mod;
    }
    void update(ll n, ll m, ll num){ arr[n][m] = num % mod; }

    _matrix operator *(_matrix& ot){
        _matrix ret(n, ot.m, mod);
        for(int i = 0;i < n;i++){
            for(int k = 0;k < m;k++){
                ll now = arr[i][k];
                for(int j = 0;j < ot.m;j++){
                    ret.arr[i][j] = (ret.arr[i][j] + now * ot.arr[k][j]) % mod;
                }
            }
        }
        return ret;
    }

    _matrix operator +(_matrix &ot){
        _matrix ret(n, m, mod);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++) ret.arr[i][j] = arr[i][j] + ot.arr[i][j];
        }
        return ret;
    }
    
    _matrix pow(_matrix& cur, ll k){ // n * n matrix
        _matrix ret(n, m, mod);
        for(int i = 0;i < n;i++) ret.arr[i][i] = 1;
        while(k > 0){
            if(k & 1) ret = ret * cur;
            cur = cur * cur;
            k >>= 1ll;
        }
        return ret;
    }

    ll ret(ll n, ll m) { return arr[n][m]; }
    friend ostream& operator<<(ostream& out, _matrix &cur){
        for(int i = 0;i < cur.n;i++){
            for(int j = 0;j < cur.m;j++) out << cur.arr[i][j] << " ";
            out << "\n";
        }
        return out;
    }
};

void run(){
    ll x; cin >> n >> m >> k >> x;
    for(int i = 1;i <= n;i++) cin >> a[i], cnt[a[i]]++;

    _matrix b(x, 1, MOD), a(x, x, MOD);
    for(int i = 0;i < x;i++){
        for(int j = 1;j <= 9;j++){
            a.add((10 * i + j) % x, i, cnt[j]);
        }
    }   

    b.update(0, 0, 1);
    a = a.pow(a, m);
    b = a * b;

    cout << b.ret(k, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}