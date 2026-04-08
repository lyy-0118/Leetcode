#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    // 如果用 0 下标，就只开 n 个空间，不然多出来的0会参与后面的排序
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // 先排序，因为双方最优时都会优先拿当前最小的数
    sort(a.begin(),a.end());
    ll x=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            x+=a[i];   // 小红先手，加
        }else x-=a[i]; // 小紫后手，减
    }
    cout<<x<<endl;
    return 0;
}