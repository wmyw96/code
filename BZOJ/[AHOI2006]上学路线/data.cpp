#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
#include<ctime>
using namespace std;
map<int,int> M;

int rand(int l,int r){
	return l+rand()%(r-l+1);
}


int main(){
	freopen("1.in","w",stdout);
	int n,m;
	srand(time(0));
	n=5;m=8;
	printf("%d %d\n",n,m);
	for (int i=2;i<=n;i++){
		int y=i;
		int x=rand(1,i-1);
		printf("%d %d %d %d\n",x,y,rand()%10+1,rand()%100);
		M[x*1000+y]=1;
	}
	for (int i=n-1;i<=m;i++){
		int x=rand()%(n*2/3)+1;
		int y=rand(x+1,n);
		//while (M[x*1000+y] || x==y){
		//	x=rand()%(n*2/3)+1;
		//	y=rand(x,n+1);			
		//}
		printf("%d %d %d %d\n",x,y,rand()%10+1,rand()%100);
		M[x*1000+y]=1;
	}
}
