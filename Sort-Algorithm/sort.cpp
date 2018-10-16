#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;

}
void BubbleSort(int a[],int n) //sap xep noi bot
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[j-1])
			{
				int temp;
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
};
void MergeSort(int a[], int n) // sap xep tron
{
};
void InsertionSort(int a[], int n) // sap xep chen
{
	int j,t;
	for(int i=1;i<n;i++)
	{
		j = i-1;
		t = a[i];
		while(t<a[j]&&j>=0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
	}
};
void SelectionSort(int a[], int n) //sap xep chon
{
	int t,Min;
	for(int i=1;i<n-1;i++)
	{
		Min = i;
		for(int j = i+1;j<n;j++)
		{
			if(a[j]<a[Min])
				Min = j;
		}
		t = a[Min];
		a[Min] = a[i];
		a[i] = t;
	}
};
void QuickSort(int a[], int n)
{

};
void HeapSort(int a[], int n){};
void Print(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	//BubbleSort(a,n);
	//InsertionSort(a,n);
	//SelectionSort(a,n);
	Print(a,n);
	return 0;
}