#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int H, W, K, A[309][309]; 
// 用来标记第i行的j列和k列之间是否满足条件
bool ok[309][309][309];

int main() {
	int Q;
	cin >> Q;
	for (int rep = 1; rep <= Q; ++rep) {
		cin >> H >> W >> K;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> A[i][j];
			}
		}
		// 按行进行循环
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				int cl = inf, cr = -inf;
				for (int k = j; k < W; ++k) {
					cl = min(cl, A[i][k]);
					cr = max(cr, A[i][k]);
					if (cr - cl <= K) {
						ok[i][j][k] = true;
					}
					else {
						ok[i][j][k] = false;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < W; ++i) {
			for (int j = i; j < W; ++j) {
				int cont = 0;
				// 行
				for (int k = 0; k < H; ++k) {
					if (ok[k][i][j]) ++cont;
					else cont = 0;
					ans = max(ans, cont * (j - i + 1));
				}
			}
		}
		cout << "Case #" << rep << ": " << ans << endl;
	}
	return 0;
}