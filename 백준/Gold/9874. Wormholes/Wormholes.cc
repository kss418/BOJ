#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <ll> vec, adj[MAX];
map <ll, vector<pll>> ym;
bool in[MAX], flag, v[MAX];
ll op[MAX], result;

void dfs(ll cur){
    if(v[cur]){
        flag = 1;
        return;
    }
    v[cur] = 1;

    for(auto& nn : adj[cur]){
        ll nxt = op[nn];
        dfs(nxt);
    }
}

void bt(){
    if(vec.size() == n){
        for(int i = 0;i < n;i += 2){
            op[vec[i]] = vec[i + 1];
            op[vec[i + 1]] = vec[i];
        }

        flag = 0;
        for(int i = 1;i <= n;i++){
            memset(v, 0, sizeof(v)); dfs(i);
        }

        result += flag; return;
    }

    for(int i = (vec.size() % 2 ? vec.back() + 1 : (vec.empty() ? 1 : vec[vec.size() - 2] + 1));i <= n;i++){
        if(in[i]) continue;
        in[i] = 1;
        vec.push_back(i);
        bt();
        vec.pop_back();
        in[i] = 0;
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        ym[a[i].y].push_back({a[i].x, i});
    }

    for(auto&[y, v] : ym){
        sort(all(v));
        for(int i = 1;i < v.size();i++){
            adj[v[i - 1].y].push_back(v[i].y);
        }
    }

    bt();
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}