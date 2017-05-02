#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
struct node{
	string bookNum;
	string name;
	string inorOut;
};
class book{
	public: vector<node> bookdata;
	book(void);
	void insertbookfromtxt(string bookfilename);
	int lookupbook();
	void addnewbook();
	void storebookfile();
	void deletealldata(){bookdata.clear();};
	void deletebookbyname(string bookname);
	void deletebookbynum(string booknum);
};


void book::deletebookbyname(string bookname)
{
	vector<node>::iterator entry;
	entry = bookdata.begin();
	while(entry<bookdata.end())
	{
		if(entry->name == bookname)
		{
			entry = bookdata.erase(entry);
			continue;
		}
		entry++;
	}

}


void book::deletebookbynum(string booknum)
{
	vector<node>::iterator entry;
	entry = bookdata.begin();
	while(entry<bookdata.end())
	{
		if(entry->bookNum== booknum)
		{
			entry = bookdata.erase(entry);
			continue;
		}
		entry++;
	}

}

void book::storebookfile()
{
	ofstream out;
	out.open("Info.txt");
	ostringstream temp;
	temp<<"name    num   state";
	out<<temp.str()<<endl;
	vector<node>::iterator entry;
	entry = bookdata.begin();
	for(;entry<bookdata.end();entry++)
	{
		cout<<entry->name<<"   "<<entry->bookNum<<"    "<<entry->inorOut<<endl;
		ostringstream formatted;
		formatted<<entry->name<<"   "<<entry->bookNum<<"    "<<entry->inorOut;
		out<<formatted.str()<<endl;
	}
	out.close();
}


void book::addnewbook()
{
	string bookname,booknum,bookstate;
	cout<<"Pls. type into the book name, num and state"<<endl;
	cin>>bookname>>booknum>>bookstate;
	node tempnode;
	tempnode.bookNum = booknum;
	tempnode.name = bookname;
	tempnode.inorOut = bookstate;
	bookdata.push_back(tempnode);
}
 book::book(){};
 inline void csvformat(string& name)  
 {	
	 std::string::size_type startpos = 0;  
	 while (startpos!= std::string::npos)  
	 {	
		 startpos = name.find(',');   //找到'.'的位置  
		 if( startpos != std::string::npos ) //std::string::npos表示没有找到该字符	
		 {	
		   name.replace(startpos,1," "); //实施替换，注意后面一定要用""引起来，表示字符串  
		 }	
	 }	
 }	

void book::insertbookfromtxt(string bookfilename)
{

	ifstream inFile;
	inFile.open(bookfilename.c_str());
	if(!inFile) 
	{
		cout<<"File open fail"<<endl;
		return;
	}
	string line,word;
	while(getline(inFile,line))
	{
		#if 1
		csvformat(line);
		#endif
		node tempnode;
		istringstream record(line);
		record>>tempnode.name;
		record>>tempnode.bookNum;
		record>>tempnode.inorOut;
		bookdata.push_back(tempnode);
	}
	inFile.close();
}
int book::lookupbook(void)
{
	return 1;	
}
void displaymenu()
{
	cout<<"======================"<<endl;
	cout<<"1: to read the data from txt file"<<endl;
	cout<<"2: to add  the data from txt file"<<endl;
	cout<<"3: to delete the book by name"<<endl;
	cout<<"4: to delete the book by num"<<endl;
	cout<<"5: to logout the book by state"<<endl;
	cout<<"6: to delete all the data"<<endl;
	cout<<"0: to exit"<<endl;
	cout<<"Pls. type into the command"<<endl;}
int main()
{
	book book1;
	string booktxtname;
	char flag;

	
	while(1)
	{
		displaymenu();
		cin>>flag;
		cin.sync();
		cin.clear();
		switch(flag)
		{
			case '0': return 1;
			case '1':
			{
				booktxtname = "2.csv";
				book1.insertbookfromtxt(booktxtname);
				break;
			}
			case '2':
			{
				book1.addnewbook();
				break;
			}
			case '3':
			{
				book1.deletebookbyname("math");
				break;

			}
			case '4':
			{
				book1.deletebookbynum("2");
				break;

			}

			case '5':
			{
				book1.storebookfile();
				break;

			}
			case '6':
			{
				book1.deletealldata();
				break;
			}
			case '7':
			{
				break;

			}
			default:
				break;
		}
	
	}

	system("PAUSE");

	return 1;
}
