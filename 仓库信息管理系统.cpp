#include<iostream>
using namespace std;
class Good
{
	public:
		int id;
		int num;
		string name;
		double InPrice;
		double OutPrice;
		Good(){num=0;}
		void SetId(int id_){id=id_;}
		void SetName(string name_){name=name_;}
		void SetInPrice(double InPrice_){InPrice=InPrice_;}
		void SetOutPrice(double OutPrice_) {OutPrice=OutPrice_;}
		void import_(int add_){num+=add_;}
		void export_(int sub_)
		{
			if((num-sub_)<0) cout<<"error!"<<endl;
			else
			{
				num-=sub_;
			}
		}
};
class Inventory
{
	public:
		int num;
		Good g[400];
		void add_(int id_,int num_,string name_,double InPrice_,double OutPrice_)
		{
			int i;
			for(i=0;i<num;i++)
			{
				if(g[i].id==id_)
				{
					g[i].import_(num_);
					break;
				}
			}
			if(i==num){
				g[num].SetId(id_);
				g[num].import_(num_);
				g[num].SetName(name_);
				g[num].SetInPrice(InPrice_);
				g[num].SetOutPrice(OutPrice_);
				num++;
			}
		}
		void out_(int id_,int num_)
		{
			int i;
			for(i=0;i<num;i++)
			{
				if(g[i].id==id_)
				{
					g[i].export_(num_);
					if(g[i].num==0)
					{
						for(int j=i+1;j<num;j++)
						{
							g[j-1]=g[j];
						}
						num--;
					}
					break;
				}
			}
			//if(i==num) cout<<"error!"<<endl;
		}
		void change_(int id_,double InPrice_,double OutPrice_)
		{
			int i;
			for(i=0;i<num;i++)
			{
				if(g[i].id==id_)
				{
					g[i].SetInPrice(InPrice_);
					g[i].SetOutPrice(OutPrice_);
					break;
				}
			}
			if(i==num) cout<<"error!"<<endl;
		}
		void display_all()
		{
			cout<<"货号\t"<<"名称\t"<<"进价\t出价\t数量\t"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<g[i].id<<"\t"<<g[i].name<<"\t"<<g[i].InPrice<<"\t"<<g[i].OutPrice<<"\t"<<g[i].num<<"\t"<<endl;
			}
		}
};
class Info
{
	public:
		int id;
		int num;
		int hours;
		int mins;
		string name;
		void SetId(int id_){id=id_;}
		void SetNum(int num_){num=num_;}
		void SetHours(int hours_){hours=hours_;}
		void SetMins(int mins_){mins=mins_;}
		void SetName(string name_){
			name=name_;
		}
};
class WorkerInfo
{
	public:
		int num;
		Info a[100];
		WorkerInfo(){
			num=3;
			a[0].SetId(1111);
			a[0].SetName("张三"); 
			a[1].SetId(2222);
			a[1].SetName("李四");
			a[2].SetId(3333);
			a[2].SetName("王五");
		}
		void add_(int id_,string name_)
		{
			a[num].id=id_;
			a[num].name=name_;
			num++;
		}
		void delete_(int n)
		{
			if(num<=0) cout<<"error!"<<endl;
			else
			{
				for(int j=n+1;j<num;j++)
				{
					a[j-1]=a[j];
				}
				num--;
			}
		}
		void display_all()
		{
			cout<<"序号\t"<<"工号\t"<<"姓名\t"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<i<<"\t"<<a[i].id<<"\t"<<a[i].name<<"\t"<<endl; 
			}
		}
};
class ImportInfo
{
	public:
		int num;
		Info a[400];
		ImportInfo(){
			num=0;
		}
		void add_(int id_,int num_,int hours_,int mins_)
		{
			a[num].id=id_;
			a[num].num=num_;
			a[num].hours=hours_;
			a[num].mins=mins_;
			num++;
		}
		void delete_(int n)
		{
			if(num<=0) cout<<"error!"<<endl;
			else
			{
				for(int j=n+1;j<num;j++)
				{
					a[j-1]=a[j];
				}
				num--;
			}
		}
		void change_(int n,int num_,int hours_,int mins_)
		{
			a[n].SetNum(num_);
			a[n].SetHours(hours_);
			a[n].SetMins(mins_);
		}
		void display_all()
		{
			cout<<"序号\t"<<"货号\t"<<"数量\t"<<"入库时间\t"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<i<<"\t"<<a[i].id<<"\t"<<a[i].num<<"\t"<<a[i].hours<<":"<<a[i].mins<<endl; 
			}
		}
};
class ExportInfo
{
	public:
		int num;
		Info a[400];
		ExportInfo(){
			num=0;
		}
		void add_(int id_,int num_,int hours_,int mins_)
		{
			a[num].id=id_;
			a[num].num=num_;
			a[num].hours=hours_;
			a[num].mins=mins_;
			num++;
		}
		void delete_(int n)
		{
			if(num<=0) cout<<"error!"<<endl;
			else
			{
				for(int j=n+1;j<num;j++)
				{
					a[j-1]=a[j];
				}
				num--;
			}
		}
		void change_(int n,int num_,int hours_,int mins_)
		{
			a[n].SetNum(num_);
			a[n].SetHours(hours_);
			a[n].SetMins(mins_);
		}
		void display_all()
		{
			cout<<"序号\t"<<"货号\t"<<"数量\t"<<"出库时间\t"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<i<<"\t"<<a[i].id<<"\t"<<a[i].num<<"\t"<<a[i].hours<<":"<<a[i].mins<<endl; 
			}
		}
};
void display_mainmenu()
{
	cout<<"------------------菜单-----------------"<<endl;
	cout<<"(1)物资/库存信息管理"<<endl;
	cout<<"(2)入库信息管理"<<endl;
	cout<<"(3)出库信息管理"<<endl;
	cout<<"(4)工人信息管理"<<endl; 
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";
}
void display_secmenu1()//二级目录 
{
	cout<<"------------------物资/库存管理菜单-----------------"<<endl;
	cout<<"(1)显示所有项"<<endl;
	cout<<"(2)进库"<<endl;
	cout<<"(3)出库"<<endl;
	cout<<"(4)修改进出价"<<endl;
	cout<<"(5)查找货物"<<endl; 
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";
}
void display_secmenu2()//二级目录 
{
	cout<<"------------------入库管理菜单-----------------"<<endl;
	cout<<"(1)显示所有项"<<endl;
	cout<<"(2)删除条目"<<endl;
	cout<<"(3)修改条目"<<endl;
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";	
} 
void display_secmenu3()//二级目录 
{
	cout<<"------------------出库管理菜单-----------------"<<endl;
	cout<<"(1)显示所有项"<<endl;
	cout<<"(2)删除条目"<<endl;
	cout<<"(3)修改条目"<<endl;
	cout<<"(0)退出"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";	
} 
void display_secmenu4()//二级目录 
{
	cout<<"------------------工人管理菜单-----------------"<<endl;
	cout<<"(1)显示所有项"<<endl;
	cout<<"(2)添加工人"<<endl;
	cout<<"(3)删除工人"<<endl;
	cout<<"(0)退出"<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";	
} 
int main()
{
	Inventory a;
	ImportInfo b;
	ExportInfo c;
	WorkerInfo d;
	int tag;
	bool f=1;
	while(f)
	{
		display_mainmenu();
		cin>>tag;
		cout<<endl;
		switch(tag)
		{
			case 1:{
				display_secmenu1();
				cin>>tag;
				cout<<endl;
				switch(tag)
				{
					case 1:{
						a.display_all();
						break;
					}
					case 2:{
						int id_,num_,hours_,mins_;
						string name_;
						double InPrice_,OutPrice_;
						cout<<"请输入货号：";
						cin>>id_;
						cout<<"请输入名称：";
						cin>>name_;
						cout<<"请输入进货量：";
						cin>>num_;
						cout<<"请输入进价：";
						cin>>InPrice_;
						cout<<"请输入售价：";
						cin>>OutPrice_;
						cout<<"请输入进货时间（格式为 时钟+空格+分钟）：" ;
						cin>>hours_>>mins_; 
						a.add_(id_,num_,name_,InPrice_,OutPrice_);
						b.add_(id_,num_,hours_,mins_);
						break;
					}
					case 3:{
						int id_,num_,hours_,mins_;
						cout<<"请输入货号：";
						cin>>id_;
						cout<<"请输入出货量：";
						cin>>num_;
						cout<<"请输入出货时间（格式为 时钟+空格+分钟）：" ;
						cin>>hours_>>mins_;
						a.out_(id_,num_);
						c.add_(id_,num_,hours_,mins_);
						break;
					}
					case 4:{
						int id_;
						double InPrice_,OutPrice_;
						cout<<"请输入货号：";
						cin>>id_;
						cout<<"请输入进价：";
						cin>>InPrice_;
						cout<<"请输入售价：";
						cin>>OutPrice_;
						a.change_(id_,InPrice_,OutPrice_);
						break;
					}
					case 5:{
						int id_;
						cout<<"请输入要查找的货号：";
						cin>>id_;
						int i;
						for(i=0;i<a.num;i++)
						{
							if(a.g[i].id==id_)
							{
								cout<<"货号\t"<<"名称\t"<<"进价\t出价\t数量\t"<<endl;
								cout<<a.g[i].id<<"\t"<<a.g[i].name<<"\t"<<a.g[i].InPrice<<"\t"<<a.g[i].OutPrice<<"\t"<<a.g[i].num<<"\t"<<endl;
								break;
							}
						}
						if(i==a.num) cout<<"未查询到！"<<endl; 
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"error!"<<endl;
						break;
					}
				}
				break;
			}
			case 2:{
				display_secmenu2();
				cin>>tag;
				cout<<endl;
				switch(tag)
				{
					case 1:{
						b.display_all();
						break;
					}
					case 2:{
						int n;
						b.display_all();
						cout<<"请输入要删除的条目序号：";
						cin>>n;
						b.delete_(n);
						break;
					}
					case 3:{
						int n;
						int num_,hours_,mins_;
						b.display_all();
						cout<<"请输入要修改的条目序号：";
						cin>>n;
						cout<<"请输入修改后的数量：";
						cin>>num_;
						cout<<"请输入修改后的时间(格式为 时钟+空格+分钟)：";
						cin>>hours_>>mins_;
						b.change_(n,num_,hours_,mins_); 
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"error!"<<endl;
						break;
					}
				}
				break;
			}
			case 3:{
				display_secmenu3();
				cin>>tag;
				cout<<endl;
				switch(tag)
				{
					case 1:{
						c.display_all();
						break;
					}
					case 2:{
						int n;
						c.display_all();
						cout<<"请输入要删除的条目序号：";
						cin>>n;
						c.delete_(n);
						break;
					}
					case 3:{
						int n;
						int num_,hours_,mins_;
						c.display_all();
						cout<<"请输入要修改的条目序号：";
						cin>>n;
						cout<<"请输入修改后的数量：";
						cin>>num_;
						cout<<"请输入修改后的时间(格式为 时钟+空格+分钟)：";
						cin>>hours_>>mins_;
						c.change_(n,num_,hours_,mins_); 
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"error!"<<endl;
						break;
					}
				}
				break;
			}
			case 4:{
				display_secmenu4();
				cin>>tag;
				cout<<endl;
				switch(tag)
				{
					case 1:{
						d.display_all();
						break;
					}
					case 2:{
						int id_;
						string name_; 
						cout<<"请输入工号：";
						cin>>id_;
						cout<<"请输入姓名：";
						cin>>name_;
						d.add_(id_,name_);
						break;
					}
					case 3:{
						d.display_all();
						int n;
						cout<<"请输入要删除的序号：";
						cin>>n;
						d.delete_(n); 
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"error!"<<endl;
						break;
					}
				}
				break;
			}
			case 0:{
				f=0;
				break;
			}
			default:{
				cout<<"error!"<<endl; 
				break;
			}
		}
	}
	return 0;
}
