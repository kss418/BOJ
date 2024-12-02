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
constexpr ll MAX = 31; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], result = INF;
vector <pll> num;

ll lat(ll cx, ll cy){
    if(cy == k + 1) return cx;
    if(a[cx][cy]) return lat(cx + 1, cy + 1);
    else if(a[cx - 1][cy]) return lat(cx - 1, cy + 1);
    return lat(cx, cy + 1);
}

ll chk(vector <pll>& v){
    for(int i = 1;i <= n;i++){
        if(lat(i, 1) != i) return INF;
    }

    return v.size() - 1;
}

void bt(){
    result = min(chk(num), result);
    if(num.size() == 4) return;
    
    for(int i = num.back().x;i < n;i++){
        for(int j = (i == num.back().x) ? num.back().y + 1 : 1;j <= k;j++){
            if(a[i + 1][j] || a[i - 1][j]) continue;
            a[i][j]++; num.push_back({i, j});
            bt();
            a[i][j]--; num.pop_back();
        }
    }
}

int main() {
    fastio;

    cin >> n >> m >> k;
    while(m--){
       ll y, x; cin >> y >> x;
       a[x][y] = 1; 
    }
    
    num.push_back({0, 0});
    bt();

    if(result == INF) result = -1;
    cout << result;

     
    return 0;
}