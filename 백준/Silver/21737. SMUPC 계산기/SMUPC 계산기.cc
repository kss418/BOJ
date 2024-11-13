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
constexpr ll MAX = 501010; // PLZ CHK!
constexpr ll MOD = 998244353;
deque <ll> q;

int main() {
    fastio;

    cin >> n >> s;

    string now;
    for(auto& i : s){
        if(i >= '0' && i <= '9') now.push_back(i);
        else {
            if(!now.empty()) q.push_back(stoll(now)), now.clear();
            q.push_back(INF + i);
        }
    }
    if(!now.empty()) q.push_back(stoll(now));

    ll result = q.front(); q.pop_front();
    ll pre = 'P', flag = 0;
    for(auto& i : q){
        if(i > INF) {
            pre = i - INF;
            if(pre == 'C') {
                cout << result << " ", flag = 1;
                pre = 'P';
            }
        }
        else{
            if(pre == 'S') result -= i;
            else if(pre == 'M') result *= i;
            else if(pre == 'U') result /= i;
            else if(pre == 'P') result += i;
        }
    }

    if(!flag) cout << "NO OUTPUT";

     
    return 0;
}