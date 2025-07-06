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
ll a[MAX], dp[MAX], now1, now2;
vector <ll> arr, dia;
vector <pll> adj[MAX];

ll solve(ll cur, ll pre = -1){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ret = max(ret, solve(nxt, cur) + co);
    } 

    return ret;
}

void reroot1(ll cur, ll mx = 0, ll pre = -1){
    ll num = 0;
    vector <ll> arr;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ll now = solve(nxt) + co;
        arr.push_back(now);
    }

    sort(all(arr));
    if(!arr.empty()) num = max(num, arr.back());
    num = max(num, mx);

    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue; 
        if(solve(nxt) + co == arr.back()){
            if(arr.size() > 1) reroot1(nxt, max(mx, arr[arr.size() - 2]) + co, cur);
            else reroot1(nxt, mx + co, cur);
            
        }
        else reroot1(nxt, max(mx, arr.back()) + co, cur);
    }

    now1 = min(now1, num);
}

void reroot2(ll cur, ll mx = 0, ll pre = -1){
    ll num = 0;
    vector <ll> arr;
    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue;
        ll now = solve(nxt) + co;
        arr.push_back(now);
    }

    sort(all(arr)); 
    if(!arr.empty()) num = max(num, mx + arr.back());
    if(arr.size() >= 2) num = max(num, arr.back() + arr[arr.size() - 2]);
    num = max(num, mx);

    for(auto& [nxt, co] : adj[cur]){
        if(nxt == pre) continue; 
        if(solve(nxt) + co == arr.back()){
            if(arr.size() > 1) reroot2(nxt, max(mx, arr[arr.size() - 2]) + co, cur);
            else reroot2(nxt, mx + co, cur);
            
        }
        else reroot2(nxt, max(mx, arr.back()) + co, cur);
    }

    now2 = max(now2, num);
}

void init(ll cur){
    now1 = INF; now2 = 0; solve(cur); 
    reroot1(cur); reroot2(cur);
    arr.push_back(now1);
    dia.push_back(now2);
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++){
        if(dp[i] != -1) continue;
        init(i);
    }

    ll result = 0;
    sort(all(dia)); reverse(all(dia));
    if(!dia.empty()) result = dia[0];

    sort(all(arr)); reverse(all(arr));
    if(arr.size() >= 2){
        result = max(result, arr[0] + arr[1] + k);
        if(arr.size() >= 3) result = max(result, arr[1] + arr[2] + 2 * k);
    }
    else if(arr.size() == 1) result = max(result, arr[0]);

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

