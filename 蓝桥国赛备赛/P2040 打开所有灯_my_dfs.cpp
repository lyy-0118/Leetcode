#include<bits/stdc++.h>
using namespace std;
int a[3][3];
int b[3][3];
int ans=INT_MAX;
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,1,-1};

//改变该位置即该位置上下左右方向灯的状态
void Change(int x,int y){
	for(int i=0;i<5;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if((nx>=0&&nx<3)&&(ny>=0&&ny<3)){
			b[nx][ny]^=1;
		}
	}
}

//检查该方案是否打开全部灯，即全为 “1”
bool Check(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!b[i][j]) return false;
		}
	}
	return true;
}

int Count(int mask){
	int cnt=0;
	for(int k=0;k<9;k++){
		if((mask>>k)&1){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	
	//mask表示一种方案数
	for(int mask=0;mask<(1<<9);mask++){
		//复制原数组
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				b[i][j]=a[i][j];
			}
		}
		//根据mask改变数组状态
		if(mask!=0){
			for(int k=0;k<9;k++){
				if((mask>>k)&1){ //改变它自己以及上下左右的状态
					int x=k/3;
					int y=k%3;
					Change(x,y);
				}
			}
		}
		if(Check()){
			ans=min(Count(mask),ans);
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}