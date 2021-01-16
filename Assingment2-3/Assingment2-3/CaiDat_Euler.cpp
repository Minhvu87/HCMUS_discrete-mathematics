#include "DoThi_Euler.h"
#include "stdafx.h"
Euler::Euler(){
	danhDau[1] = 0;
	bac = 0;
	canh = 0;\
}
bool Euler::kiemTraFile(int a[][MAX], int& n, int& start, int& goal, string filename) {
	if (filename == "Dothi1.txt") {
		f.readFile(filename, a, n, start, goal);
	}
	if (filename == "Dothi2.txt") {
		f.readFile(filename, a, n, start, goal);
	}
	if (filename == "Dothi3.txt") {
		f.readFile_1(filename, a, n, start, goal);
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
bool Euler::kiemTraEuler(int a[][MAX],int n){
	for (int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<n ; j++)
		{
			if (a[i][j] != 0)
			{
				bac++;
			}
		}
		if (bac %2 == 1)	//bac chan
		{
			return false;
		}
	}
	return true;
}
int Euler::tinhCanh(int a[][MAX],int n){
	canh = bac/2;
	return canh;
}
void Euler::xuatChuTrinh(int a[][MAX],int n){
	//cout<<"\nChu Trinh Euler \n";
	cout<<xuatPhat;
	for (int i=1 ; i<=canh ; i++)
	{
		cout<<"->"<<danhDau[i];
		
	}
	//if (danhDau[i] = xuatPhat) break;
	cout<<endl;
	//system("pause");
	//exit(1);
}
void Euler::chuTrinh_Euler(int a[][MAX],int n, int xuatPhat, int y){
		for (int i=0 ; i<n ; i++)
		{
			if (a[xuatPhat][i] != 0)
			{
				danhDau[y] = i;
				a[xuatPhat][i] = a[i][xuatPhat] = 0;
				if (y == tinhCanh(a,n))
				{
					xuatChuTrinh(a,n);
				}
				else
				{
					chuTrinh_Euler(a,n,i,y+1);
				}
				a[xuatPhat][i] = a[i][xuatPhat] =1;
			}
		}
}
