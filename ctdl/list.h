template <class T>
class List
{
private:
	T a[100];
	int N;
public:
	List()
	{
		N = 0;
	}
	void Add(T v)
	{
		a[N] = v;
		N++;
	}
	void PrintAll() const
	{
		for(int i=0; i<N; i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	void Change(int pos, T value)
	{
		a[pos-1] = value;
	}
	int Count() const
	{
		return N;
	}
	void Insert(int vt, int value)
	{
		N++;
		for(int i = N;i>=vt;i--)
		{
			a[i]=a[i-1];
		}
		a[vt-1] = value;
	}
	void Delete(int vt)
	{
		for(int i=vt-1;i<N;i++)
		{
			a[i]=a[i+1];
		}
		N--;
	}
	void Delete(int pos1, int pos2)
	{
		for(int i= pos2-1; i>pos1;i--)
		{
			Delete(i);
		}
	}
	int Count(T value) const
	{
		int dem=0;
		for(int i=0;i<N;i++)
		{
			if(value == a[i])
			{
				dem++;
			}
		}
		return dem;
	}
	bool Seach(T value)
	{
		for(int i=0;i<N;i++)
		{
			if(value == a[i])
			{
				return true;
				break;
			}
		}
		return false;	
	}

	int SeachMax()
	{
		int maxx = a[0];
			for(int i=1;i<N;i++)
			{
				if(a[i]>maxx)
				{
					maxx = a[i];
				}
			}
		return maxx;
	}
	int SeachMin()
	{
		int minn = a[0];
		for(int i=1; i<N; i++)
		{
			if(a[i]<minn)
			{
				minn = a[i];
			}
		}
		return minn;
	}
};
