#include<bits/stdc++.h>
using namespace std;

void Buildtree(int *tree, int *a, int index, int s, int e){
	if(s>e){
		return;
	}
	if(s==e){
		tree[index]= a[s];
		return;
	}
	int mid = (s+e)/2;
	Buildtree(tree, a, 2*index, s, mid);
	Buildtree(tree, a, 2*index+1, mid+1, e);

	int left = tree[2*index];
	int right = tree[2*index+1];

	tree[index]= min(left, right);
}	

void updateRange(int *tree, int index, int s, int e, int rs, int re, int dec,int X){
	if(re<s || rs>e){
		return;
	}
	if(s==e){
		if(tree[index]>X)
			tree[index] -=dec;
		return;
	}
	int mid = (s+e)/2;
	updateRange(tree, 2*index, s, mid, rs, re, dec);
	updateRange(tree, 2*index+1, mid+1, e, rs, re, dec);
	tree[index] = min(tree[2*index], tree[2*index+1]);
	return; 
}
void printtree(int *tree,int index, int s, int e){
	if(s>e){
		return;
	}
	if(s==e){
		cout<<tree[index]<<" ";
		return;
	}
	int mid = (s+e)/2;
	printtree(tree,2*index, s, mid);
	printtree(tree,2*index+1, mid+1, e);

}



int main()
{
	int N;
	int M;
	int X;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int *tree = new int[4*N+1];
	int index = 1;
	int s= 0;
	int e= n-1;
	Buildtree(tree,a,index,s,e);
	cin>>M;
	for(int j=0;j<M;j++)
	{
		cin>>X;

		updateRange(tree,index,s,e,0,n-1,1,X);
	}

	printtree(tree,index,s,e);



	return 0;
}