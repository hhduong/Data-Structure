#ifndef book_h
#define book_h
#include "list.h"
#include "Node.h"
class Book
{
private:
	string TenSach;
	string TacGia;
	int NamXB;
	int SoTrang;
public:
	Book()
	{
		TenSach = "";
		TacGia = "";
		NamXB = 0;
		SoTrang = 0;
	};
	Book(string a, string b, int c, int d)
	{
		TenSach = a;
		TacGia = b;
		NamXB = c;
		SoTrang = d;
	};
	string getTenSach()
	{
		return TenSach;
	};

	string getTacGia()
	{
		return TacGia;
	};

	int getNamXB()
	{
		return NamXB;
	};

	int getSoTrang()
	{
		return SoTrang;
	};

	friend istream & operator >> (istream &in, Book &a)
	{
		cout<<"Nhap ten sach: ";
		in.ignore();
		getline(in, a.TenSach);
		cout<<"Nhap ten tac gia: ";
		getline(in, a.TacGia);
		cout<<"Nhap nam xuat ban: ";
		in>>a.NamXB;
		cout<<"Nhap so trang: ";
		in>>a.SoTrang;
		return in;
	}
	friend ostream & operator << (ostream &out, Book a)
	{
		out<<"\t\t"<<a.TenSach<<"\t\t"<<a.TacGia<<"\t"<<a.NamXB<<"\t"<<a.SoTrang<<endl;
		return out;
	}


};
void SuaSach(List<Book> &l)
{
	int vitri;
	cout<<"Nhap vi tri cuon sach muon sua:";
	cin>>vitri;
	Book a;
	cin>>a;
	l.Change(vitri,a);
}
void ThemSach(List<Book> &l)
{
	Book a;
	cin>>a;
	l.addBack(a);
};
void HienThi(List<Book> &l)
{	
	cout<<"STT\t\tTen Sach\t\tTac Gia\t\t\tNam XB\tSo trang"<<endl;
	l.Display();
};
void Savefile(List<Book> &l)
{
	ofstream fout;
	fout.open("data.txt");
	int count = l.size();
	fout<<count<<endl;
	for(int i=1;i<=count;i++)
	{
		Book a = l.GetAnItem(i);
		fout<<a.getTenSach()<<endl;
		fout<<a.getTacGia()<<endl;
		fout<<a.getNamXB()<<endl;
		fout<<a.getSoTrang()<<endl;
	}
	fout.close();
	cout<<"Luu file thanh cong!!"<<endl;
};
void LoadFile(List<Book> &l)
{
	ifstream fin("data.txt");
	int count;
	fin>>count;
	for(int i=1;i<=count; i++)
	{
		string ts; string tg; int n; int st;
		fin.ignore();
		getline(fin,ts);

		getline(fin,tg);
		fin>>n;
		fin>>st;
		l.addBack(Book(ts,tg,n,st));
	}
	fin.close();
	cout<<"Load file thanh cong!!"<<endl;
}

void Xuat_HTML(List<Book> &l)
{
	char fileName[100];
	cout<<"Nhap ten file HTML muon xuat: ";
	cin.ignore();
	cin.getline(fileName,100);
	ofstream fout(fileName);

	int count = l.size();
	fout<<"<html>\n";
	fout<<"		<head>\n";
	fout<<"		<title>Quan ly thu vien</title>\n";
	fout<<"		</head>\n";
	fout<<"		<body>\n";
	fout<<"		<table border = \"1\">\n";
	fout<<"			<tr\n>";
	fout<<"				<td>STT</td>\n";
	fout<<"				<td>Ten sach</td>\n";
	fout<<"				<td>Tac gia</td>\n";
	fout<<"				<td>Nam XB</td>\n";
	fout<<"				<td>So trang</td>\n";
	fout<<"			<tr\n>";
	for(int i=1; i<=count; i++)
	{
		Book a = l.GetAnItem(i);
		fout<<"			<tr\n>";
		fout<<"				<td>"<<i<<"</td>\n";
		fout<<"				<td>"<<a.getTenSach()<<"</td>\n";
		fout<<"				<td>"<<a.getTacGia()<<"</td>\n";
		fout<<"				<td>"<<a.getNamXB()<<"</td>\n";
		fout<<"				<td>"<<a.getSoTrang()<<"</td>\n";
		fout<<"			<tr\n>";
	}
	fout<<"		</tale>\n";
	fout<<"		</body>\n";
	fout<<"</html>\n";
	fout.close();

};
#endif