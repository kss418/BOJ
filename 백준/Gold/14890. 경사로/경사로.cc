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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], use[MAX];

bool chk(vector <ll>& v){
    bool ret = 1;
    for(int i = 0;i < v.size() - 1;i++){
        if(v[i] == v[i + 1]) continue;
        if(abs(v[i] - v[i + 1]) != 1) return 0;

        ll cnt = 0;
        if(v[i] < v[i + 1]){
            for(int j = i; j >= i - m + 1;j--){
                if(j < 0) break;
                if(v[j] == v[i] && !use[j]) cnt++;
                use[j] = 1;
            }
        }
        else{
            for(int j = i + 1;j <= i + m;j++){
                if(j >= v.size()) break;
                if(v[j] == v[i + 1] && !use[j]) cnt++;
                use[j] = 1; 
            }
        }

        if(cnt < m) return 0;
    }

    return 1;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        vector <ll> now; memset(use, 0, sizeof(use));
        for(int j = 1;j <= n;j++) now.push_back(a[i][j]);
        result += chk(now);
    }
  
    for(int i = 1;i <= n;i++){
        vector <ll> now; memset(use, 0, sizeof(use));
        for(int j = 1;j <= n;j++) now.push_back(a[j][i]);
        result += chk(now);
    }

    cout << result;

     
    return 0;
}