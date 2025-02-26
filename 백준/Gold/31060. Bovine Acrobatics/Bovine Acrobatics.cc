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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
deque <pll> q;
ll sum, result;

void run(){
    cin >> n >> m >> k; 
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, [](pll& a, pll& b){
        return a.x < b.x;
    });

    for(int i = 1;i <= n;i++){
        while(!q.empty()){
            auto[ca, cw] = q.front();
            if(ca > a[i].x - k) break;
            sum -= cw; q.pop_front();
        }

        ll use = m - sum;
        if(use <= 0) continue;
        ll mn = min({use, a[i].y, m});
        q.push_back({a[i].x, mn});
        result += mn; sum += mn;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}