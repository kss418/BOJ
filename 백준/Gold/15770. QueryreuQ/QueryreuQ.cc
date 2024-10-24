#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 10101;
constexpr ll MOD = 998244353;
int dp[MAX][MAX];

int main() {
    fastio;

    cin >> n >> s; string st;
    ll cnt = 0, cur = 0;

    for(auto& i : s){
        if(i != '-'){
            cnt++; dp[cnt][cnt] = 1;
            cur++; st.push_back(i);
            
            if(st[cnt - 1] == st[cnt - 2]) {
                dp[cnt - 1][cnt] = 1; cur++;
            }

            for(int i = 1;i < cnt - 1;i++){
                if(st[i - 1] != st[cnt - 1]) continue;
                if(!dp[i + 1][cnt - 1]) continue;
                dp[i][cnt] = 1; cur++;
            }
        }
        else{
            cnt--; st.pop_back();
            for(int i = 1;i <= cnt + 1;i++){
                if(dp[i][cnt + 1]) cur--; dp[i][cnt + 1] = 0;
            }
        }

        cout << cur << " ";
    }
    
    return 0;
}