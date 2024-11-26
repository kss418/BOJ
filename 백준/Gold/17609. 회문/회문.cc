#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];


int main() {
    fastio;

    cin >> t;
    while(t--){
        cin >> s; ll l = 0, r = s.size() - 1;
        ll cnt = 0, result = 0;
        
        while(l <= r){
            if(s[l] != s[r]){
                if(s[l + 1] == s[r]) l++, cnt++;
                else if(s[l] == s[r - 1]) r--, cnt++;
                else cnt += 2, l++, r--;
            }
            else l++, r--;
        }
        result = cnt;

        l = 0; r = s.size() - 1; cnt = 0;
        while(l <= r){
            if(s[l] != s[r]){
                if(s[l] == s[r - 1]) r--, cnt++;
                else if(s[l + 1] == s[r]) l++, cnt++;
                else cnt += 2, l++, r--;
            }
            else l++, r--;
        }  
        result = min(result, cnt);

        cout << min(result, 2ll) << "\n";
    }


    return 0;
}

