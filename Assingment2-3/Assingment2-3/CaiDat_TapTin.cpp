#include "TapTin.h"
#include <string>
#include <vector>
int vertArr[20][20];
//void File::setFile(int x ,int y){
//	setReadFile(x,y);
//	getReadFile(x,y);
//}
void add_edge(int u, int v, int value) {
	vertArr[u][v] = value;
	vertArr[v][u] = value;
}

int Xu_ly_chuoi(string s) {

	if (s == "A")return 0;
	else if (s == "a")return 0;
	else if (s == "B")return 1;
	else if (s == "b")return 1;
	else if (s == "C")return 2;
	else if (s == "c")return 2;
	else if (s == "D")return 3;
	else if (s == "d")return 3;
	else if (s == "E")return 4;
	else if (s == "e")return 4;
	else if (s == "F")return 5;
	else if (s == "f")return 5;
	else if (s == "G")return 6;
	else if (s == "g")return 6;
}
int Xu_ly_chuoi_1(string s) {
	if (s == "Aa")return 0;
	else if (s == "Ac")return 1;
	else if (s == "Ba") return 2;
	else if (s == "C") return 3;
	else if (s == "aa")return 4;
}
int Xu_ly_so(string s) {
	if (s == "0") return 0;
	else if (s == "1") return 1;
	else if (s == "2") return 2;
	else if (s == "3") return 3;
	else if (s == "4") return 4;
	else if (s == "5") return 5;
	else if (s == "6") return 6;
	else if (s == "7") return 7;
	else if (s == "8") return 8;
	else if (s == "9") return 9;
	else if (s == "10") return 10;
}
bool IsParentheseOrDash(char c)
{
	switch (c)
	{
	case '(':
	case ')':
		return true;
	default:
		return false;
	}
}
vector <string> split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}
string Bien1(string s, string delimiter) {
	vector<string>v;
	for (int i = 3; i < s.size(); i++) {

		v = split(s, delimiter);
	}
	//cout<<v[0]; cout << endl;
	//cout << s;
	return v[0];
}
string Bien2(string s, string delimiter) {
	vector<string>v;
	for (int i = 3; i < s.size(); i++) {

		v = split(s, delimiter);
	}
	//cout<<v[0]; cout << endl;
	//cout << s;
	return v[1];
}

string Bien3(string s, string delimiter) {
	vector<string>v;
	for (int i = 3; i < s.size(); i++) {

		v = split(s, delimiter);
	}
	//cout<<v[0]; cout << endl;
	//cout << s;
	return v[2];
}
void File::readFile(string filename, int a[][MAX], int& n, int& start, int& goal) {
	//cout << "Doc tap tin:" << filename << endl;

	vector<string>line;
	ifstream ifile(filename);
	string mystr;
	while (ifile >> mystr)
	{
		line.push_back(mystr);

	}
	/*for (int i = 0; i < line.size(); i++)
	{
		cout << line[i] << endl;
	}
	*/
	//cout << line[3].size();
	/*ifile >> n;
	stoi(line[1]) >> start;
	stoi(line[2]) >> goal;*/
	n = stoi(line[0]);
	start = stoi(line[1]);
	goal = stoi(line[2]);
	string delimiter = ",";
	vector <string>s;
	for (int i = 3; i < line.size(); i++) {
		line[i].erase(remove_if(line[i].begin(), line[i].end(), &IsParentheseOrDash), line[i].end());
		//cout << line[i] << endl;
	}
	vector<string>BIEN1, BIEN2, BIEN3;
	for (int i = 3; i < line.size(); i++) {
		BIEN1.push_back(Bien1(line[i], ","));
	}
	for (int i = 3; i < line.size(); i++) {
		BIEN2.push_back(Bien2(line[i], ","));
	}
	for (int i = 3; i < line.size(); i++) {
		BIEN3.push_back(Bien3(line[i], ","));
	}
	for (int i = 0; i < BIEN1.size(); i++) {
			add_edge(Xu_ly_chuoi(BIEN1[i]), Xu_ly_chuoi(BIEN2[i]), Xu_ly_so(BIEN3[i]));
	}
	//cout << start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = vertArr[i][j];
		}
	}
	//displayMatrix(n);
}
void File::readFile_1(string filename, int a[][MAX], int& n, int& start, int& goal) {
	//cout << "Doc tap tin:" << filename << endl;

	vector<string>line;
	ifstream ifile(filename);
	string mystr;
	while (ifile >> mystr)
	{
		line.push_back(mystr);

	}
	/*for (int i = 0; i < line.size(); i++)
	{
		cout << line[i] << endl;
	}*/

	//cout << line[3].size();
	/*ifile >> n;
	stoi(line[1]) >> start;
	stoi(line[2]) >> goal;*/
	n = stoi(line[0]);
	start = stoi(line[1]);
	goal = stoi(line[2]);
	string delimiter = ",";
	vector <string>s;
	for (int i = 3; i < line.size(); i++) {
		line[i].erase(remove_if(line[i].begin(), line[i].end(), &IsParentheseOrDash), line[i].end());
		//cout << line[i] << endl;
	}
	vector<string>BIEN1, BIEN2, BIEN3;
	for (int i = 3; i < line.size(); i++) {
		BIEN1.push_back(Bien1(line[i], ","));
	}
	for (int i = 3; i < line.size(); i++) {
		BIEN2.push_back(Bien2(line[i], ","));
	}
	for (int i = 3; i < line.size(); i++) {
		BIEN3.push_back(Bien3(line[i], ","));
	}
	for (int i = 0; i < BIEN1.size(); i++) {
			add_edge(Xu_ly_chuoi_1(BIEN1[i]), Xu_ly_chuoi_1(BIEN2[i]), Xu_ly_so(BIEN3[i]));
	}
	//cout << start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = vertArr[i][j];
		}
	}
	//displayMatrix(n);
}
void File::xuatFile(string filename, int a[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
