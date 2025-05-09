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
ll a[MAX], pre[30101], nxt[30101], result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) nxt[a[i]]++;
    for(int i = 1;i <= n;i++){
        ll now = a[i];
        nxt[now]--;

        result += pre[now] * nxt[now];
        for(int d = 1;d <= 15000;d++){
            if(now - d < 0 || now + d > 30000) break;
            result += pre[now - d] * nxt[now + d];
            result += pre[now + d] * nxt[now - d];
        }

        pre[now]++;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

