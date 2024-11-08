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
constexpr ll MAX = 5010;
constexpr ll MOD = 1e9 + 7;
ll dp[MAX][MAX], num[MAX];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, -1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a, si[a] += si[b];
    }

    ll size(ll num){
        return si[find(num)];
    }

    ll same(ll a, ll b) {
        if (find(a) == find(b)) return 1;
        return 0;
    }
};


int main() {
    fastio;

    cin >> n >> m; _uf uf(n); ll cnt = n;

    dp[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] = (dp[i - 1][j - 1] % MOD) + (dp[i - 1][j] * j % MOD);
            dp[i][j] %= MOD;
        }
    }

    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= i;j++) {
            num[i] += dp[i][j];
            num[i] %= MOD;
        }
    }

    while(m--){
        ll s, e; cin >> s >> e;
        if(!uf.same(s, e)) uf.merge(s, e), cnt--;
    
        cout << num[cnt] << "\n";
    }
    
    
    return 0;
}