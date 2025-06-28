#include <bits/stdc++.h>
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
int d[1ll << MAX], pre[1ll << MAX], use[1ll << MAX];
vector <int> adj[MAX];
deque <int> q;

void init(){
    for(int i = 0;i < n;i++) adj[i].clear();
    for(int i = 0;i < (1ll << n);i++){
        d[i] = 1e9;
        pre[i] = use[i] = -1;
    }
}

void solve(ll n, ll m){
    int now = (1ll << n) - 1;
    d[now] = 0;

    for(int i = 0;i < n;i++){
        int nxt = now & ~(1ll << i);
        d[nxt] = 1;
        q.push_back(nxt);
        pre[nxt] = now;
        use[nxt] = i;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();

        int nxt = 0;
        for(int i = 0;i < n;i++){
            if(cur & (1ll << i)){
                for(auto& j : adj[i]) nxt |= (1ll << j);
            }
        }

        for(int i = 0;i < n;i++){
            if(!(nxt & (1ll << i))) continue;
            int num = nxt & ~(1ll << i);

            if(d[num] <= d[cur] + 1) continue;
            pre[num] = cur; use[num] = i;
            d[num] = d[cur] + 1;
            q.push_back(num);
        }
    }

    if(d[0] >= 1e9) cout << "Impossible\n";
    else{
        vector <int> result; int now = 0;
        while(1){
            bool flag = 0;
            int nxt = pre[now];
            if(nxt == -1) break;
            if(d[nxt] != d[now] - 1) continue;

            result.push_back(use[now]);
            now = nxt;
        }

        cout << result.size() << ": ";
        reverse(all(result));
        for(auto& i : result) cout << i << " ";
        cout << "\n";
    }
}

void run(){
    while(1){   
        cin >> n >> m; if(!n && !m) return;
        init();

        while(m--){
            ll s, e; cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }

        solve(n, m);
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}