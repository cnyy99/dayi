// //陈楠   计算机类16-1班    161002107
// //Microsoft Visual Studio Community 2017 下运行正常
// #include <fstream>
// #include <cstdio>
// #include <sstream>
// #include <cctype>
// #include <ctime>
// #include <string>
// #include <cmath>
// #include <iostream>
// #include <regex>
// using namespace std;
// #define KEYS_LENGTH 65		//关键词个数
// #define M 80               	//散列表的表长(开放地址法)
// #define MM 17               //散列表的表长(链地址法)
// //const string keys[] = { "bool","char", "do", "double","else", "float", "for","goto" ,"if", "int","long","new","return", "void", "while" };   //关键词																																	   //const int KEYS_LENGTH = sizeof(keys) / sizeof(string);
// const string keys[KEYS_LENGTH] = { "asm","auto","bad_cast","bad_typeid","bool","break","case","catch","char","class","const","const_cast","continue",
// "default","delete","do","double","dynamic_cast",
// "else","enum","except","explicit","extern","false","finally","float","for",
// "friend","goto","if","inline","int","long","mutable","namespace","new","operator",
// "private","protected","public","register","return","short",
// "signed","sizeof","static","static_cast","struct","switch","template","this","throw",
// "true","try","type_info","typedef","typeid","typename","union","unsigned","using","virtual","void","volatile","while" };
// int id;
// clock_t start, finish;      //计时起止点
// stringstream sss;
// void read_back(string name);								//除去注释
// bool is_key(string word);									//查找是不是关键词
// void show_win();											//主界面
// void show_win1();
// void show_win2();
// class base
// {
// public:
// 	base(){}
// 	virtual ~base() { }
// 	virtual int get_count(string name) { return 0; }
// 	virtual void add_elem(string name) {}
// 	virtual void clear() {}
// 	virtual void set_s(double x) {}
// 	virtual void set_time(double x) {}
// 	virtual void set_used(bool x) {}
// 	virtual bool get_used() { return true; }
// 	virtual double get_time() { return 0.0; }
// 	virtual double get_s() { return 0.0; }
// private:

