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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101; // PLZ CHK!
constexpr ll MOD = 998244353;
char a[MAX][MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin >> a[i][j];
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        bool flag = 0;
        for(int j = 1;j <= m;j++){
            if(a[i][j] == '.'){
                if(flag) result += 2;
            }
            else flag ^= 1, result++;
        }
    }

    cout << (result >> 1);
    
     
    return 0;
}