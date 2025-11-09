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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll p[MAX], sz[MAX], result;
vector <ll> adj[MAX], c;
bitset <501010> dp;

void init(ll cur = 1){
    sz[cur] = 1;
    for(auto& nxt : adj[cur]){
        init(nxt);
        sz[cur] += sz[nxt];
    }
}   

void cent(ll cur = 1){
    bool flag = 0;
    for(auto& nxt : adj[cur]){
        if(2 * sz[nxt] > n){
            flag = 1;
            cent(nxt);
        }
    }

    if(!flag && n - sz[cur] < n / 2) c.push_back(cur);
}

pll cal(ll cur, ll pre = -1){
    pll ret = {0, 1};
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        pll now = cal(nxt, cur);
        ret.x += now.x; ret.y += now.y;
    }

    if(p[cur] != pre && p[cur] != -1){
        pll now = cal(p[cur], cur);
        ret.x += now.x; ret.y += now.y;
    }

    ret.x += ret.y;
    return ret;
}

void run(){
    cin >> n; p[1] = -1;
    for(int i = 2;i <= n;i++) cin >> p[i], adj[p[i]].push_back(i);
    init(); cent();

    for(auto& cur : c){
        vector <ll> arr; vector <pll> comp; dp.reset();
        for(auto& nxt : adj[cur]) arr.push_back(sz[nxt]);
        arr.push_back(n - sz[cur]);
        sort(all(arr));

        ll la = -1, cnt = 0;
        for(auto& i : arr){
            if(i != la){
                if(la != -1) comp.push_back({la, cnt});
                cnt = 1; la = i;
            }
            else cnt++;
        }
        comp.push_back({la, cnt});

        vector <ll> num;
        for(auto& [x, y] : comp){
            ll now = 1;
            while(now <= y){
                num.push_back(x * now);
                y -= now; now <<= 1ll;
            }
        }
    
        dp[0] = 1; ll sum = cal(cur).x;
        for(auto& i : num) dp |= dp << i;
        for(int i = n / 2 + 1;i >= 0;i--){
            if(!dp[i]) continue;
            result = max<ll>(result, i * (n - i - 1) + sum);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}