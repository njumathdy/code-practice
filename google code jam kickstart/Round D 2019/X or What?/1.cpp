#include <iostream>
#include <vector>

using namespace std;

int T;
int N, Q;
vector<int> arr(10050, 0);
vector<int> p(10050, 0);
vector<int> qnum(10050, 0);

bool is_xor_even(int num) {
    int count = 0;
    while(num) {
        num &= (num-1);
        count++;
    }
    return count % 2 == 0;
}

void solve(vector<int>& nums, int n, int q) {
    vector<int> x_or(n+1, 0);
    x_or[0] = 0;
    for(int i = 1; i <= n; i++) {
        x_or[i] = x_or[i-1] ^ nums[i-1];
    }
    for(int i = 0; i < q; i++) {
        for(int j = p[i]+1; j <= n; j++) {
            x_or[j] = x_or[j] ^ nums[p[i]] ^ qnum[i];
        }
        nums[p[i]] = qnum[i];
        bool flag = false;
        for(int k = n; k >= 0; k--) {
            for(int l = 0; l + k <= n; l++) {
                if(is_xor_even(x_or[l+k] ^ x_or[l])) {
                    cout << k;
                    if(i != q-1)
                        cout << " ";
                    flag = true;
                    break;
                }   
            }
            if(flag)
                break;
        }
    }
    cout << endl;
}

int main() {
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> N >> Q;
        for(int j = 0; j < N; j++)
            cin >> arr[j];
        for(int j = 0; j < Q; j++)
            cin >> p[j] >> qnum[j];
        cout << "Case #" << i+1 << ": ";
        solve(arr, N, Q);
    }  
    
    return 0;
}
