#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0),ios::sync_with_stdio(0);
using namespace std; typedef long long ll; 
using pll = pair<ll, ll>; ll n, m, k, t; string s;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAX = 101019;
ll arr[MAX];
deque <ll> st, q, result;



int main() { 
  fastio;

  cin >> n;
  for(int i = 1;i <= n;i++) cin >> arr[i];
  for(int i = 1;i <= n;i++) q.push_back(i);

  for(int i = 1;i <= n;i++){
    while(!q.empty() && arr[i] >= q.front()) {
      st.push_back(q.front());
      q.pop_front();
      result.push_back(1);
    }

    if(arr[i] == st.back()) st.pop_back(), result.push_back(0);
    else {
      cout << "NO";
      return 0;
    }
  }

  for(auto i : result) cout << (i ? "+" : "-") << "\n";

  
  return 0;
}
