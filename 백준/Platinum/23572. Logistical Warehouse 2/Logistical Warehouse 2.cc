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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> tmp[MAX];
ll p[MAX], ind[MAX], result, mx[MAX], mn[MAX];
deque <ll> q;

void init(ll cur = 1, ll pre = -1){
    for(auto& nxt : tmp[cur]){
        if(nxt == pre) continue;
        p[nxt] = cur;
        ind[cur]++;
        init(nxt, cur);
    }
}

void run(){
    cin >> n >> m; memset(p, -1, sizeof(p));
    memset(mx, 0xc0, sizeof(mx));
    memset(mn, 0x3f, sizeof(mn));
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        tmp[s].push_back(e);
        tmp[e].push_back(s);
    }

    init();
    for(int i = 1;i <= n;i++){
        if(!ind[i]){
            q.push_back(i);
            mx[i] = mn[i] = 1;
        }
    }

    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(mx[cur] + mn[cur] <= 1) mx[cur] = mn[cur];
        if(mx[cur] > m) mx[cur] = mn[cur] = -m, result++;

        ll nxt = p[cur];
        if(nxt == -1){
            if(mx[cur] > 0) result++;
            break;
        }

        mx[nxt] = max(mx[nxt], mx[cur] + 1);
        mn[nxt] = min(mn[nxt], mn[cur] + 1);
        if(!--ind[nxt]) q.push_back(nxt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}