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
ll a[MAX], result = INF, all;

void cal(ll num){
    ll now = n, sum = 0, flag = 1;
    for(int j = 1;j <= n;j++){
        sum += a[j];
        if(sum > num) return;
        if(sum == num) sum = 0, now--;
    }

    result = min(result, now);
}

void run(){
    cin >> n; all = 0; result = INF;
    for(int i = 1;i <= n;i++) cin >> a[i], all += a[i];
    if(!all){ cout << 0 << "\n"; return; }

    for(ll i = 1;i * i <= all;i++){
        if(all % i) continue;
        cal(i); cal(all / i);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}