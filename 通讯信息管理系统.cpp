#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;
void caidan();						//菜单函数，实现菜单的显示
static int n=0;    					//记录输入的数据的个数
#define limit 10  					//通讯信息条数只能是最多为limit条。 
class Information
{
public:
	struct xinxi
	{
		int id;          			//编号顺序
		char name[20];
		char num[11];
		char type;
		char mail[20];
	}xx;
	void zengInformation(); 		//增加信息；

	int cc(char na[]);         		//看输入的名字是不是重复；
};
void Information::zengInformation()
{
	cin>>xx.name>>xx.num>>xx.type>>xx.mail;
}
int Information::cc(char na[])
{
	if(strcmp(na,xx.name)==0)
		return 1;
	else return 0;
}
Information B[10];
class PP:public Information    			//对信息进行排序，并且写进文件，打开文件；
{
public:	
	void searchInformation1(char nu[]); //根据电话号码查找联系人；
	void searchInformation2(char na[]); //根据姓名查找联系人；
	void xiuInformation(char na[]);		//修改功能；
	void baocun();      				//实现保存功能；
	void inputfile();  					//增加的信息写入文件
	void outfile();	    				//打开文件，显示信息
	void display();     				//浏览功能，显示信息；
	void shanInformation();   			//删除功能；
};
void PP::searchInformation1(char nu[])
{
	int i;
	if(n==0)
	{
		cout<<"查无此人"<<endl;
	}else
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(nu,B[i].xx.num)==0)
			{	cout<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
				break;
			}
			else if(strcmp(nu,B[i].xx.num)!=0 && i==n-1)
			{
				cout<<"查无此人"<<endl;	
				break;		
			}
		
		}
		
		

	}

}
void PP::searchInformation2(char na[])
{
	int i;
	if(n==0)
	{
		cout<<"查无此人"<<endl;
	}else
	{
		for(i=0;i<n;i++)
		{
			if(strcmp(na,B[i].xx.name)==0)
			{	cout<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
				break;
			}
			else if(strcmp(na,B[i].xx.name)!=0 && i==n-1)
			{
				cout<<"查无此人"<<endl;	
				break;		
			}
		
		}
		
		

	}
		
}
void PP::xiuInformation(char na[])
{
	if(n==0)
	{
		cout<<"查无此人"<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(strcmp(na,B[i].xx.name)==0)
			{
				int a;
				cout<<"输入你要修改哪一项（1.姓名 2.电话号码 3.类型 4.电子邮件）"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:cout<<"你要将其修改为:"<<endl;
					cin>>B[i].xx.name;break;
				case 2:cout<<"你要将其修改为:"<<endl;
					cin>>B[i].xx.num;break;
				case 3:cout<<"你要将其修改为:"<<endl;
					cin>>B[i].xx.type;break;
				case 4:cout<<"你要将其修改为:"<<endl;
					cin>>B[i].xx.mail;break;
				}
				break;
			}
			if((i==n-1 && strcmp(na,B[i].xx.name)!=0))
				cout<<"查无此人"<<endl;
		} 
		fstream f1("Information.dat");
		ofstream f2("tmp.dat");  

		
		for(int i2=0;i2<n;i2++)
		{
			f2<<B[i2].xx.id<<" "<<B[i2].xx.name<<" "<<B[i2].xx.num<<" "<<B[i2].xx.type<<" "<<B[i2].xx.mail<<endl;
		}
		f1.close();
		f2.close();
		remove("Information.dat");
		rename("tmp.dat","Information.dat");
	}
	

}

