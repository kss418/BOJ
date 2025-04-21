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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX], b[MAX];

void run(){
    cin >> n; ll result = INF;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, [](pll a, pll b){
        return a.y < b.y;
    });

    for(int i = 0;i <= n;i++){
        pll now = {0, 0};
        if(a[i].x == a[i + 1].x) continue;
        for(int j = 1;j <= n;j++){
            (b[j].x <= a[i].x ? now.x : now.y)++;
            if(b[j].y == b[j + 1].y) continue;
            result = min(result, max({now.x, now.y, i - now.x, n - i - now.y}));
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}