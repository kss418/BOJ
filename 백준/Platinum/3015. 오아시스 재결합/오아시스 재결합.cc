#include <iostream>
#include <stack>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;


stack <pair <int, int>> st;
int a[501010];

int main(){
    fastio;
    int n; cin >> n;
    long long result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        while(!st.empty() && st.top().first < a[i]){
            result += st.top().second; st.pop();
        }

        if(st.empty() || st.top().first != a[i]) st.push({a[i], 1});
        else{
            int num = st.top().second + 1;
            st.pop(); st.push({a[i], num});
            result += num - 1;
        }
        
        if(st.size() >= 2) result++;
    }

    cout << result;
    return 0;
}
