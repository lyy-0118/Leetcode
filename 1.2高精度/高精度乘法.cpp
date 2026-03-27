//#include<bits/stdc++.h>
//using namespace std;
//const int N = 1e6 + 10; //定义数组最大长度
//int a[N], b[N], c[N];
//int la, lb, lc;        // 分别表示 a, b, c 的长度
//// 高精度乘法：c = a * b
//void mul(int c[], int a[], int b[]){
//	// 1. 每一位相乘，不处理进位，直接累加到对应位置
//	for(int i=0;i<la;i++){
//		for(int j=0;j<lb;j++){
//			c[i+j]+=a[i]*b[j];
//		}
//	}
//	//2.统一处理进位
//	for(int i=0;i<lc;i++){
//		c[i+1]+=c[i]/10; // 向高位进位
//		c[i] %= 10;            // 当前位只保留个位
//	}
//	// 3. 删除结果最高位多余的 0
//    while(lc > 1 && c[lc - 1] == 0) lc--;
//}
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	
//	string x, y;
//    cin >> x >> y;
//    // 计算长度
//    la = x.size();
//    lb = y.size();
//    lc = la + lb;
//    // 将字符串中的数字逆序存入数组
//    for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
//    for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';
//    // 高精度乘法
//    mul(c, a, b);
//    // 倒序输出结果
//    for(int i = lc - 1; i >= 0; i--) cout << c[i];
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi; // 简化vector<int>的书写
// 高精度乘法：计算A × B（A、B为低位在前的数组）
vi mul(vi &A, vi &B) {
    vi C(A.size() + B.size(), 0); // 结果最大长度为A.size()+B.size()
    
    // 逐位计算乘积并累加
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)B.size(); j++) {
            // A的第i位（对应10^i） × B的第j位（对应10^j） = 10^(i+j)位上的贡献
            C[i + j] += A[i] * B[j];
            // 处理进位：当前位的进位累加到高位
            C[i + j + 1] += C[i + j] / 10;
            // 保留当前位的个位数字
            C[i + j] %= 10;
        }
    }
    // 去除前导零（高位的0）
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    
    return C;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); // 快速IO优化
    
    string a, b; cin >> a >> b;
    vi A, B;
    
    // 字符串倒序存入数组（低位在前：个位→索引0）
    for (int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
    
    vi C = mul(A, B); // 计算乘积
    
    // 输出结果（从高位到低位，即数组末尾到开头）
    for (int i = C.size() - 1; ~i; i--) cout << C[i];
    
    return 0;
}
