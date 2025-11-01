#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll n, a[MAX];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    ll sum = 0, result = 0;
    for(int i = 1;i <= n;i++){
        sum += a[i];
        result += sum;
    }

    cout << result;
    
    return 0;
}