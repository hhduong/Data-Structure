#include <stdlib.h>
#include <fstream>
using namespace std;
#define GREEN   "\033[32m"
#define RED	    "\033[31m"
#define YELLOW  "\033[33m"
class MonHoc
{
public:
	int MaMonHoc;
	string TenMon;
	MonHoc()
	{
		MaMonHoc = 0;
		TenMon = "";
	}
	MonHoc(int a, string b)
	{
		MaMonHoc = a;
		TenMon = b;
	}
	void setMaMonHoc(int a)
	{
		MaMonHoc = a;
	}
	void setTen(string a)
	{
		TenMon = a;
	}
	int getMaMon()
	{
		return MaMonHoc;
	}
	string getTenMon()
	{
		return TenMon;
	}
	friend istream &operator >>(istream &in, MonHoc &a)
	{
		cout<<"- Nhap ma mon hoc : ";
		in>>a.MaMonHoc;
		cout<<"- Nhap ten mon hoc: ";
		in.ignore();
		getline(in,a.TenMon);
		return in;
	}
	friend ostream &operator <<(ostream &out,MonHoc &a)
	{
		out<<a.MaMonHoc<<"\t"<<a.TenMon;
		return out;
	}
	MonHoc getMonHoc(MonHoc a)
	{
		return a;
	}
};

class BangDiem
{
private:
	//MonHoc mon;
	int mamon;
	float diemmon;
public:
	MonHoc mon;
	BangDiem(){}
	BangDiem(MonHoc a, int b, float c)
	{
		mon = a;
		mamon = b;
		diemmon = c;
	}
	void setMaMon(int a)
	{
		mamon = a;
	}
	int getMaMon()
	{
		return mamon;
	}
	void setMonHoc(MonHoc a)
	{
		mon = a;
	}
	void setDiem(float a)
	{
		diemmon = a;
	}
	float getDiem()
	{
		return diemmon;
	}
	friend istream &operator >>(istream &in, BangDiem &a)
	{
		cout<<"- Nhap ma mon      : ";
		in>>a.mamon;
		cout<<"- Nhap diem mon hoc: ";
		in>>a.diemmon;
		a.mon.setMaMonHoc(a.getMaMon());
		return in;
	}

	friend ostream &operator <<(ostream &out, BangDiem a)
	{
		out<<a.mon<<"\t"<<a.diemmon<<endl;
		return out;
	}
};

int menu()
{
	system("clear");
	int chon;
	cout<<GREEN<<"~ PHAN MEM QUAN LI DIEM ~"<<endl;
	cout<<YELLOW<<"[1]. Them mon hoc"<<endl;
	cout<<"[2]. Cap nhat bang diem"<<endl;
	cout<<"[3]. Xem bang diem"<<endl;
	cout<<"[4]. Sua diem"<<endl;
	cout<<"[5]. Luu bang diem xuong file"<<endl;
	cout<<"[6]. Nap data mon hoc tu file"<<endl;
	cout<<"[7]. Nap data bang diem tu file (Chua hoan thien)"<<endl;
	cout<<"[0]. Thoat"<<endl;
	cout<<"[?]. Ban chon => "; cin>>chon;
	return chon;
}
void NhapDiem(BangDiem a[], int &m, MonHoc b[], int n)
{
	system("clear");
	cout<<"[2]. Cap nhat bang diem"<<endl;
	cin>>a[m];
	int check = 1;
	for(int j=0;j<m;j++)
	{
		if(a[m].getMaMon()==a[j].getMaMon())
		{	
			check = 0;
			break;
		}
	}
	if(check == 1)
	{
		m++;
		for(int i=0;i<m;i++)
		{
			if(a[m-1].getMaMon()== b[i].getMaMon())
			{
				a[m-1].setMonHoc(b[i].getMonHoc(b[i]));
			}
		}
		cout<<RED<<"Nhap diem thanh cong!"<<endl;
	}
	else
		cout<<RED<<"[!].Mon da ton tai, khong thuc hien duoc!!!"<<endl;
	cout<<GREEN<<"An ENTER de thoat!";
	cin.get();
	cin.get();
}

