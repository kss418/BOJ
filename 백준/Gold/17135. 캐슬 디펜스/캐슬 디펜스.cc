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
constexpr ll MAX = 21; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], cur[MAX][MAX];
ll cnt, result;
vector <ll> num;

void init(){
    cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            cur[i][j] = a[i][j];
            cnt += cur[i][j];
        }
    }
}

void move(){
    for(int i = 1;i <= m;i++){
        if(cur[n][i]) cnt--;
        cur[n][i] = cur[n - 1][i];
    }

    for(int i = n - 1;i >= 1;i--){
        for(int j = 1;j <= m;j++){
            cur[i][j] = cur[i - 1][j];
        }
    }
}

ll dist(ll cx, ll cy, ll nx, ll ny){
    return abs(cx - nx) + abs(cy - ny);
}

vector <pll> atkv;
void atk(ll idx){
    ll rx = INF, ry = INF, d = INF;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            ll now = dist(idx, n + 1, j, i);
            if(now > k || !cur[i][j]) continue;
            if(now < d) d = now, rx = j, ry = i;
            else if(now == d){
                if(rx > j) rx = j, ry = i;
            }
        }
    }

    if(rx != INF) atkv.push_back({rx, ry});
}

void cal(){
    init(); ll ret = 0;
    while(cnt){
        atkv.clear();
        for(int i = 1;i <= 3;i++) atk(num[i]);
        for(auto& i : atkv) {
            if(cur[i.y][i.x]) ret++, cnt--;
            cur[i.y][i.x] = 0;
        }
        
        move();
    }

    result = max(result, ret);
}

void bt(){
    if(num.size() == 4){ cal(); return; }

    for(int i = num.back() + 1;i <= m;i++){
        num.push_back(i);
        bt();
        num.pop_back();
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }
    
    num.push_back(0);
    bt(); cout << result;

     
    return 0;
}