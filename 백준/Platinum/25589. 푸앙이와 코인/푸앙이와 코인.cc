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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX], ul[MAX][MAX], ur[MAX][MAX];
ll dl[MAX][MAX], dr[MAX][MAX], sum[MAX][MAX];

ll p4(ll cur){
    return cur * cur * cur * cur;
}

ll sa(ll y1, ll x1, ll y2, ll x2){
    return sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1];
}

void init(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                if(i + k - 1 <= n && j + k - 1 <= n){
                    ul[i][j] = max(ul[i][j], sa(i, j, i + k - 1, j + k - 1) - p4(k));
                }

                if(i + k - 1 <= n && j - k + 1 > 0){
                    ur[i][j] = max(ur[i][j], sa(i, j - k + 1, i + k - 1, j) - p4(k));
                }

                if(i - k + 1 > 0 && j + k - 1 <= n){
                    dl[i][j] = max(dl[i][j], sa(i - k + 1, j, i, j + k - 1) - p4(k));
                }

                if(i - k + 1 > 0 && j - k + 1 > 0){
                    dr[i][j] = max(dr[i][j], sa(i - k + 1, j - k + 1, i, j) - p4(k));
                }
            }
        }
    }
    
    for(int i = n;i >= 1;i--){
        for(int j = n;j >= 1;j--) {
            ul[i][j] = max(ul[i + 1][j], ul[i][j]);  
            ul[i][j] = max(ul[i][j + 1], ul[i][j]);
        }
    }

    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= n;j++) {
            ur[i][j] = max(ur[i + 1][j], ur[i][j]);  
            ur[i][j] = max(ur[i][j - 1], ur[i][j]);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = n;j >= 1;j--) {
            dl[i][j] = max(dl[i - 1][j], dl[i][j]);  
            dl[i][j] = max(dl[i][j + 1], dl[i][j]);
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) {
            dr[i][j] = max(dr[i - 1][j], dr[i][j]);  
            dr[i][j] = max(dr[i][j - 1], dr[i][j]);
        }
    }
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        } 
    } init();

    ll result = 0;
    for(int i = 2;i <= n;i++){
        ll mxd = max(dl[i - 1][1], dr[i - 1][n]);
        ll mxu = max(ul[i][1], ur[i][n]);
        result = max(result, mxd + mxu);
    }

    for(int i = 2;i <= n;i++){
        ll mxl = max(dl[n][i], ul[1][i]);
        ll mxr = max(dr[n][i - 1], ur[1][i - 1]);
        result = max(result, mxl + mxr);
    }
    
    cout << result;
}

int main() {
    fastio;

    // cin >> t;
    while(t--) run();
    

    return 0;
}