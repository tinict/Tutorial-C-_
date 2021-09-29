#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>

using namespace std;

class Date
{
	private:
		int d, m, y;
	public:
		void input_Date();
		void show();
		bool check_leapyear(int);
		bool check_DMY();
		void up_D(int k);
		int re_Date(int,int);
		int d_D(Date);
};

bool Date::check_leapyear(int k)
{
	if(k % 4 == 0 && k  % 100 != 0 || k % 400 == 0)
		return true;
	return false;
}

bool Date::check_DMY()
{
	if(check_leapyear(y) == 1)
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if(d <= 31) return 1;
			else return 0;
		}
		else if(m == 4 || m == 6 || m == 9 || m == 11)
		{
			if(d <= 30) return 1;
			else return 0;
		}
		if(m == 2)
		{
			if(d <= 28) return 1;
			else return 0;
		}
		else return 0;
	}
	else if(check_leapyear(y) == 0)
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if(d <= 31) return 1;
			else return 0;
		}
		if(m == 4 || m == 6 || m == 9 || m == 11)
		{
			if(d <= 30) return 1;
			else return 0;
		}
		if(m == 2)
		{
			if(d <= 28) return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void Date::input_Date()
{
	cout << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	while(check_DMY() == 0)
	{
		cout << "Nhap sai ! Moi nhap lai" << endl;
		cout << "Day: ";
		cin >> d;
		cout << "Month: ";
		cin >> m;
		cout << "Year: ";
		cin >> y;
	}
}

int Date::re_Date(int a, int b)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
	else if(m == 2)
	{
		if(check_leapyear(b) == 1) return 29;
		else return 28;
	}
}

void Date::show()
{
	cout << d << "/" << m << "/" << y << endl;
}

void  Date::up_D(int k)
{
	while(1)
	{
		if(re_Date(m,y) - d >= k)
		{
			d += k;
			k = 0;
			if(d > re_Date(m,y))
			{
				m++;
				if(m > 12)
				{
					y++;
					m = m - 12;
				}
				d = d - re_Date(m,y);
			}
		}
		else if(re_Date(m,y) - d < k)
		{
			int t = re_Date(m,y) - d + 1;
			d += t;
			k -= t;
			d = d - re_Date(m,y);
			m++;
			if(m > 12)
			{
				y++;
				m = m - 12;
			}
		}
		if(k == 0)
			break;
	}
	show();
}

int Date::d_D(Date a)
{
	int t = 0;
	int f1 = re_Date(m,y) - d;
	int f2 = a.re_Date(a.m,a.y) - a.d;
	int k = a.y - y + 1;
	Date b;
	for(int i = y; i <= a.y; i++)
	{
		if(k != 1)
		{
			if(i == y)
			{
				for(int j = m ; j <= 12; j++)
				{
					b.m = j;
					t += b.re_Date(j,y);
				}
			}
			else if(i == a.y)
			{
				for(int q = 1; q <= a.m ; q++)
				{
					b.m = q;
					t += b.re_Date(q,a.y);
				}
			}
			
			else
			{
				for(int p = 1; p <= 12; p++)
				{
					b.m = p;
					t += b.re_Date(p,i);
				}
			}
		}
		else
		{
			for(int r = m ; r <= a.m; r++)
			{
				b.m = r;
				t += b.re_Date(r,y);
			}
		}
	}
	return t - re_Date(m,y) + f1 - f2;
}

int main()
{
	Date a,b;
	a.input_Date();
	b.input_Date();
	a.up_D(a.d_D(b));
	return 0;
}

