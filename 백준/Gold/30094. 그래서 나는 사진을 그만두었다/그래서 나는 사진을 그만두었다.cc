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
pll a[MAX];
map <ll, ll> cnt;
vector <ll> arr;
ll mx, mn, result = 1;
ll fac[MAX];

void run(){
    cin >> n; fac[0] = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        ll diff = a[i].x - a[i].y;
        cnt[diff]++;
        arr.push_back(i);
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    sort(all(arr), [](ll l, ll r){
        return a[l].x - a[l].y > a[r].x - a[r].y;
    });

    for(auto& [idx, v] : cnt){
        result *= fac[v];
        result %= MOD;
    }

    for(int i = 1;i <= n;i++){
        ll idx = arr[i - 1];
        mn += (i - 1) * a[idx].x + (n - i) * a[idx].y;
    }

    cout << mn << " " << result << "\n";
    for(auto& i : arr) cout << i << " ";
    cout << "\n";

    reverse(all(arr));
    for(int i = 1;i <= n;i++){
        ll idx = arr[i - 1];
        mx += (i - 1) * a[idx].x + (n - i) * a[idx].y;
    }

    cout << mx << " " << result << "\n";
    for(auto& i : arr) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}