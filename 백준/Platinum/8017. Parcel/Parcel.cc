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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], sum[MAX][MAX], result;

class _uf { 
public:
    ll n; vector <ll> p, si;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1); si.resize(n + 1, 1);
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

    ll size(ll num){ return si[find(num)]; }
    bool same(ll a, ll b) { return find(a) == find(b); }
};

void solve(ll cur){
    _uf uf(n + 1);
    vector <pll> arr;

    for(int i = 1;i <= n;i++){
        arr.push_back({sum[cur][i], i});
    }
    sort(all(arr)); reverse(all(arr));

    for(auto& [v, idx] : arr){
        if(sum[cur][idx - 1] >= v) uf.merge(idx, idx - 1);
        if(sum[cur][idx + 1] >= v) uf.merge(idx, idx + 1);
        result = max(result, v * uf.size(idx));
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cin >> a[i][j];
        a[i][0] = a[i][n + 1] = MINF;
    }

    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= n;j++){
            if(a[i][j]) continue;
            sum[i][j] = sum[i + 1][j] + 1;
        }
    }

    for(int i = 1;i <= n;i++) solve(i);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