void SuaDiem(BangDiem a[], int m)
{
	system("clear");
	cout<<"[4]. Sua diem"<<endl;
	int MaMonSua;
	int DiemSua;
	int check=0;
	cout<<"- Nhap ma mon muon sua: "; cin>>MaMonSua;
	for(int i=0;i<m;i++)
	{
		if(MaMonSua==a[i].getMaMon())
		{
			check=1;
			break;
		}
	}
	if(check==1)
	{
		cout<<"- Nhap diem muon sua: "; cin>>DiemSua;
		for(int i=0;i<m;i++)
		{
			if(MaMonSua==a[i].getMaMon())
			{
				a[i].setDiem(DiemSua);
			}
		}
		cout<<RED<<"Sua diem thanh cong!"<<endl;
	}
	else
		cout<<RED<<"[!] Mon khong ton tai trong bang diem!!"<<endl;
	cout<<GREEN<<"An ENTER de thoat!";
	cin.get();
	cin.get();
}
void XemBangDiem(BangDiem a[], int m)
{
	system("clear");
	float diem_tong = 0;
	cout<<"[3]. Xem bang diem"<<endl;
	cout<<"\t\tBang Diem"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"   \tMM \tMON       \tDiemTK"<<endl;
	for(int i=0; i<m; i++)
	{
		cout<<"["<<i+1<<"]\t"<<a[i];
	}
	for(int i=0; i<m; i++)
	{
		diem_tong = diem_tong + a[i].getDiem();
	}
	cout.precision(3);
	cout<<GREEN<<"\t\t*Diem trung binh: "<<diem_tong/m<<endl;
	cout<<YELLOW<<"------------------------------------------"<<endl;
	cout<<GREEN<<"An ENTER de thoat!";
	cin.get();
	cin.get();
}

void Xuat_mon_hoc(MonHoc a[], int m)
{
	cout<<"~ Cac Mon Da Co ~"<<endl;
	cout<<"MM\tMon"<<endl;
	for(int i=0; i<m;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"---------------------------------------"<<endl;
}

void ThemMonHoc(MonHoc a[],int &m)
{
	system("clear");
	cout<<"[1]. Them mon hoc"<<endl;
	Xuat_mon_hoc(a,m);
	cout<<"Moi nhap: "<<endl;
	cin>>a[m];
	int check = 1;
	for(int i=0;i<m;i++)
	{
		if(a[m].getMaMon()==a[i].getMaMon())
		{
			check = 0;
			break;
		}
	}
	if(check == 1)
	{
		m++;
		cout<<GREEN<<"[+].Them mon hoc vao data mon hoc thanh cong!"<<endl;
	}
	else
		cout<<RED<<"[!].Mon da ton tai!!"<<endl;
	cout<<GREEN<<"An ENTER de thoat!";
	cin.get();
	cin.get();
}
void Luu_bang_diem_xuong_file(BangDiem a[], int m)
{
	system("clear");
	cout<<"[5]. Luu bang diem xuong file "<<endl;
	char tenfile[100];	
	cout<<"- Nhap ten file ban muon luu: "; 
	cin.ignore();
	cin.getline(tenfile, 100);
	ofstream fout(tenfile);
	for(int j=0; j<m;j++)
	{
		fout<<a[j]<<" ";
	}
	fout.close();
	cout<<RED<<"Luu file thanh cong!!"<<endl;
	cout<<GREEN<<"An Enter de thoat!";
	cin.get();
	cin.get();
}

void Nap_data_mon_hoc(ifstream &filein, MonHoc &a)
{
	filein>>a.MaMonHoc;
	getline(filein, a.TenMon);
}
void Doc_file(ifstream &filein, MonHoc a[], int &m)
{
	do
	{
		Nap_data_mon_hoc(filein,a[m]);
		m++;
	}while(!filein.eof());
}
void Xuat_data_mon_hoc(MonHoc a[], int m)
{
	system("clear");
	cout<<"[6]. Nap data mon hoc tu file"<<endl;
	cout<<"Du lieu da duoc nap vao: "<<endl;
	cout<<"MM\tMon"<<endl;
	for(int i=0; i<m;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"---------------------------------------"<<endl;
	cout<<GREEN<<"An Enter de thoat!";
	cin.get();
	cin.get();
}

void Nap_data_bang_diem(ifstream &filein, BangDiem &a)
{
	int b,c;
	filein>>b;
	a.setMaMon(b);
	getline(filein, a.mon.TenMon);
	filein>>c;
	a.setDiem(c);
}

void Doc_file_bang_diem(ifstream &filein, BangDiem a[], int &m)
{
	do
	{
		Nap_data_bang_diem(filein,a[m]);
		m++;
	}while(!filein.eof());
	
}

void Xuat_data_bang_diem(BangDiem a[], int m)
{
	cout<<"[7]. Nap data bang diem tu file"<<endl;
	cout<<RED<<"Du lieu duoc nap vao thanh cong!!"<<endl;
	for(int i=0;i<m;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<GREEN<<"An Enter de thoat!";
	cin.get();
	cin.get();

}