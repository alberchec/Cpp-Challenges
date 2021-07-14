#include <iostream>

using namespace std;

class Box{
private:
	int l,b,h;
public:
	Box() : l(0), b(0), h(0) {}
	Box(int l, int b, int h){
		this->l = l;
		this->b = b;
		this->h = h;
	}
	Box(const Box& B){
		l = B.l;
		b = B.b;
		h = B.h;
	}
	int getLength() const{
		return l;
	}
	int getBreadth() const{
		return b;
	}
	int getHeight() const{
		return h;
	}
	long long CalculateVolume() const{
		long long temp = (long)l*b*h;
		return temp;
	}
	bool operator < (const Box& B){
		if(l < B.l)
			return true;
		else if( (b < B.b) && (l == B.l) )
			return true;
		else if( (h < B.h) && (b == B.b) && (l == B.l) )
			return true;
		else
			return false;
	}
	friend ostream& operator << (ostream& out, const Box& B);
};

ostream& operator << (ostream& out, const Box& B){
	out << B.l << ' ' << B.b << ' ' << B.h;
	return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}