// };
// class myvector													//向量类
// {
// public:
// 	myvector();
// 	void creat_myvector(int *a);								//通过数组创建类
// 	~myvector() {}
// 	friend myvector operator-(myvector x1, myvector x2);		//重载 - 运算符
// 	friend int operator*(myvector x1, myvector x2);				//重载 * 运算符
// private:
// 	int x[KEYS_LENGTH];											//长为KEYS_LENGTH的数组保存关键字频数;
// };
// myvector::myvector()
// {
// 	for (int i = 0; i < KEYS_LENGTH; i++)
// 		x[i] = 0;
// }
// void myvector::creat_myvector(int * a)
// {
// 	for (int i = 0; i < KEYS_LENGTH; i++)
// 		x[i] = a[i];
// }
// myvector operator-(myvector x1, myvector x2)
// {
// 	for (int i = 0; i < KEYS_LENGTH; i++)
// 		x1.x[i] -= x2.x[i];
// 	return x1;
// }
// int operator*(myvector x1, myvector x2)
// {
// 	int num = 0;
// 	for (int i = 0; i < KEYS_LENGTH; i++)
// 	{
// 		num += x1.x[i] * x2.x[i];
// 	}
// 	return num;
// }
// myvector ht1, ht2;
// typedef struct {
// 	string  KeyName;								//关键字名字
// 	int count;										//关键字频度
// }HashTable;
// class hashtable :public base
// {
// public:
// 	hashtable();									//默认构造函数
// 	void add_elem(string name);						//添加元素	
// 	void kaifang_chongtu(string str, int key);		//添加冲突处理
// 	int get_count(string name);						//返回出现频数
// 	int get_key(string str);						//返回hash运算后的key
// 	int find_chongtu(string str, int key);			//查找冲突处理办法
// 	void clear();
// 	void set_s(double x)
// 	{
// 		s = x;
// 	}
// 	void set_used(bool t)
// 	{
// 		used = t;
// 	}
// 	void set_time(double x)
// 	{
// 		time = x;
// 	}
// 	double get_time()
// 	{
// 		return time;
// 	}
// 	double get_s()
// 	{
// 		return s;
// 	}
// 	bool get_used()
// 	{
// 		return used;
// 	}
// 	~hashtable();									//默认析构函数
// private:
// 	HashTable HT[2][M];											//HashTable数组   
// 	double time, s;
// 	bool used = false;
// };
// hashtable::hashtable()
// {
// 	clear();
// }
// void hashtable::add_elem(string str)
// {
// 	int key = get_key(str);
// 	if (HT[id][key].KeyName == "" || HT[id][key].KeyName == str)
// 	{
// 		HT[id][key].KeyName = str;
// 		HT[id][key].count++;
// 	}
// 	else
// 	{
// 		kaifang_chongtu(str, key);
// 	}
// }
// void hashtable::kaifang_chongtu(string str, int key)
// {
// 	key = (++key) % M;
// 	if (HT[id][key].KeyName == "" || HT[id][key].KeyName == str)
// 	{
// 		HT[id][key].KeyName = str;
// 		HT[id][key].count++;
// 	}
// 	else
// 	{
// 		kaifang_chongtu(str, key);
// 	}
// }
// int hashtable::get_count(string str)
// {
// 	int key = get_key(str);
// 	if (HT[id][key].KeyName == "")
// 	{
// 		return 0;
// 	}
// 	else if (HT[id][key].KeyName == str)
// 	{
// 		return HT[id][key].count;
// 	}
// 	else
// 	{
// 		return find_chongtu(str, key);
// 	}
// 	return 0;
// }
// int hashtable::get_key(string str)
// {
// 	int n = 0;
// 	for (auto &a : str)
// 	{
// 		n += a;
// 	}
// 	return n%M;
// }
// void hashtable::clear()
// {
// 	for (int j = 0; j<2; j++)
// 		for (int i = 0; i < M; i++)
// 		{
// 			HT[j][i].KeyName = "";
// 			HT[j][i].count = 0;
// 		}
// 	id = 0;
// }
// int hashtable::find_chongtu(string str, int key)
// {
// 	key = (++key) % M;
// 	if (HT[id][key].KeyName == "")
// 	{
// 		return 0;
// 	}
// 	else if (HT[id][key].KeyName == str)
// 	{
// 		return HT[id][key].count;
// 	}
// 	else
// 	{
// 		return find_chongtu(str, key);
// 	}
// }
// hashtable::~hashtable()
// {
// }
// typedef struct HashNode {
// 	string  KeyName;		//关键字名字
// 	int count;			    //关键字频度
// 	struct HashNode *next;
// } *HashLink;
// class myhashlink :public base
// {
// public:
// 	myhashlink();
// 	~myhashlink();
// 	void add_elem(string name);
// 	int get_count(string name);
// 	int get_key(string str);
// 	void clear();
// 	void set_s(double x)
// 	{
// 		s = x;
// 	}
// 	void set_used(bool t)
// 	{
// 		used = t;
// 	}
// 	void set_time(double x)
// 	{
// 		time = x;
// 	}
// 	double get_time()
// 	{
// 		return time;
// 	}
// 	double get_s()
// 	{
// 		return s;
// 	}
// 	bool get_used()
// 	{
// 		return used;
// 	}
// private:
// 	HashLink HT[2][MM];
// 	double time, s;
// 	bool used = false;
// };
// myhashlink::myhashlink()
// {
// 	for (int j = 0; j<2; j++)
// 		for (int i = 0; i < MM; i++)
// 			HT[j][i] = nullptr;
// 	id = 0;
// }
// myhashlink::~myhashlink()
// {
// 	clear();
// }
// void myhashlink::clear()
// {
// 	HashLink p;
// 	for (int j = 0; j<2; j++)
// 		for (int i = 0; i < MM; i++)
// 		{
// 			p = HT[j][i];
// 			while (p)
// 			{
// 				HT[j][i] = HT[j][i]->next;
// 				delete p;
// 				p = HT[j][i];
// 			}
// 		}
// 	id = 0;
// }
// void myhashlink::add_elem(string name)
// {
// 	int key = get_key(name);
// 	if (HT[id][key] == nullptr)
// 	{
// 		HT[id][key] = new HashNode;
// 		HT[id][key]->KeyName = name;
// 		HT[id][key]->count = 1;
// 		HT[id][key]->next = nullptr;
// 	}
// 	else
// 	{
// 		if (!get_count(name))
// 		{
// 			HashLink p;
// 			p = HT[id][key];
// 			while (p->next)
// 			{
// 				p = p->next;
// 			}
// 			p->next = new HashNode;						//后插法
// 			p->next->KeyName = name;
// 			p->next->count = 1;
// 			p->next->next = nullptr;

