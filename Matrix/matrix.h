

class Matrix
{
private:
	int **p; int m; int n;
public:
	Matrix(int row, int col)
	{
		m = row;
		n = col;
		p = new int*[m];
		for(int i = 0; i<m;i++)
		{
			p[i] = new int[n];
			for(int j = 0; j<n;j++)
			{
				p[i][j] = 0;
			} 
		}
	}
	~Matrix(){}
	void Import()
	{
		cout<<"Enter matrix elements: ";
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cin>>p[i][j];
			}
		}
	}

	void Display()
	{
		for(int i = 0;i<m;i++)
		{
			for(int j = 0;j<n;j++)
			{
				cout<<p[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	Matrix operator + (Matrix b)
	{
		Matrix T(m,n);
		for(int i = 0; i < m; i++)
      	{
    		for(int j = 0; j < n; j++)
    		{
       			T.p[i][j] = p[i][j] + b.p[i][j]; 
    		} 
      	}
      	return T;
	}
	Matrix operator - (Matrix b)
	{
		Matrix T(m,n);
		for(int i = 0; i < m; i++)
      	{
    		for(int j = 0; j < n; j++)
    		{
       			T.p[i][j] = p[i][j] - b.p[i][j]; 
    		} 
      	}
      	return T;
	}

	Matrix operator * (Matrix b)
	{
		Matrix N(1,1);
		if(n == b.m)
		{
			Matrix T(m, b.n);
			for(int i = 0; i<m;i++)
			{
				for(int k = 0;k<b.n;k++)
				{
					T.p[i][k] = 0;
					for(int j = 0; j<n; i++)
					{
						T.p[i][k]+= p[i][j] * b.p[j][k];
					}
				}
			}
			N = T;
		}
		return N;
	}

	Matrix operator = (Matrix Eq)
	{
		m = Eq.m;
		n = Eq.n;
		p = Eq.p;
		return *this;
	}
	bool operator == (Matrix b)
	{
		if(m != b.m && n != b.n)
			return false;
		else
		{
			for(int i = 0; i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(p[i][j] = b.p[i][j])
						continue;
					else
						return false;
				}	
			}
		}
		return true;	
	}
};