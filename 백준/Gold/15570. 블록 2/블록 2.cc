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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 1999;
ll dp[MAX];

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
    cin >> n >> m; _matrix mat(n, n, MOD);
    _pow pow; _matrix ret(n, 1, MOD);

    if(n == 1){
        cout << 1; return;
    }
    else if(m == n){
        cout << pow.ret(2, m, MOD) - 1;
        return;
    }
    else if(m < n){
        cout << pow.ret(2, m - 1, MOD);
        return;
    }
    
    for(int i = 0;i < n - 1;i++) mat.add(i + 1, i, 1);
    for(int i = 0;i < n;i++) mat.add(0, i, 1);
    for(int i = n - 1;i >= 1;i--) ret.add(i, 0, pow.ret(2, n - i - 1, MOD));

    ret.update(0, 0, (pow.ret(2, n, MOD) + MOD - 1) % MOD);
    mat.update(0, n - 1, pow.ret(2, n - 1, MOD));
    mat = mat.pow(mat, m - n);
    ret = mat * ret;

    cout << ret.ret(0, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

