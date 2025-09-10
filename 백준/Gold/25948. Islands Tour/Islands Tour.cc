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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll nxt[MAX], ind[MAX], num[MAX], dp[MAX];
deque <ll> q;
bool v[MAX];

void dfs(ll cur){
    v[cur] = 1; num[cur]++; 
    if(nxt[cur] == -1) return;
    if(v[nxt[cur]]) return;

    num[nxt[cur]] += num[cur];
    dfs(nxt[cur]);
    num[cur] = num[nxt[cur]];
    nxt[cur] = -1;
}

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 1;

    if(num[nxt[cur]]) ret += num[nxt[cur]];
    else ret += solve(nxt[cur]);

    return ret;
}

void run(){
    cin >> m >> n;
    memset(dp, -1, sizeof(dp));
    memset(nxt, -1, sizeof(nxt));

    while(m--){
        ll s, e; cin >> s >> e;
        nxt[s] = e; ind[e]++;
    }

    for(int i = 0;i < n;i++){
        if(!ind[i]) q.push_back(i);
    }

    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(nxt[cur] == -1) continue;
        if(!--ind[nxt[cur]]) q.push_back(nxt[cur]);
    }

    for(int i = 0;i < n;i++){
        if(!ind[i]) continue;
        if(!v[i]) dfs(i);
    }

    ll result = 0;
    for(int i = 0;i < n;i++){
        if(num[i]) result = max(result, num[i]);
        else result = max(result, solve(i));
    }

    cout << result;
}       

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}