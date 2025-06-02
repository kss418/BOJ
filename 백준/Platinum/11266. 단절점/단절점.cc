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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

class _bcc{ // 1-based index
public:
    vector <vector <ll>> adj;
    vector <ll> mn, seq;
    ll n, cnt;

    _bcc(ll n) : n(n) {
        adj.resize(n + 1);
    }

    void add(ll s, ll e){
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    void clear(){
        seq.clear(); mn.clear(); cnt = 0;
        seq.resize(n + 1); mn.resize(n + 1);
    }

    void dfs_point(vector <ll>& arr, ll cur, ll pre = -1){
        bool flag = 0; ll now = 0;
        seq[cur] = mn[cur] = ++cnt;

        for(auto& nxt : adj[cur]){
            if(nxt == pre) continue;
            
            if(seq[nxt]) mn[cur] = min(mn[cur], seq[nxt]);
            else{   
                dfs_point(arr, nxt, cur); now++;
                mn[cur] = min(mn[cur], mn[nxt]);
                if(pre != -1 && mn[nxt] >= seq[cur]) flag = 1;
            }
        }

        if(pre == -1 && now >= 2) flag = 1;
        if(flag) arr.push_back(cur);
    }

    // 단절점 반환
    vector <ll> point(){
        vector <ll> ret; clear();
        for(int i = 1;i <= n;i++){
            if(seq[i]) continue;
            dfs_point(ret, i);
        }

        return ret;
    }

    // 단절선 반환
    vector <pll> line(){

    }

    // bcc 반환
    vector <vector <pll>> ret(){

    }
};

void run(){
    cin >> n >> m; _bcc bcc(n);
    while(m--){
        ll s, e; cin >> s >> e;
        bcc.add(s, e);
    }

    vector <ll> result = bcc.point();
    sort(all(result));

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

