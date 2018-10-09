#include <iostream>
using namespace std;
class matric
{
private:
	int hang;
	int cot;
	int array[100][100];	

public:
	matric()
	{
		hang = 3;
		cot = 3;
		for(int i=0; i<100; i++)
		{
			for(int j=0; j<100; j++)
			{
				array[i][j]=0;
			}
		}
	}
	matric(int m, int n)
	{
		hang = m;
		cot = n;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				array[i][j]=0;
			}
		}

	}
	void setAll(int m, int n, int a)
	{
		array[m][n]=a;
	}
	void setSodong(int a)
	{
		hang = a;
	}
	void setSocot(int a)
	{
		cot = a;
	}
	int getSodong()
	{
		return hang;
	}
	int getSocot()
	{
		return cot;
	}
	void nhapMaTran(int m, int n)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
                                cout<<"\n-"<<i<<endl;
                                cout<<"-"<<j<<endl;
				cin>>array[i][j];
			}
		}
	}
	int Laymotdiem(int m, int n)
	{
		return array[m][n];
	}
	matric getMatran()
	{
		matric a;
		a.hang = hang;
		a.cot = cot;
		for(int i=0; i<hang;i++)
		{
			for(int j=0; j<cot; j++)
			{
				a.setAll(i,j,array[i][j]);
			}
		}
		return a;
	}
	void print()
	{
		for(int i=0;i<hang;i++)
		{
			for(int j=0;j<cot;j++)
			{
				cout<<array[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	matric operator + (matric a)
	{
		matric kq;
		for(int i=0;i<=hang;i++)
		{
			for(int j=0; j<=cot; j++)
			{
				kq.array[i][j] = array[i][j] + a.array[i][j];
			}
		}
		return kq;
	}
	matric operator - (matric a)
	{
		matric kq;
		for(int i=0;i<=hang;i++)
		{
			for(int j=0; j<=cot; j++)
			{
				kq.array[i][j] = array[i][j] - a.array[i][j];
			}
		}
		return kq;

	}
	/*matric operator * (matric a)
	{
		matric kq;
		if(hang = a.cot)
		{
			for(int i=0; i<=hang; i++)
			{
				for(int j=1; j<=cot;j++)
				{
					kq.array[i][j]=array[i][j]*a.array[i][j];
				}
			}
		}
		return kq;
	}*/

};

int main()
{
	matric a,b;
	cout<<"Nhap ma tran a:";
	a.nhapMaTran(3,3);
	cout<<"Nhap ma tran b: ";
	b.nhapMaTran(3,3);
	cout<<"Ma tran a: "<<endl;
	a.print();
	cout<<"Ma tran b: "<<endl;
	b.print();
	matric kq = a + b;
	cout<<"Tong 2 ma tran: "<<endl;
	kq.print();
	return 0;
}	
