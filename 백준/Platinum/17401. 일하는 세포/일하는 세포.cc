#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
constexpr ll MAX = 21;
constexpr ll MOD = 1e9 + 7;
ll adj[MAX][MAX][101];
ll sum[MAX][MAX][101];
ll tmp[MAX][MAX];


class _ms{ //0-based index
public:
    ll n, m;
    vector <vector<ll>> arr, result, tmp;
    vector <ll> num;

    _ms(){}
    _ms(ll n, ll m = 998244353){ 
        this->n = n; this->m = m; 
        arr.resize(n, vector<ll>(n));
        result.resize(n, vector<ll>(n));
        tmp.resize(n, vector<ll>(n));
        num.resize(n);
        for(int i = 0;i < n;i++) result[i][i] = 1;
    }

    void add(ll cy, ll cx, ll val){ arr[cy][cx] = val % m; }
    void fi(ll cx, ll val){ num[cx] = val % m; }

    void cal(bool flag){
        for(int i = 0;i < n;i++) memset(&tmp[i][0], 0, sizeof(tmp[i][0]) * tmp[i].size());
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                for(int k = 0;k < n;k++) {
                    if(flag) tmp[i][j] += result[i][k] * arr[k][j];
                    else tmp[i][j] += result[i][k] * result[k][j];
                    tmp[i][j] %= m;
                }
            }
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++) result[i][j] = tmp[i][j] % m;
        }
    }
    
    void init(ll k){
        stack <ll> com; 
        while(k > 0){
            com.push(k & 1);
            if(k & 1) k--; else k >>= 1;
        }
        while(!com.empty()){
            bool cur = com.top();
            cal(cur); com.pop();
        }
    }

    ll ret(ll cy, ll cx){ return result[cy][cx]; }
};

int main() {
    fastio;

    cin >> n >> m >> k; _ms ms(m, MOD);
    for(int i = 0;i < n;i++){
        cin >> t;
        while(t--){
            ll s, e, c; cin >> s >> e >> c;
            s--; e--;
            adj[s][e][i] = c;
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++) sum[i][j][0] = adj[i][j][0];
    }

    for(int i = 1;i < n;i++){
        for(int j = 0;j < m;j++){
            for(int k = 0;k < m;k++) {
                for(int l = 0;l < m;l++){
                    sum[j][k][i] += sum[j][l][i - 1] * adj[l][k][i];
                    sum[j][k][i] %= MOD;
                }
            }
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++) ms.add(i, j, sum[i][j][n - 1]);
    }
    for(int i = 0;i < m;i++) ms.fi(i, 1);
    ms.init(k / n);

    ll mod = k % n;
    if(mod) for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++) {
            for(int k = 0;k < m;k++){
                tmp[i][j] += ms.result[i][k] * sum[k][j][mod - 1];
                tmp[i][j] %= MOD;
            }
        }
    }

    if(mod) for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++) ms.result[i][j] = tmp[i][j];
    }

    memset(tmp, 0, sizeof(tmp));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            tmp[i][j] += ms.result[i][j] * ms.num[j];
            tmp[i][j] %= MOD;
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++) cout << ms.ret(i, j) << " ";
        cout << "\n";
    }
    
    
    return 0;
}