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
constexpr ll MOD = 1e9 + 7;
ll p[MAX], q[MAX], result;

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
    cin >> n >> m >> k;
    _matrix mat(n + 2, n + 2, MOD);
    while(m--){
        ll s, e; cin >> s >> e; s--; e--;
        mat.add(s, e, 1); mat.add(e, s, 1);
    }

    ll sz[2]; cin >> sz[0] >> sz[1];
    for(int i = 1;i <= sz[0];i++) {
        cin >> p[i], p[i]--;
        mat.add(n, p[i], 1);
    }

    for(int i = 1;i <= sz[1];i++) {
        cin >> q[i], q[i]--;
        mat.add(q[i], n + 1, 1);
    }
    mat.add(n + 1, n + 1, 1);
    mat = mat.pow(mat, k + 2);
    ll ret = mat.ret(n, n + 1);
    
    for(int i = 1;i <= sz[0];i++){
        for(int j = 1;j <= sz[1];j++){
            if(p[i] == q[j]) ret--;
        }
    }

    cout << (ret + MOD) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}