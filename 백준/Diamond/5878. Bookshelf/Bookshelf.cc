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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX];
multiset <ll> ms;

class node{
public:
    ll l, r, v;
};
deque <node> q;

void run(){
    cin >> n >> m; memset(dp, 0x3f, sizeof(dp)); 
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    ll l = 1, sum = 0; 
    dp[0] = 0; q.push_back({0, 0, 0});
    ms.insert(0);
    
    for(int r = 1;r <= n;r++){
        ll pre = dp[r - 1]; sum += a[r].y;
        node cur = {r, r, a[r].x};

        while(sum > m){
            sum -= a[l].y; l++;
            while(!q.empty() && q.front().l < l){
                auto [ql, qr, qv] = q.front(); q.pop_front();

                ll pre_dp = (ql ? dp[ql - 1] : 0);
                ms.erase(ms.find(pre_dp + qv));
                ql = l; if(ql > qr) continue;
                
                q.push_front({ql, qr, qv});
                pre_dp = (ql ? dp[ql - 1] : 0);
                ms.insert(pre_dp + qv);
            }
        } 

        while(!q.empty() && q.back().v <= cur.v){
            auto& [l, r, v] = q.back(); q.pop_back();
            cur.l = l; ll pre_dp = (l ? dp[l - 1] : 0);
            ms.erase(ms.find(pre_dp + v));
            pre = min(pre, pre_dp);
        }
        ms.insert(pre + cur.v);
        q.push_back(cur);
        dp[r] = *ms.begin();
    }

    cout << dp[n];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

