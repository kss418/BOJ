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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result, c;
vector <ll> dp[MAX][MAX];
priority_queue <pll> pq;

ll solve(ll cy, ll cx, ll cnt){
    if(!cx) return 0;
    if(dp[cy][cx].size() > cnt) return dp[cy][cx][cnt];
    ll now = 0;
    if(cx >= 1) now = max(now, solve(cy, cx - 1, cnt));
    if(cx >= 3){
        ll sum = a[cy][cx] + a[cy][cx - 1] + a[cy][cx - 2];
        now = max(now, solve(cy, cx - 3, cnt - 1) + sum);
    }

    dp[cy][cx].push_back(now);
    return now;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            dp[i][j].push_back(0);
        }
    }

    for(int i = 1;i <= n;i++) pq.push({solve(i, n, 1), i});
    while(!pq.empty()){
        auto [v, idx] = pq.top(); pq.pop();
        if(v < 0 || c == m) break;
        result += v; c++;

        if(dp[idx][n].size() == n + 1) continue;
        ll cur = solve(idx, n, dp[idx][n].size() - 1);
        ll nxt = solve(idx, n, dp[idx][n].size());
        pq.push({nxt - cur, idx});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}