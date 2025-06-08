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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;

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
    void update(ll n, ll m, ll num){ arr[n][m] = num; }

    _matrix operator *(_matrix& ot){
        _matrix ret(n, ot.m, mod);
        for(int i = 0;i < n;i++){
            for(int k = 0;k < m;k++){
                ll now = arr[i][k];
                for(int j = 0;j < ot.m;j++){
                    ret.arr[i][j] = (ret.arr[i][j] + now * ot.arr[k][j]);
                    if(ret.arr[i][j]) ret.arr[i][j] = 1;
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
    cin >> n >> m >> k; _matrix arr(n, n, 1ll << 62);
    for(int i = 1;i <= n;i++){
        ll s, e; cin >> s >> e;
        arr.update(i - 1, s - 1, 1);
        arr.update(i - 1, e - 1, 1);
    }

    arr = arr.pow(arr, m);
    while(k--){
        ll s, e; cin >> s >> e;
        cout << (arr.ret(s - 1, e - 1) ? "death" : "life") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

