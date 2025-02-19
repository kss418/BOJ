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
vector <ll> arr;

ll lb(ll cur){
    return upper_bound(all(arr), cur) - arr.begin() - 1;
}

ll solve(ll cur){
    if(!cur) return 0; ll idx = lb(cur);
    return solve(cur - arr[idx]) + idx;
}

ll dnc(ll l, ll r){
    if(l > r) return MINF;
    if(r <= l + 1) return max(solve(l), solve(r));

    ll idx = lb(r);
    if(l < arr[idx]){
        ll r1 = dnc(0, r - arr[idx]) + idx;
        ll r2 = dnc(max(0ll, l - arr[idx - 1]), arr[idx - 1]) + idx - 1;
        return max(r1, r2);
    }
    return dnc(l - arr[idx], r - arr[idx]) + idx;
}

void init(){
    for(int i = 0;i < 32;i++) arr.push_back((1ll << i) - 1);
}

void run(){
    cin >> n >> m;
    cout << dnc(n, m) << "\n";
}

int main() {
    fastio; cin >> t; init();
    while(t--) run();
    
    return 0;
}