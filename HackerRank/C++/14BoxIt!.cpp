#include<bits/stdc++.h>

using namespace std;

class Box{
    
        private: 
            int l,b,h;
        public:
        
        Box(){
            l = 0;
            b = 0;
            h = 0;
        }
        
        Box(int a,int b,int c){
            l = a; 
            this->b = b;
            h = c;    
        };
        
        Box(Box &other){
            l = other.l;
            b = other.b;
            h = other.h;
        };
        
        int getLength(){return l;}
        int getBreadth() {return b;}
        int getHeight(){return h;}
        long long CalculateVolume(){
            return (long long)l*b*h; //this should REALLY automatically get typecasted.
        }
        
        bool operator< (const Box& other){
            bool lessThan = true;
            if(l < other.l) {return true;}
            if(b < other.b && l == other.l) {return true;}
            if(h < other.h && b == other.b && l == other.l){return true;}
            return false;
        }
        
        friend ostream& operator<< (ostream& os, const Box& other){
            os << other.l << " " << other.b << " " << other.h;
            return os;
        }
} ;


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