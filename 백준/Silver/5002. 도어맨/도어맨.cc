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
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
deque <char> q;

int main() {
    fastio;

    cin >> n >> s; ll diff = 0;
    for(auto& i : s) q.push_back(i);

    while(!q.empty()){
        char fi = q.front(); q.pop_front();
        char se = 0;
        if(!q.empty()) se = q.front(), q.pop_front();

        if(diff <= 0){
            if(se == 'M') {
                diff++; q.push_front(fi);
            }
            else if(fi == 'M'){
                diff++; if(se) q.push_front(se);
            }
            else{
                diff--; if(se) q.push_front(se);
            }
        }
        else{
            if(se == 'W') {
                diff--; q.push_front(fi);
            }
            else if(fi == 'W'){
                diff--; if(se) q.push_front(se);
            }
            else{
                diff++; if(se) q.push_front(se);
            }
        }

        if(abs(diff) > n) {
            q.push_back(0); break;
        }
    }

    cout << s.size() - q.size();



    
    
    
    return 0;
}