void PP::baocun()
{

	ofstream f2("save_Information.dat"); 
	f2.close();
	remove("save_Information.dat"); 
	ofstream f3("save_Information.dat"); 

		
		for(int i=0;i<n;i++)
		{
			f3<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
		}
		f3.close();
}
void PP::inputfile()
{
	ofstream outfile("Information.dat");  
  
	if(!outfile){  
	    cout << "Unable to open otfile";  
	        exit(1); // terminate with error  
	  
	}  

		cout<<"输入联系人信息：姓名、电话号码、类型（A.同事 B.朋友 C.家庭）、电子邮件"<<endl;
		for(int i=n;;i++)
		{
			if(i==limit)
			{
				cout<<"存储空间已满，可选择删除数据再进行输入"<<endl;
				break;
			}
			B[i].zengInformation();
			for(int j=0;j<n;j++)
			{
				if(B[i].cc(B[j].xx.name))
				{
					cout<<"数据录入重复"<<endl;
					i=i-1;
					break;
				}
			}
			
			n++;
	
			B[i].xx.id=n;
			outfile<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
			char q;
			cout<<"选择是否继续输入（y/n）"<<endl;
			cin>>q;
			if(q=='n')
				break;
			if(q=='y')
				continue;
		
		}
	outfile.close();
}
void PP::outfile()
{
	fstream Myfile("Information.dat");
	if(!Myfile)    //判断是否成功打开文件
	{
		cerr<<"open error!"<<endl;
		abort();
	}
	string temp;
	while(getline(Myfile,temp))
   {
   		cout<<temp<<endl;
   }
   Myfile.close(); 
	
}
void PP::display()
{
	cout<<"联系人信息如下:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
	} 
}
void PP::shanInformation()
{
	char na[20];
	cout<<"输入你要删除的人的名字"<<endl;
	cin>>na;
	int j;
	for(int i=0;i<n;i++)
	{
		if(strcmp(na,B[i].xx.name)==0)
		{
			j=i;
			break;
		}
	}
	
	for(int i1=j;i1<n-1;i1++)
	{
		B[i1]=B[i1+1];
		B[i1].xx.id=i1;
	}
	n--;
	fstream Myfile("Information.dat");
	ofstream f2("tmp2.dat");  
	
			
	for(int i3=0;i3<n;i3++)
			{
				f2<<B[i3].xx.id<<" "<<B[i3].xx.name<<" "<<B[i3].xx.num<<" "<<B[i3].xx.type<<" "<<B[i3].xx.mail<<endl;
			}
			Myfile.close();
			f2.close();
			remove("Information.dat");
			rename("tmp2.dat","Information.dat");
}
void caidan(PP p)
{
	cout<<"****菜单****"<<endl;
	cout<<"1.增加功能"<<endl;
	cout<<"2.浏览功能"<<endl;
	cout<<"3.查询功能"<<endl;
	cout<<"4.修改功能"<<endl;
	cout<<"5.删除功能"<<endl;
	cout<<"6.保存功能"<<endl;
	cout<<"7.读取功能"<<endl;
	int q;
	cout<<"输入你要选择的功能:"<<endl;
	cin>>q;
	switch(q)
	{
	case 1:
		p.inputfile();
		break;
	case 2:p.display();break;
	case 3:{cout<<"输入你要按号码（h）查找还是按姓名（m）查找:"<<endl;
		char z;
		cin>>z;
		if(z=='h')
		{
			char h[11];
			cout<<"输入你要查找的号码:"<<endl;
			cin>>h;
			p.searchInformation1(h);
		}
		if(z=='m')
		{
			char m[20];
			cout<<"输入你要查找的姓名:"<<endl;
			cin>>m;
			p.searchInformation2(m);
		}
		break;}
	case 4:{
		char m[20];
		cout<<"输入你要修改的联系人的姓名:"<<endl;
		cin>>m;
		p.xiuInformation(m);break;
		   }
	case 5:p.shanInformation();break;
	case 6:p.baocun();break;
	case 7:p.outfile();break;
	}
}
int  main()
{
	PP P;
	char Q;
	cout<<"********欢迎使用本系统********"<<endl;
	fstream f1("Information.dat");
	f1.clear();
	f1.close();
	for(int i=0;;i++)
	{
		caidan(P);
		cout<<"请问是否(y/n)要继续使用菜单选择功能?"<<endl;
		cin>>Q;
		if(Q=='y')
			continue;
		if(Q=='n')
			break;
	}
	
	return 0;
}
