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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll cnt;
vector <pll> adj[MAX];

ll dfs(ll now, ll cur = 1, ll pre = -1){
    ll ret = 0;
    vector <ll> arr;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ll num = dfs(now, nxt, cur) + co;
        arr.push_back(num);
    }

    sort(all(arr));
    if(!arr.empty() && arr[0] <= now) ret = arr[0], cnt++;
    for(int i = 1;i < arr.size();i++){
        if(ret + arr[i] > now) break;
        else ret = arr[i], cnt++;
    }

    return ret;
}

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        cnt = 0; dfs(cur);
        return cnt >= m;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) adj[i].clear();
    
    for(int i = 1;i < n;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    _bs <ll> bs(1, 3e10);
    cout << bs.ret() << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}