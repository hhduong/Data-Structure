class Date
{
private:
	int d;
	int m;
	int y;
public:
	Date()
	{
		d = 1;
		m = 1;
		y = 2000;
	}
	Date(int day, int month, int year)
	{
		d = day;
		m = month;
		y = year;
	}
	friend ostream &operator<<(ostream &out, Date a)
	{
		out<<a.d<<"-"<<a.m<<"-"<<a.y;
		return out;
	}
};