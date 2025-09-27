#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream filestd("Students.txt",ios::out);
	filestd<<" Name                 Father name         Roll no   "<<endl;
	filestd<<"===================================================="<<endl;
	filestd<<" Hasnain Malik      Muhammad Bilal         2024-SE-37 "<<endl;
	filestd<<" Usman Saleem       M. Saleem        2024-SE-36 "<<endl;
	filestd<<" Abdullah           Saifullah          2024-SE-38 "<<endl;
	filestd.close();
	
	fstream filein("Students.txt" , ios::in);
	string s;
	while(getline(filein,s))
	{
		cout<<s<<endl;
	}
	filein.close();
}
