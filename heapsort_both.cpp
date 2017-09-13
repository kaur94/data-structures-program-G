#include<iostream>
#include<process.h>
 
using namespace std;
maxheapify(int a[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]>a[largest])
	{
		largest=left;
	}
	if(right<n && a[right]>a[largest])
	{
		largest=right;
	}
	if(largest!=i)
	{
		swap(a[largest],a[i]);
		maxheapify(a,n,largest);
	}
}
minheapify(int a[],int n,int i)
{
	int smallest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && a[left]<a[smallest])
	{
	smallest=left;
	}
	if(right<n && a[right]<a[smallest])
	{
		smallest=right;
	}
	if(smallest!=i)
	{
		swap(a[smallest],a[i]);
		minheapify(a,n,smallest);
	}
}
 MaxheapSort(int a[],int n)
 {
 	for(int i=n/2-1;i>=0;i--)
 	{
 		maxheapify(a,n,i);
	 }
	for(int i=n-1;i>0;i--)
	{
		swap(a[0],a[i]);
		maxheapify(a,i,0);
	}
 }
 MinheapSort(int a[],int n)
 {
 	for(int i=n/2-1;i>=0;i--)
 	{
 		minheapify(a,n,i);
	 }
	for(int i=n-1;i>0;i--)
	{
		swap(a[0],a[i]);
		minheapify(a,i,0);
	}
 }
 void print(int a[],int n)
 {
 	
    for (int i=0; i<n; ++i)
        cout << a[i] << " ";
    cout << "\n";

 
 }
int main()
{
		int n,x;
		cout<<"enter the size of array";
	cin>>n;
       int a[n];

	
	cout<<"enter the elements ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"elements are ";
		for(int i=0;i<n;i++)
	{
		cout<<"  "<<a[i];
	}
	// int n = sizeof(arr)/sizeof(arr[0]);
	MinheapSort(a,n);
	cout<<endl;
	cout<< "sorted array is : Max Heap";
	print(a,n);
	MaxheapSort(a,n);
	cout<<endl;
	cout<< "sorted array is : Min Heap";
	print(a,n);

	
	return 0;
	
}
