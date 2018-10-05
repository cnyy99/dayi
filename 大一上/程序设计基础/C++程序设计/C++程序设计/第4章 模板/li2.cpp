#include <iostream>
using namespace std;

template <class T, int N> 
class ABC{
private:
	T array[N];
public:
	void set(T base)
	{
		for(int i = 0;i<N;i++)
			array[i] = base + i;
	}
	void get(){
		cout<<"数组元素总数为："<<N<<"\n";
		for(int i = 0; i<N;i++)
			cout<<array[i]<<" ";
		cout<<endl;
	}
	
};

int main()
{
	ABC <int,10> abc1;
	abc1.set(0);
	abc1.get();
	ABC <double, 20> abc2;
	abc2.set(100);
	abc2.get();
	
	return 0;
}