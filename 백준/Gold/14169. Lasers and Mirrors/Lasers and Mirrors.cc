#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
pll a[MAX], st, en;
deque <pll> q;
map <ll, set<ll>> my, mx;
ll d[2][MAX];

void run(){
    cin >> n >> st.x >> st.y >> en.x >> en.y;
    a[0] = st; a[n + 1] = en;
    mx[a[n + 1].x].insert(n + 1);
    my[a[n + 1].y].insert(n + 1);
    

    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        mx[a[i].x].insert(i);
        my[a[i].y].insert(i);
    }
    memset(d, 0x3f, sizeof(d));

    for(auto& nxt : my[a[0].y]){
        q.push_back({0, nxt});
        d[0][nxt] = 0;
    }

    for(auto& nxt : mx[a[0].x]){
        q.push_back({1, nxt});
        d[1][nxt] = 0;
    }
    mx[a[0].x].clear(); my[a[0].y].clear();

    while(!q.empty()){
        auto [cd, cur] = q.front(); q.pop_front();
        
        if(!cd) for(auto& nxt : mx[a[cur].x]){
            if(d[1][nxt] != INF) continue;
            d[1][nxt] = d[0][cur] + 1;
            q.push_back({1, nxt});
        }
        else for(auto& nxt : my[a[cur].y]){
            if(d[0][nxt] != INF) continue;
            d[0][nxt] = d[1][cur] + 1;
            q.push_back({0, nxt});
        }

        if(!cd) mx[a[cur].x].clear();
        else my[a[cur].y].clear();
    }

    ll result = min(d[0][n + 1], d[1][n + 1]); 
    cout << (result == INF ? -1 : result);  
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}