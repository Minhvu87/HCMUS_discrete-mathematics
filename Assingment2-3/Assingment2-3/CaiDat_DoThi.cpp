#include "DoThi.h"
#include "stdafx.h"
Graph::Graph(){
	tongBac = 0;
	canh = 0;
	TPLienThong = 0;
	danhDau[1] = 0;
	truoc[1] = 0;
	chuaXet[1] = 0;
}
string Xuly(string filename, int a)
{
	if (filename == "Dothi1.txt") {
		switch (a)
		{
		case 0: return "a";
		case 1: return "b";
		case 2: return "c";
		case 3: return "d";
		case 4: return "e";
		}
	}
	if (filename == "Dothi2.txt") {
		switch (a)
		{
		case 0: return "A";
		case 1: return "B";
		case 2: return "C";
		case 3: return "D";
		case 4: return "E";
		case 5: return "F";
		case 6: return "G";
		}
	}
	if (filename == "Dothi3.txt") {
		switch (a)
		{
		case 0: return "Aa";
		case 1: return "Ac";
		case 2: return "Ba";
		case 3: return "C";
		case 4: return "aa";
		}
	}
}
bool Graph::kiemTraFile(int a[][MAX],int &n,int &start,int &goal,string filename){
	if (filename == "Dothi1.txt") {
		f.readFile(filename, a, n, start, goal);
		cout << endl;
		cout << "a" << "\t" << "b" << "\t" << "c" << "\t" << "d" << "\t" << "e"<< endl;
		f.xuatFile(filename, a, n);
	}
	if (filename == "Dothi2.txt") {
		f.readFile(filename, a, n, start, goal);
		cout << endl;
		cout << "A" << "\t" << "B" << "\t" << "C" << "\t" << "D" << "\t" << "E" <<"\t"<<"F"<<"\t"<<"G"<< endl;
		f.xuatFile(filename, a, n);
	}
	if (filename == "Dothi3.txt") {
		f.readFile_1(filename, a, n, start, goal);
		cout << endl;
		cout << "Aa" << "\t" << "Ac" << "\t" << "Ba" << "\t" << "C" << "\t" << "aa" << endl;
		f.xuatFile(filename, a, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[j][i])
			{
				return false;
			}
		}
	}
	return true;
}
int Graph::tinhBac(int a[][MAX],int n){
	for (int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<n ; j++)
		{
			if(a[i][j] != 0)
				tongBac++;
		}
	}
	return tongBac;
}
int Graph::tinhCanh(int a[][MAX],int n){
	//Tong bac = 2 * canh;
	canh = tongBac / 2;
	return canh;
}
char Graph::Lien_Thong(int a[][MAX], int n) {
	char* DanhDau = new char[n];
	char ThanhCong;
	int Dem = 0;
	for (int i = 0; i < n; i++) //Khoi tao moi dinh chua danh dau
		DanhDau[i] = 0;
	DanhDau[0] = 1; //danh dau dinh dau
	Dem++; //dem so dinh duoc danh dau
	do {
		ThanhCong = 1; //khong con kha nang loang
		for (int i = 0; i < n; i++)
			if (DanhDau[i] == 1)
			{
				for (int j = 0; j < n; j++)
					if (DanhDau[j] == 0 && a[i][j] > 0)
					{
						DanhDau[j] = 1;
						ThanhCong = 0; //con kha nang loang
						Dem++;
						if (Dem == n)
							return 1;
					}
			}
	} while (ThanhCong == 0); //lap lai cho den khi khong con kha nang loan
	return 0;
}
void Graph::timDinhLienThong(int a[][MAX],int n,int x){
	cout<<"\nCac dinh lien thong voi dinh "<<x<<" la";
	for (int i=0 ; i<n ; i++)
	{
		if (a[x][i] != 0)
		{
			cout<<","<<i;
		}
	}
	cout<<endl;
}
void Graph::DFSDeQuy(int a[][MAX],int n,int x){
	//duyet 1 thanh phan lien thong.
	cout<<","<<x;
	danhDau[x] = TPLienThong;
	for (int i=0 ; i<n ; i++)
	{
		if (a[x][i] != 0 && !danhDau[i])
		{
			truoc[i] = x;
			DFSDeQuy(a,n,i);
		}
	}
}
void Graph::DFS_QuayLui(int a[][MAX],int n){
	//duyet toan bo thanh phan lien thong.
	for (int i=0 ; i<n ; i++)
	{
		danhDau[i] = 0;
		for (int i=0 ; i<n ; i++)
		{
			if (!danhDau[i])
			{
				TPLienThong++;
				DFSDeQuy(a,n,i);
			}
		}
	}
}
