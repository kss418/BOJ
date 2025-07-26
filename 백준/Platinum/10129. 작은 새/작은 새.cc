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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], dp[MAX];
deque <pll> q;

ll solve(ll cur){
    memset(dp, 0x3f, sizeof(dp)); dp[1] = 0;
    q.clear(); q.push_back({0, 1});

    for(int i = 2;i <= n;i++){
        while(!q.empty() && q.front().y < i - cur) q.pop_front();
        dp[i] = q.front().x + (a[q.front().y] <= a[i] ? 1 : 0);
        while(!q.empty()){
            if(q.back().x > dp[i] || (q.back().x == dp[i] && a[q.back().y] <= a[i])) q.pop_back();
            else break;
        }
        
        q.push_back({dp[i], i});
    }
    
    return dp[n];
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    cin >> m;
    while(m--){
        cin >> k;
        cout << solve(k) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

