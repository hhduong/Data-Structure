#ifndef contacts_h
#define contacts_h
#include "list.h"
#include "Node.h"
class Contacts
{
private:
	string Name;
	int PhoneNumber;
public:
	Contacts()
	{
		Name = "";
		PhoneNumber = 0;
	};
	Contacts(string a, int b)
	{
		Name = a;
		PhoneNumber = b;
	};
	void setName(string a)
	{
		Name = a;
	}
	string getName()
	{
		return Name;
	};
	int getPhoneNumber()
	{
		return PhoneNumber;
	};
	friend istream & operator >> (istream &in, Contacts &a)
	{
		cout<<"Enter name: ";
		in.ignore();
		getline(in, a.Name);
		cout<<"Enter phone number: ";
		in>>a.PhoneNumber;
		return in;
	}
	friend ostream & operator << (ostream &out, Contacts a)
	{
		out<<"  \t"<<a.Name<<"\t"<<a.PhoneNumber;
	}

};

void New_contacts(List<Contacts> &l)
{
	Contacts a;
	cin>>a;
	l.addBack(a);
};
void Show_contacts(List<Contacts> &l)
{
	cout<<"STT\tTen\tSDT"<<endl;
	l.Display();
};
void Seach_Contacts(List<Contacts> &l)
{
	int count = l.size();
	string name;
	cout<<"Enter name you want to find: ";
	cin.ignore();
	getline(cin, name);
	for(int i=0;i<count;i++)
	{
		Contacts b = l.GetAnItem(i);
		if(name==b.getName())
		{
			cout<<b<<endl;
		} 
	}
};

void Savefile(List<Contacts> &l)
{
	ofstream fout;
	fout.open("data.txt");
	int count = l.size();
	fout<<count<<endl;
	for(int i=1;i<=count;i++)
	{
		Contacts a = l.GetAnItem(i);
		fout<<a.getName()<<endl;
		fout<<a.getPhoneNumber()<<endl;
	}
	fout.close();
	cout<<"Finish!!"<<endl;
};

void LoadFile(List<Contacts> &l)
{
	ifstream fin("data.txt");
	int count;
	fin>>count;
	for(int i=1;i<=count; i++)
	{
		string name;
		int phonenumber;
		fin.ignore();
		getline(fin,name);
		fin>>phonenumber;
		l.addBack(Contacts(name,phonenumber));
	}
	fin.close();
	cout<<"Finish!!"<<endl;
};

void Edit(List<Contacts> &l)
{
	int pos;
	cout<<"Enter the address: ";
	cin>>pos;
	Contacts a;
	cin>>a;
	l.Change(pos,a);
};

void Export_HTML(List<Contacts> &l)
{
	char fileName[100];
	cout<<"Nhap ten file HTML muon xuat: ";
	cin.ignore();
	cin.getline(fileName,100);
	ofstream fout(fileName);

	int count = l.size();
	fout<<"<html>\n";
	fout<<"		<head>\n";
	fout<<"		<title>MY CONTACTS</title>\n";
	fout<<"		</head>\n";
	fout<<"		<body>\n";
	fout<<"		<table border = \"1\">\n";
	fout<<"			<tr\n>";
	fout<<"				<td>STT</td>\n";
	fout<<"				<td>Name</td>\n";
	fout<<"				<td>Phone Number</td>\n";
	fout<<"			<tr\n>";
	for(int i=1; i<=count; i++)
	{
		Contacts a = l.GetAnItem(i);
		fout<<"			<tr\n>";
		fout<<"				<td>"<<i<<"</td>\n";
		fout<<"				<td>"<<a.getName()<<"</td>\n";
		fout<<"				<td>"<<a.getPhoneNumber()<<"</td>\n";
		fout<<"			<tr\n>";
	}
	fout<<"		</tale>\n";
	fout<<"		</body>\n";
	fout<<"</html>\n";
	fout.close();

};

#endif