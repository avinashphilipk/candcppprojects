#include <iostream>
using namespace std;
class a{
public:
	int x,y;
	a(){ };
	a(int,int);
	a operator + (a);
};
a::a(int a,int b)
{
	x	= a;
	y	= b;
}
a a::operator+ (a param)
{
	a b;
	b.x = x + param.x;
	b.y = y + param.y;
	return (b);
}
int main()
{
	a x(2,3);
	a y(1,2);
	a z;
	z = x+y;
	cout << z.x<<"," << z.y <<endl;
	return 0;
}	

