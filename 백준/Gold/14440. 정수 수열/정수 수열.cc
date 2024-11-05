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
constexpr ll MAX = 201010;
constexpr ll MOD = 100;


class _matrix{ //0-based index
public:
    ll n, m, mod;
    vector <vector<ll>> arr;

    _matrix(){}
    _matrix(ll n, ll m, ll mod = 998244353){
        this->n = n; this->m = m; this->mod = mod;
        arr.resize(n, vector<ll>(m));
    }
    void add(ll n, ll m, ll num){ arr[n][m] += num % mod; }
    void update(ll n, ll m, ll num){ arr[n][m] = num % mod; }

    _matrix operator *(_matrix& ot){
        _matrix ret(n, ot.m, mod);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < ot.m;j++){
                for(int k = 0;k < m;k++){
                    ret.arr[i][j] += (arr[i][k] * ot.arr[k][j]) % mod;
                    ret.arr[i][j] %= mod;
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
        if(!k){
            for(int i = 0;i < n;i++) ret.arr[i][i] = 1;
            return ret;
        }

        ret = pow(cur, k >> 1);
        ret = ret * ret;
        if(k & 1) ret = ret * cur;
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

int main() {
    fastio;

    ll x, y, a, b; cin >> x >> y >> a >> b >> n;
    _matrix mt(2, 2, MOD), fi(2, 1, MOD);
    
    mt.add(0, 0, x); mt.add(0, 1, y);
    mt.add(1, 0, 1);

    fi.add(0, 0, b); fi.add(1, 0, a);
    mt = mt.pow(mt, n); mt = mt * fi;

    ll ret = mt.ret(1, 0);
    cout << ret / 10 << ret % 10;


    return 0;
}