// 			//p = new HashNode;							//前插法
// 			//p->KeyName = name;
// 			//p->count = 1;
// 			//p->next = HT[key];
// 			//HT[id][key] = p;
// 		}
// 		else
// 		{
// 			HashLink p;
// 			p = HT[id][key];
// 			while (p&&p->KeyName != name)
// 			{
// 				p = p->next;
// 			}
// 			if (p)
// 				p->count++;
// 		}
// 	}
// }
// int myhashlink::get_count(string name)
// {
// 	int key = get_key(name);
// 	if (HT[id][key] == nullptr)
// 	{
// 		return 0;
// 	}
// 	else
// 	{
// 		HashLink p;
// 		p = HT[id][key];
// 		while (p&&p->KeyName != name)
// 		{
// 			p = p->next;
// 		}
// 		if (p)
// 			return p->count;
// 		else
// 			return 0;
// 	}
// 	return 0;
// }
// int myhashlink::get_key(string str)
// {
// 	int n = 0;
// 	for (auto &a : str)
// 	{
// 		n += a;
// 	}
// 	return n%MM;
// }
// class myarray :public base
// {
// public:
// 	myarray();
// 	~myarray();
// 	void add_elem(string name);
// 	int get_count(string name);
// 	void clear();
// 	int get_key(string word);
// 	void set_s(double x)
// 	{
// 		s = x;
// 	}
// 	void set_used(bool t)
// 	{
// 		used = t;
// 	}
// 	void set_time(double x)
// 	{
// 		time = x;
// 	}
// 	double get_time()
// 	{
// 		return time;
// 	}
// 	double get_s()
// 	{
// 		return s;
// 	}
// 	bool get_used()
// 	{
// 		return used;
// 	}
// private:
// 	int x[2][KEYS_LENGTH];
// 	double time, s;
// 	bool used = false;
// };
// myarray::myarray()
// {
// 	clear();
// }
// myarray::~myarray()
// {
	
