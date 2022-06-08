#include<iostream>
using namespace std;

template<typename Type>
Type GetMax(Type a, Type b)
{
	if (a > b)
		return a;
	else
		return b;
}

template<typename Type>
Type GetMin(Type a, Type b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
class Pair
{
	T values[2];

	template<class T> friend ostream& operator<<(ostream& cout, const Pair<T>& p);

public:

	Pair(T a, T b)
	{
		values[0] = a;
		values[1] = b;
	}

	Pair greater()
	{
		return(GetMax(values[0], value[1]));
	}
	Pair smaller();
};
template<class T>
ostream& operator<<(ostream& cout, const Pair<T>& p) {
	cout << p << endl;
	return cout;
}

template<typename T>
Pair<T>::smaller()
{
	return(GetMin(values[0], values[1]));
}

template<typename T>
class Container
{
	T data;

	template<class T> friend ostream& operator<<(ostream& cout, const Container<T>& p);
public:
	Container(T a)
	{
		data = a;
	}
	Container increase();
};
template<class T>
ostream& operator<<(ostream& cout, const Container<T>& p) {
	cout << p << endl;
	return cout;
}
template<>
class Container <char>
{
	char data;

public:

	Container(char a)
	{
		data = a;
	}
	Container uppercase();
};

template<typename T>
Container<T>::increase()
{
	return (data++);
}
template<typename T>
Container<char>::uppercase()
{
	return (data = data + 32);
}

template <class T, int N>
class Sequence
{
	T memblock[N];

	template<class T,int N> friend ostream& operator<<(ostream& cout, const Sequence<T,N>& p);
public:
	void setmember(int x, T value);
	T getmember(int x);
};
template<class T,int N>
ostream& operator<<(ostream& cout, const Sequence<T,N>& p) {
	cout << p << endl;
	return cout;
}
template<class T, int N>
Sequence<T, N>::setmember(int x, T value)
{
	for (int i = 0; i < N; i++)
	{
		if (memblock[i] = x)
			memblock = value;
	}
}

template<class T, int N>
Sequence<T, N>::getmember(int x)
{
	return(memblock[x]);
}

int main()
{
	/*int i = 5, j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax(i, j);
	n = GetMin(l, m);
	cout << k << endl;
	cout << n << endl;*/

	/*char a = 'Z';
	int j = 6, k;
	long l = 10, m = 5, n;
	k = GetMax<int long>(a, m);
	n = GetMin<int long>(j, l);
	cout << k << endl;
	cout << n << endl;*/

	//Pair<double> myobject(1.012, 1.01234);
	//cout << myobject.greater() << endl;

	/*Container<int> myint(7);
	Container<char> mychar('j');
	cout << myint.increase() << endl;
	cout << mychar.uppercase() << endl;*/

	Sequence<int, 5> myints;
	Sequence<double, 5> myfloats;
	myints.setmember(0, 100);
	myfloats.setmember(3, 3.1416);
	cout << myints.getmember(0) << endl;
	cout << myfloats.getmember(3) << endl;

	Pair<double> y(2.23, 3.45);
	Sequence<Pair<double>, 5> myPairs;
	myPairs.setmember(0, y);
	cout << myPairs.getmember(0) << endl;

	system("pause");
	return 0;
}
