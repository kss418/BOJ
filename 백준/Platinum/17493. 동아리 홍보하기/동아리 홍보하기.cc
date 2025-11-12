#include <bits/stdc++.h>
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
vector <ll> tmp[MAX];
bool v[MAX];
ll p[MAX], ind[MAX], mx[MAX], mn[MAX], result;
deque <ll> q;

void dfs(ll cur, ll pre = -1){
    v[cur] = 1;
    for(auto& nxt : tmp[cur]){
        if(nxt == pre) continue;
        p[nxt] = cur; ind[cur]++;
        dfs(nxt, cur);
    }
}

void run(){
    cin >> n >> m;
    while(m--){
        ll s, e; cin >> s >> e;
        tmp[s].push_back(e);
        tmp[e].push_back(s);
    }

    memset(p, -1, sizeof(p));
    for(int i = 1;i <= n;i++){
        if(v[i]) continue;
        dfs(i);
    }

    memset(mn, 0x3f, sizeof(mn));
    memset(mx, 0xc0, sizeof(mx));
    for(int i = 1;i <= n;i++){
        if(ind[i]) continue;
        q.push_back(i);
        mx[i] = mn[i] = 1;
    }

    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(mn[cur] + mx[cur] <= 1) mx[cur] = mn[cur];
        if(mx[cur] > 1){
            mx[cur] = mn[cur] = -1; result++;
        }

        ll nxt = p[cur];
        if(nxt == -1){
            if(mx[cur] >= 1) result++;
            continue;
        }

        mn[nxt] = min(mn[nxt], mn[cur] + 1);
        mx[nxt] = max(mx[nxt], mx[cur] + 1);
        if(!--ind[nxt]) q.push_back(nxt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}