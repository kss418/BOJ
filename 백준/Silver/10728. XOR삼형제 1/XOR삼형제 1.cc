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
constexpr ll MAX = 201; // SET MAX SIZE
constexpr ll MOD = 998244353;

bool chk(ll now){
    for(int i = 1;i <= n;i++){
        if(!(now & (1ll << i - 1))) continue;
        for(int j = i + 1;j <= n;j++){
            if(!(now & (1ll << j - 1))) continue;
            ll num = i ^ j;
            if(num > n) continue;
            if(now & (1ll << (num - 1))) return 0;
        }
    }

    return 1;
}

void run(){
    cin >> n; ll mx = 0, idx = 0;
    for(int i = 1;i <= (1ll << n);i++){
        if(!chk(i)) continue; ll cnt = 0;
        for(int j = 0;j < n;j++) if(i & (1ll << j)) cnt++;
        if(mx >= cnt) continue;
        mx = cnt; idx = i;
    }

    cout << mx << "\n";
    for(int i = 0;i < n;i++){
        if(idx & (1ll << i)) cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}