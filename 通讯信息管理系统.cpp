#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;
void caidan();						//�˵�������ʵ�ֲ˵�����ʾ
static int n=0;    					//��¼��������ݵĸ���
#define limit 10  					//ͨѶ��Ϣ����ֻ�������Ϊlimit���� 
class Information
{
public:
	struct xinxi
	{
		int id;          			//���˳��
		char name[20];
		char num[11];
		char type;
		char mail[20];
	}xx;
	void zengInformation(); 		//������Ϣ��

	int cc(char na[]);         		//������������ǲ����ظ���
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
class PP:public Information    			//����Ϣ�������򣬲���д���ļ������ļ���
{
public:	
	void searchInformation1(char nu[]); //���ݵ绰���������ϵ�ˣ�
	void searchInformation2(char na[]); //��������������ϵ�ˣ�
	void xiuInformation(char na[]);		//�޸Ĺ��ܣ�
	void baocun();      				//ʵ�ֱ��湦�ܣ�
	void inputfile();  					//���ӵ���Ϣд���ļ�
	void outfile();	    				//���ļ�����ʾ��Ϣ
	void display();     				//������ܣ���ʾ��Ϣ��
	void shanInformation();   			//ɾ�����ܣ�
};
void PP::searchInformation1(char nu[])
{
	int i;
	if(n==0)
	{
		cout<<"���޴���"<<endl;
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
				cout<<"���޴���"<<endl;	
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
		cout<<"���޴���"<<endl;
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
				cout<<"���޴���"<<endl;	
				break;		
			}
		
		}
		
		

	}
		
}
void PP::xiuInformation(char na[])
{
	if(n==0)
	{
		cout<<"���޴���"<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(strcmp(na,B[i].xx.name)==0)
			{
				int a;
				cout<<"������Ҫ�޸���һ�1.���� 2.�绰���� 3.���� 4.�����ʼ���"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:cout<<"��Ҫ�����޸�Ϊ:"<<endl;
					cin>>B[i].xx.name;break;
				case 2:cout<<"��Ҫ�����޸�Ϊ:"<<endl;
					cin>>B[i].xx.num;break;
				case 3:cout<<"��Ҫ�����޸�Ϊ:"<<endl;
					cin>>B[i].xx.type;break;
				case 4:cout<<"��Ҫ�����޸�Ϊ:"<<endl;
					cin>>B[i].xx.mail;break;
				}
				break;
			}
			if((i==n-1 && strcmp(na,B[i].xx.name)!=0))
				cout<<"���޴���"<<endl;
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

		cout<<"������ϵ����Ϣ���������绰���롢���ͣ�A.ͬ�� B.���� C.��ͥ���������ʼ�"<<endl;
		for(int i=n;;i++)
		{
			if(i==limit)
			{
				cout<<"�洢�ռ���������ѡ��ɾ�������ٽ�������"<<endl;
				break;
			}
			B[i].zengInformation();
			for(int j=0;j<n;j++)
			{
				if(B[i].cc(B[j].xx.name))
				{
					cout<<"����¼���ظ�"<<endl;
					i=i-1;
					break;
				}
			}
			
			n++;
	
			B[i].xx.id=n;
			outfile<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
			char q;
			cout<<"ѡ���Ƿ�������루y/n��"<<endl;
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
	if(!Myfile)    //�ж��Ƿ�ɹ����ļ�
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
	cout<<"��ϵ����Ϣ����:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<B[i].xx.id<<" "<<B[i].xx.name<<" "<<B[i].xx.num<<" "<<B[i].xx.type<<" "<<B[i].xx.mail<<endl;
	} 
}
void PP::shanInformation()
{
	char na[20];
	cout<<"������Ҫɾ�����˵�����"<<endl;
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
	cout<<"****�˵�****"<<endl;
	cout<<"1.���ӹ���"<<endl;
	cout<<"2.�������"<<endl;
	cout<<"3.��ѯ����"<<endl;
	cout<<"4.�޸Ĺ���"<<endl;
	cout<<"5.ɾ������"<<endl;
	cout<<"6.���湦��"<<endl;
	cout<<"7.��ȡ����"<<endl;
	int q;
	cout<<"������Ҫѡ��Ĺ���:"<<endl;
	cin>>q;
	switch(q)
	{
	case 1:
		p.inputfile();
		break;
	case 2:p.display();break;
	case 3:{cout<<"������Ҫ�����루h�����һ��ǰ�������m������:"<<endl;
		char z;
		cin>>z;
		if(z=='h')
		{
			char h[11];
			cout<<"������Ҫ���ҵĺ���:"<<endl;
			cin>>h;
			p.searchInformation1(h);
		}
		if(z=='m')
		{
			char m[20];
			cout<<"������Ҫ���ҵ�����:"<<endl;
			cin>>m;
			p.searchInformation2(m);
		}
		break;}
	case 4:{
		char m[20];
		cout<<"������Ҫ�޸ĵ���ϵ�˵�����:"<<endl;
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
	cout<<"********��ӭʹ�ñ�ϵͳ********"<<endl;
	fstream f1("Information.dat");
	f1.clear();
	f1.close();
	for(int i=0;;i++)
	{
		caidan(P);
		cout<<"�����Ƿ�(y/n)Ҫ����ʹ�ò˵�ѡ����?"<<endl;
		cin>>Q;
		if(Q=='y')
			continue;
		if(Q=='n')
			break;
	}
	
	return 0;
}
