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
vector <pll> arr;
ll result;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        ll mn = min(a[s].y, a[e].y);
        ll mx = max(a[s].y, a[e].y);
        arr.push_back({mn, c});
        arr.push_back({mx + 1, -c});
    }

    sort(all(arr)); ll la = arr[0].x, sum = 0;
    for(auto& [x, c] : arr){
        if(la != x) result = max(result, sum);
        sum += c; la = x;
    }

    cout << max(result, sum);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}