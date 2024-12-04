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
constexpr ll MAX = 52; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], sum, cnt, tmp[MAX];

void rot(ll num, ll dir, ll val){
    if(!dir) dir = -1;
    for(int i = 1;i <= m;i++){
        tmp[i] = a[num][(i + dir * val + m - 1) % m + 1];
    }
    for(int i = 1;i <= m;i++) a[num][i] = tmp[i];
}

bool chk(ll cy, ll cx){
    ll cur = a[cy][cx];
    if(cur == a[cy + 1][cx]) return 1;
    if(cur == a[cy - 1][cx]) return 1;
    if(cur == a[cy][cx % m + 1]) return 1;
    if(cur == a[cy][(cx - 2 + m) % m + 1]) return 1;
    return 0;
}

bool erase(){
    bool ret = 0; vector <pll> num;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == INF) continue;
            if(chk(i, j)){
                num.push_back({i, j});
                ret = 1;
            }
        }
    }
    
    for(auto& i : num){
        sum -= a[i.x][i.y]; cnt--;
        a[i.x][i.y] = INF;
    }

    return ret;
}

void operate(){
    ll diff = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == INF) continue;
            if(a[i][j] * cnt < sum) a[i][j]++, diff++;
            else if(a[i][j] * cnt > sum) a[i][j]--, diff--;
        }
    }

    sum += diff;
}

int main() {
    fastio;

    cin >> n >> m >> k;
    memset(a, 0x3f,sizeof(a));
    
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            sum += a[i][j]; cnt++;
        }
    }

    while(k--){
        ll num, dir, val; cin >> num >> dir >> val;
        for(int i = num;i <= n;i += num) rot(i, dir, val);
        if(!erase()) operate();
    }

    cout << sum;
  
     
    return 0;
}