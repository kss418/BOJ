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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
vector <pll> num;
stack <ll> st;

int main() {
    fastio;

    cin >> n; 
    for(int i = 1;i <= n;i++){
        cin >> a[i].x >> a[i].y;
        num.push_back({a[i].x + a[i].y, -i});
        num.push_back({a[i].x - a[i].y, i});
    }
    sort(all(num));

    ll result = 1;
    for(auto& i : num){
        if(i.y > 0) st.push(i.y);
        else{
            if(!st.empty() && st.top() == -i.y) st.pop();
            else result = 0;
        }
    }
    if(!st.empty()) result = 0;
    for(int i = 0;i < num.size() - 1;i++){
        if(num[i].x == num[i + 1].x) result = 0;
    }

    if(result) cout << "YES";
    else cout << "NO";
    
     
    return 0;
}