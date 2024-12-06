#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll mx[11], arr[MAX], all = 1;
ll d[11][22], result, v[MAX];

ll tf(deque <ll>& arr){
    ll mul = 1, ret = 0;
    for(int i = 0;i < 11;i++){
        ret += mul * arr[i];
        mul *= mx[i];
    }
    return ret;
}

deque <ll> tf(ll cur){
    deque <ll> ret; ll mul = all;
    for(int i = 10;i >= 0;i--){
        mul /= mx[i];
        ll now = cur / mul;
        cur -= now * mul;
        ret.push_front(now);
    }
    return ret;
}

void init(){
    for(int i = 0;i < 11;i++){
        d[i][2 * i] = 1;
        d[i][2 * i + 1] = -1;
    }
}

bool outrange(deque <ll>& v){
    for(int i = 0;i < 11;i++){
        if(v[i] >= mx[i] || v[i] < 0) return 1;
    }
    return 0;
}

deque <pll> q;
void bfs(){
    while(!q.empty()){
        auto [cn, cc] = q.front(); q.pop_front();
        if(v[cn] <= cc) continue; 
        if(arr[cn] == -1) continue;
        v[cn] = cc;

        deque <ll> now = tf(cn);
        for(int i = 0;i < 22;i++){
            now[i / 2] += d[i / 2][i];
            ll nn = tf(now), nc = cc + 1;
            if(!outrange(now) && v[nn] > nc) q.push_back({nn, nc});
            now[i / 2] -= d[i / 2][i];
        }
    }
}

int main() {
    fastio;

    for(int i = 0;i < 11;i++) cin >> mx[i];
    for(int i = 0;i < 11;i++) all *= mx[i];
    for(int i = 0;i < all;i++) cin >> arr[i]; init();

    memset(v, 0x3f, sizeof(v));
    for(int i = 0;i < all;i++) {
        if(v[i] == 0 || arr[i] != 1) continue;
        q.push_back({i, 0});
    }
    bfs();

    for(int i = 0;i < all;i++){
        if(arr[i] == -1) continue;
        result = max(result, v[i]);
    }
    if(result == INF) result = -1;

    cout << result;
  
     
    return 0;
}