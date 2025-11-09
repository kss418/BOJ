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
ll a[MAX], dp[MAX], pre[MAX], mx;
priority_queue <pll, vector<pll>, greater<pll>> pq;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    for(int i = 1;i <= n;i++){
        while(!pq.empty() && pq.top().x <= pre[i]){
            mx = max(mx, pq.top().y);
            pq.pop();
        }

        dp[i] = pre[i] - pre[mx];
        pq.push({dp[i] + pre[i], i});
    }

    ll result = INF;
    for(int i = 0;i <= n;i++){
        result = min(result, max(dp[i], pre[n] - pre[i]));
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}