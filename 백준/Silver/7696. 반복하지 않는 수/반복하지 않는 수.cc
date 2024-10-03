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
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 1010101;
constexpr ll MOD = 998244353;
ll result[2 * MAX], cnt[10], seq = 1;


int main() {
    fastio;

    for(int i = 1;i < 30 * MAX;i++){
        string cur = to_string(i);
        memset(cnt, 0, sizeof(cnt));

        ll flag = 1;
        for(auto& i : cur) {
            if(cnt[i - '0']) flag = 0;
            cnt[i - '0']++;
        }
        
        if(!flag) continue;
        result[seq++] = i;
    }  

    while(1){
        cin >> n;
        if(!n) break;
        cout << result[n] << "\n";
    }
    
  
    return 0;
}

