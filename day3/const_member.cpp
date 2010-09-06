#include <iostream>
using namespace std;
class classroom{
	const int Numofstudents;
	char name[50][50];
	public:
	classroom(const int a):Numofstudents(a){}
	/*
	 * constant member is initialized member initialization list in constructor
	 */
	void nameofstudent(int i);
	void nameofstudentconst(int i)const;
	int Noofstudent()
	{
		return Numofstudents;
	}
	int Noofstudentconst()const
	{
		return Numofstudents;
	}
	/*
	 * constant objects ony handled by constant functions
	 */
};

int main()
{
	const classroom a(5);
	/* 
	 * only constant function can operate on constant object
	 */
	classroom b(6);
#if 0 
	cout << a.Noofstudent()<<endl;
#endif
	cout << b.Noofstudentconst()<<endl;
	cout << a.Noofstudentconst()<<endl;
	cout << b.Noofstudent()<<endl;
	return 0;
}