// }
// void myarray::add_elem(string name)
// {
// 	int key = get_key(name);
// 	if (key == -1)
// 		return;
// 	x[id][key]++;
// }
// int myarray::get_count(string name)
// {
// 	int key = get_key(name);
// 	if (key == -1)
// 		return 0;
// 	return x[id][key];
// }
// void myarray::clear()
// {
// 	for (int j = 0; j < 2; j++)
// 		for (int i = 0; i < KEYS_LENGTH; i++)
// 		{
// 			x[j][i] = 0;
// 		}
// 	id = 0;
// }
// int myarray::get_key(string word)
// {
// 	int low = 0, high = KEYS_LENGTH, mid;
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (word == keys[mid])
// 			return mid;
// 		else if (word > keys[mid])
// 			low = mid + 1;
// 		else
// 			high = mid - 1;
// 	}
// 	return -1;
// }
// myarray xl1, xl2;
// base* a = new hashtable();
// base* b = new myhashlink();
// base* c = new myarray();
// void write_cpp(base *x, string name)
// {
// 	fstream out;
// 	out.open(name, ios::out);
// 	int i, num;
// 	int a[KEYS_LENGTH];
// 	for (i = 0; i < KEYS_LENGTH; i++)
// 	{
// 		a[i] = x->get_count(keys[i]);
// 		num = a[i];
// 		//cout <<"	"<< keys[i] << "的频数为：\t" << num << endl;
// 		out << " " << keys[i];
// 		keys[i].length() < 7 ? out << "\t\t" : out << "\t";
// 		out << "的频数为：\t" << num << endl;
// 	}
// 	id ? ht2.creat_myvector(a) : ht1.creat_myvector(a);
// 	out.close();
// 	double r=0.0, time = 0.0;
// 	id ? r = sqrt((ht1 - ht2)*(ht1 - ht2)) / (sqrt(ht1*ht1)*sqrt(ht2*ht2)) : r;
// 	x->set_s(r);
// 	id ? finish = clock() : finish;
// 	id ? time = 1000 * (double)(finish - start) / CLOCKS_PER_SEC : time;
// 	x->set_time(time);
// }
// void read_cpp(base *a,string name)
// {
// 	read_back(name);
// 	string str;
// 	while (sss >> str && !sss.eof())
// 	{
// 		if (is_key(str))
// 		{
// 			a->add_elem(str);
// 		}
// 	}
// 	sss.clear();
// }
// void write(base *a)
// {
// 	id = 0;
// 	if (a->get_used())
// 	{
// 		a->clear();
// 	}
// 	start = clock();
// 	read_cpp(a,"InFile1.cpp");
// 	write_cpp(a,"OutFile1.txt");
// 	id++;
// 	read_cpp(a,"InFile2.cpp");
// 	write_cpp(a,"OutFile2.txt");
// 	cout << "识别并统计关键词频度完成，已保存到OutFile1.txt和OutFile2.txt文件中" << endl << endl;
// 	//cout << "write_cpp" << endl;
// 	if (a->get_used())
// 		system("pause");
// 	a->set_used(true);
// }
// void show_s(base*x)
// {
// 	if (!x->get_used())
// 	{
// 		cout << "尚未统计过，先为您进行统计。" << endl << endl;
// 		write(x);
// 	}
// 	cout << "相对距离为：" << x->get_s() << endl << endl;
// 	system("pause");
// }
// void show_time(base*x)
// {
// 	if (!x->get_used())
// 	{
// 		cout << "尚未统计过，先为您进行统计。" << endl << endl;
// 		write(x);
// 	}
// 	if ((dynamic_cast<myarray*>(x)) != nullptr)
// 		cout << "线性表法执行时间为：";
// 	else if ((dynamic_cast<myhashlink*>(x)) != nullptr)
// 		cout << "链地址法执行时间为：";
// 	else
// 		cout << "开放地址法法执行时间为：";
// 	cout << x->get_time() << "毫秒" << endl << endl;
// 	system("pause");
// }
// void show_win();											//主界面
// void show_win1();
// void show_win2();
// void show_win1()
// {
// 	//	system("cls");
// 	cout << "(1)识别并统计关键词频度" << endl << "(2)计算相对距离S" << endl << "(3)开放地址法执行时间" << endl << "(4)返回主界面" << endl;
// 	string s;
// 	int temp;
// 	cin >> s;
// 	while (s != "1"&&s != "2"&&s != "3"&&s != "4")
// 	{
// 		cout << "输入错误，请重新输入！" << endl;
// 		cin >> s;
// 	}
// 	stringstream t;
// 	t << s;
// 	t >> temp;
// 	//base* x = new hashtable();
// 	switch (temp)
// 	{
// 	case 1:write(a); show_win1(); break;
// 	case 2:show_s(a); show_win1(); break;
// 	case 3:show_time(a); show_win1(); break;
// 	case 4:show_win();
// 	}
// }
// void show_win2()
// {
// 	//system("cls");
// 	cout << "(1)识别并统计关键词频度" << endl << "(2)计算相对距离S" << endl << "(3)链地址法执行时间" << endl << "(4)返回主界面" << endl;
// 	string s;
// 	int temp;
// 	cin >> s;
// 	while (s != "1"&&s != "2"&&s != "3"&&s != "4")
// 	{
// 		cout << "输入错误，请重新输入！" << endl;
// 		cin >> s;
// 	}
// 	stringstream t;
// 	t << s;
// 	t >> temp;

// 	switch (temp)
// 	{
// 	case 1:write(b); show_win2(); break;
// 	case 2:show_s(b); show_win2(); break;
// 	case 3:show_time(b); show_win2(); break;
// 	case 4:show_win();
// 	}
// }
// void show_win4()
// {
// 	//system("cls");
// 	cout << "(1)识别并统计关键词频度" << endl << "(2)计算相对距离S" << endl << "(3)线性表法执行时间" << endl << "(4)返回主界面" << endl;
// 	string s;
// 	int temp;
// 	cin >> s;
// 	while (s != "1"&&s != "2"&&s != "3"&&s != "4")
// 	{
// 		cout << "输入错误，请重新输入！" << endl;
// 		cin >> s;
// 	}
// 	stringstream t;
// 	t << s;
// 	t >> temp;

