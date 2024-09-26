#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101010;
constexpr ll MOD = 998244353;
stack <ll> st;
ll result;

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> m;
        while(!st.empty() && st.top() <= m){
            result += (st.size() - 1);
            st.pop();
        }
        st.push(m);
    }

    while(!st.empty()){
        result += (st.size() - 1);
        st.pop();
    }

    cout << result;


    return 0;
}