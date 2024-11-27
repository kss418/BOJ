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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll use[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
vector <ll> num;
ll flag = 0;

bool chk(vector <ll>& v){
    ll a = 10 * num[0] + num[1];
    ll b = 10 * num[2] + num[3];
    ll c = 10 * num[4] + num[5];
    
    return (a + b) == c;
}

void bt(){
    if(flag) return;
    if(num.size() == 6){
        if(chk(num) && !n){
            cout << num[0] << num[1] << "+";
            cout << num[2] << num[3] << "=";
            cout << num[4] << num[5];
            flag = 1;
        }
        return;   
    }

    for(int i = 0;i < 10;i++){
        if(n < use[i]) continue;
        num.push_back(i); n -= use[i];
        bt();
        num.pop_back(); n += use[i];
    }
}


int main() {
    fastio;

    cin >> n; n -= 4; bt();
    if(!flag) cout << "impossible";
    
     
    return 0;
}