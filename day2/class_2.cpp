// classes example                           area: 12
#include <iostream>
using namespace std;
class CRectangle {
	int x,y;
	public:
	int area ()
	{
		return (x*y);
	};
	CRectangle(){
		cout << "Enter the length :";
		cin >> x;
		cout << "Enter the width :";
		cin >> y;
	};

};
int main ()
{
	CRectangle rect;
	cout << "area: " << rect.area() << endl;
	return 0;
}
