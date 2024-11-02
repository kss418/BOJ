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
constexpr ll MAX = 30101;
constexpr ll MOD = 998244353;
ll a[MAX], sum[MAX], dp[MAX][3010];

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1); si.resize(n + 1);
        fill(all(p), -1);
        fill(all(si), 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (a < b) swap(a, b);
        sum[a] += sum[b];
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

vector <pll> arr;
int main() {
    fastio;

    cin >> n >> m >> k; _uf uf(n);
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; sum[i] = a[i];
    }
    
    while(m--){
        ll s, e; cin >> s >> e;
        uf.merge(s, e);
    }

    arr.push_back({0, 0});
    for(int i = 1;i <= n;i++){
        if(uf.find(i) != i) continue;
        arr.push_back({sum[i], uf.size(i)});
    }

    ll result = 0;
    for(int i = 1;i <= arr.size();i++){
        auto&[v, si] = arr[i];
        for(int j = 0;j < k;j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= si) dp[i][j] = max(dp[i][j], dp[i - 1][j - si] + v);

            result = max(result, dp[i][j]);
        }
    }
    
    cout << result;


    return 0;
}

