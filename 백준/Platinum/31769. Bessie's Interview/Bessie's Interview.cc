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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
bool result[MAX];

priority_queue <pll, vector<pll>, greater<pll>> pq;
vector <vector<ll>> track;

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) pq.push({a[i], i});

    ll idx = m + 1; pll la = {-1, -1};
    while(1){
        auto [cur, ci] = pq.top(); pq.pop();
        vector <pll> now; now.push_back({cur, ci});

        while(!pq.empty() && pq.top().x == now[0].x){
            now.push_back(pq.top());
            pq.pop();
        }
        
        if(now.size() > 1){
            vector <ll> fm;
            for(auto& v : now) fm.push_back(v.y);
            track.push_back(fm);
        }

        if(idx + now.size() > n + 1){
            la = now[0]; break;
        }

        for(auto& v : now){
            pq.push({v.x + a[idx], v.y});
            idx++;
        }
    }

    cout << la.x << "\n";
    result[la.y] = 1;

    for(int i = track.size() - 1;i >= 0;i--){
        bool inter = 0;
        for(auto j : track[i]){
            if(result[j]){
                inter = 1; break;
            }
        }

        if(inter){
            for(auto& j : track[i]) result[j] = 1;
        }
    }

    for(int i = 1;i <= m;i++) cout << result[i];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

