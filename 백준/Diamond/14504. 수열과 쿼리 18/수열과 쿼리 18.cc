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
ll a[MAX], b;
vector <ll> arr[404];

void insert(ll idx, ll v){
    vector <ll>& now = arr[idx / b];
    a[idx] = v;
    now.insert(lower_bound(all(now), a[idx]), a[idx]);
}

void erase(ll idx){
    vector <ll>& now = arr[idx / b];
    now.erase(lower_bound(all(now), a[idx]));
}

void update(ll idx, ll v){
    erase(idx);
    insert(idx, v);
}

ll query(ll s, ll e, ll v){
    ll ret = 0;
    if(s / b == e / b){
        for(int i = s;i <= e;i++) ret += a[i] > v;
        return ret;
    }

    ll l = s / b + 1, r = e / b - 1;
    for(int i = l;i <= r;i++){
        ll ub = upper_bound(all(arr[i]), v) - arr[i].begin();
        ret += arr[i].size() - ub;
    }

    ll idx = l * b - 1;
    while(idx >= s) ret += a[idx--] > v;

    idx = (r + 1) * b;
    while(idx <= e) ret += a[idx++] > v;

    return ret;
}

void run(){
    cin >> n; b = 800;
    for(int i = 0;i < n;i++) cin >> a[i], arr[i / b].push_back(a[i]);
    for(int i = 0;i < n / b;i++) sort(all(arr[i]));

    cin >> m;
    while(m--){
        ll op, v; cin >> op;
        if(op == 1){
            ll s, e; cin >> s >> e >> v;
            cout << query(s - 1, e - 1, v) << "\n";
        }
        else{   
            ll idx; cin >> idx >> v;
            update(idx - 1, v);
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}