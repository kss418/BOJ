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
ll a[MAX];

bool chk(){
    for(int i = 1;i < n;i++){
        if(a[i] != a[i + 1]) return 0;
        if(a[i] < 0 || a[i + 1] < 0) return 0;
    }
    return 1;
}

void run(){
    cin >> n; ll result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 2;i < n;i++){
        if(a[i] <= a[i - 1]) continue;
        ll diff = a[i] - a[i - 1];
        result += diff;
        a[i] -= diff; a[i + 1] -= diff;
    }

    for(int i = n - 1;i >= 2;i--){
        if(a[i] <= a[i + 1]) continue;
        ll diff = a[i] - a[i + 1];
        result += diff;
        a[i] -= diff; a[i - 1] -= diff;
    }

    cout << (chk() ? 2 * result : -1) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}