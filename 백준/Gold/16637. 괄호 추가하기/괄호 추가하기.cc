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
vector <ll> num;
ll sum, all, result = -INF;

ll cal(vector <ll>& v){
    ll ret = 0, op = INF + '+';
    for(auto& i : v){  
        if(i < INF){
            if(op - INF == '+') ret += i;
            else if(op - INF == '-') ret -= i;
            else ret *= i;
        }
        else op = i;
    }

    return ret;
}

ll chk(){
    ll ret = 0, idx = 0;
    vector <ll> now;
    for(auto& i : num){
        string cur = s.substr(idx, 2 * i - 1);
        vector <ll> v;
        for(auto& j : cur){
            if(j >= '0' && j <= '9') v.push_back(j - '0');
            else v.push_back(INF + j);
        }
        now.push_back(cal(v));
        idx += 2 * i - 1; now.push_back(s[idx] + INF); idx++;
    }

    return cal(now);
}

void bt(){
    if(sum == all){
        result = max(result, chk());
        return;
    }

    for(int i = 1;i <= 2;i++){
        if(sum + i > all) break;
        sum += i; num.push_back(i);
        bt();
        sum -= i;num.pop_back();
    }
}

int main() {
    fastio;

    cin >> n >> s; 
    all = (n + 1) / 2; bt();

    cout << result;

     
    return 0;
}