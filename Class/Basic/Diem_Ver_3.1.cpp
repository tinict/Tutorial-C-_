#include<bits/stdc++.h>
using namespace std;

class DIEM
{
	private:
		int tung, hoanh;
	public:
		void info();
		void show();
		DIEM sum_D(DIEM);
		double kc_D(DIEM);
};

void DIEM::info()
{
	cout << "Hoanh: ";
	cin >> hoanh;
	cout << "Tung: ";
	cin >> tung;
}

void DIEM::show()
{
	cout << "Hoanh do: " << hoanh << endl;
	cout << "Tung do: " << tung << endl;
}

DIEM DIEM::sum_D(DIEM d1)
{
	DIEM d;
	d.hoanh = hoanh + d1.hoanh;
	d.tung = tung + d1.tung;
	return d;
}

double DIEM::kc_D(DIEM d1)
{
	return sqrt(pow(d1.hoanh - hoanh, 2)+pow(d1.tung - tung, 2));
}

int main()
{
	DIEM d1,d2,d3;
	cout << "Toa do 1" << endl;
	d1.info();
	cout << "Toa do 2" << endl;
	d2.info();
	d3 = d1.sum_D(d2);
	d3.show();
	cout << "Khoang 2 diem: "<< d1.kc_D(d2);
 	return 0;
}

