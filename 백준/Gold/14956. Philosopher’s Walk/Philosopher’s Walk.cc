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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

pll dnc(ll cur, ll cnt){
    if(cur == 1){
        if(cnt == 1) return {1, 1};
        else if(cnt == 2) return {2, 1};
        else if(cnt == 3) return {2, 2};
        return {1, 2};
    }
 
    ll div = (cnt - 1) / (cur * cur), nxt = cnt - div * (cur * cur);
    pll ret = dnc(cur >> 1ll, nxt);

    if(!div){
        swap(ret.x, ret.y);
    }
    else if(div == 1){
        ret.x += cur;
    }
    else if(div == 2){
        ret.y += cur; ret.x += cur;
    }
    else{
        swap(ret.x, ret.y);
        ret.x = cur - ret.x + 1;
        ret.y = cur - ret.y + 1;

        ret.y += cur;
    }

    return ret;
}

void run(){
    cin >> n >> m;
    auto ret = dnc(n, m);
    cout << ret.x << " " << ret.y;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}