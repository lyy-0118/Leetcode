#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];     //原数组
int b[N<<2];  //线段树
long long sum=0;

void build(int cur,int l,int r){
	if(l==r){
		b[cur]=a[l]; // 叶子节点的最大值就是这个位置的数组值
		return ;
	}
	int mid=(l+r)>>1;
	//递归左右子树
	build(cur*2,l,mid);
	build(cur*2+1,mid+1,r);
	// 当前区间最大值 = 左右子区间最大值的较大者
	b[cur]=max(b[cur*2],b[cur*2+1]);
}
void update(int cur,int l,int r,int L,int R){
	//没有交集直接返回
	if(r<L||l>R) return ;
	//当前区间最大值 <= 2 说明这个区间内所有数都 <= 2
	//因为 1 经过操作后仍为 1，2 经过操作后仍为 2 所以可以跳过
	if(b[cur]<=2) return ;
	//如果到达叶子节点，说明当前只处理一个数组元素
	if(l==r){
		int oldVal=b[cur];
		int newVal=floor(log2(oldVal)+1);
		sum=sum-oldVal+newVal;
		b[cur]=newVal; 		//更新当前叶子的值
		return ;
	}else{
		int mid=(l+r)>>1;
		//递归左右子树
		update(cur*2,l,mid,L,R);
		update(cur*2+1,mid+1,r,L,R);
		// 子节点修改完后，回溯更新当前节点的最大值
		b[cur]=max(b[cur*2],b[cur*2+1]);
	}
 }
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	build(1,1,n);   // 建立线段树，根节点编号为 1，管理区间 [1, n]
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		update(1,1,n,l,r);
		cout<<sum<<'\n';
	}
	return 0;
}