// 	switch (temp)
// 	{
// 	case 1:write(c); show_win4(); break;
// 	case 2:show_s(c); show_win4(); break;
// 	case 3:show_time(c); show_win4(); break;
// 	case 4:show_win();
// 	}
// }
// bool is_key(string word)														//折半查找确定此字母串是否为关键字
// {
// 	int low = 0, high = KEYS_LENGTH, mid;
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (word == keys[mid])
// 			return true;
// 		else if (word > keys[mid])
// 			low = mid + 1;
// 		else
// 			high = mid - 1;
// 	}
// 	return false;
// }
// void show_win()
// {
// 	//system("pause");
// 	//system("cls");
// 	cout << "(1)开放地址法" << endl << "(2)链地址法" << endl << "(3)使用线性表计算时用时" << endl << "(4)退出系统" << endl << endl << "请选择您需要的服务：";
// 	string s;
// 	int temp;
// 	cin >> s;
// 	while (s != "1"&&s != "2"&&s != "3"&&s != "4")
// 	{
// 		cout << "输入错误，请重新输入！" << endl;
// 		cin >> s;
// 	}
// 	stringstream t;
// 	t << s;
// 	t >> temp;
// 	switch (temp)
// 	{
// 	case 1:show_win1(); break;
// 	case 2:show_win2(); break;
// 	case 3:show_win4(); break;
// 	case 4:exit(EXIT_SUCCESS);
// 	}
// }
// void read_back(string name)               //去注释
// {
// 	ifstream in;
// 	string str, s;
// 	int n;
// 	//clock_t a = clock();
// 	in.open(name, ios::in);
// 	if (!in.is_open())
// 	{
// 		cout << "打开文件失败。请检查文件是否存在." << endl;
// 		system("pause");
// 		show_win();
// 	}
// 	while (!in.eof())
// 	{
// 		getline(in, s);
// 		str.append(s + "\n");
// 	}
// 	//cout << str;
// 	int i = 0;
// 	while (i < str.length())
// 	{
// 		if (str[i] == '/')
// 		{
// 			if (str[++i] == '*')
// 			{
// 				n = 2;
// 			loop:while (str[++i] != '*')
// 			{
// 				n++;
// 			}
// 				 if (str[++i] == '/')
// 				 {
// 					 if (str[i + 1] == '\n')
// 						 n++;
// 					 n++;
// 					 i++;
// 					 i -= n;
// 					 str.erase(i, n);
// 					 continue;
// 				 }
// 				 else
// 				 {
// 					 n++;
// 					 goto loop;
// 				 }
// 				 continue;
// 			}
// 			else if (str[i] != '/')
// 				continue;
// 			n = 2;
// 			while (str[++i] != '\n')
// 			{
// 				n++;
// 			}
// 			i -= n;
// 			str.erase(i, n);
// 		}
// 		if (str[i] > 0 && !isalnum(str[i]) && str[i] != '_'&&str[i] != '$')
// 			str[i] = ' ';
// 		i++;
// 	}
// 	in.close();
// 	sss << str;
// 	//cout << str;
// 	//cout <<"去注释用时" <<(double)(clock() - a) / CLOCKS_PER_SEC <<"秒"<< endl;
// }
// int main()
// {
// 	show_win();
// 	return 0;
// }
#include<iostream>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstring>
using namespace std;
int partition(int *a, int low, int high)
{
	const auto pivotkey = a[low];
	while(low<high)
	{
		while (low<high&&a[high]>=pivotkey)
			high--;
		a[low] = a[high];
		while (low < high&&a[low] <= pivotkey)
			low++;
		a[high] = a[low];
	}
	a[low] = pivotkey;
	return low;
}
void quicksort(int *a, int low, int high)
{
	if (low < high)
	{
		auto mid = partition(a, low, high);
		quicksort(a, low, mid - 1);
		quicksort(a, mid + 1, high);
	}
}
int close(int *a,int n)
{
	auto diff = INT_MAX;
	quicksort(a, 0, n - 1);
	for (auto i = 0; i < n - 1; i++)
	{
		if (abs(a[i] - a[i + 1]) < diff)
			diff = abs(a[i] - a[i + 1]);
		if (diff == 0)
			return diff;
	}
	return diff;
}
int main()
{
	int n;
	cin >> n;
	auto a = new int[n];
	for (auto i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	const clock_t start = clock();
	auto diff = close(a, n);
	const clock_t end = clock();
	cout << "最相近的数的差的绝对值为：" <<endl<< diff << endl;
	cout << "用时:" << static_cast<double>(end - start)*1000 / CLOCKS_PER_SEC <<"ms"<< endl;
	system("pause");
	return 0;
}
