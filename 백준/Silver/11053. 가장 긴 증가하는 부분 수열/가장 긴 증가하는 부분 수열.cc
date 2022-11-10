#include <iostream>
#include <algorithm>
using namespace std;
int n, num;
int result[1001] = {};
int arr[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        result[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                result[i] = max(result[i], result[j] + 1);
            }
        }
    }
    cout << *max_element(result, result + 1001);
    


    return 0;
}