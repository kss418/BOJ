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
pll a[MAX];
ll result, last, mx, pl = INF;

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, [](pll &a, pll &b){
        if(a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    }); 
    a[n + 1].x = INF;

    for(int i = 1;i <= n;i++){
        result += max(a[i].y - max(last, a[i].x), 0ll);
        last = max(last, a[i].y); mx = max(mx, a[i].x);

        ll mn = min(a[i + 1].x, a[i].y);
        pl = min(pl, max(mn - mx, 0ll));
        mx = max(mx, a[i].y);
    }
    
    cout << result - pl;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}