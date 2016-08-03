#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;


const string suf = ".txt";

void update(string &st)
{
	for (int i = 0; i < st.size(); i++)
	{
		st[i] = tolower(st[i]);
	}
}
bool check(string st)
{
	for (int i = 0; i < st.size(); i++)
	{
		if (st[i] < 'a' || st[i] > 'z') return false;
	}
	return true;
}
int main()
{
	string name;
	cin >> name;
	ifstream in((name + suf).c_str());
	int n, cnt = 0;
	in >> n;
	for (int i = 0; i < n; i++)
	{
		string st1, st2;
		in >> st1 >> st2;
		update(st1);
		bool flag = check(st1);
		if (flag) cnt++;
	}
	in.close();
	
	ifstream in2((name + suf).c_str());
	ofstream out1((name + "_word" + suf).c_str());
	ofstream out2((name + "_meaning" + suf).c_str());
	ofstream out3((name + "_sentence" + suf).c_str());

	in2 >> n;
	out1 << cnt << endl;
	out2 << cnt << endl;
	out3 << cnt << endl;
	for (int i = 0; i < n; i++)
	{
		string st1, st2;
		in2 >> st1 >> st2;
		update(st1);
		bool flag = check(st1);
		if (flag)
		{
			out1 << st1 << endl;
			out2 << st2 << endl;
			out3 << 0 << endl;
		}
	}
	
	out1.close();
	out2.close();
	out3.close();
	return 0;
}
