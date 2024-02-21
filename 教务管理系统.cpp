#include<iostream>
#include<fstream>
#define Max 6
using namespace std;
string sta[15]={"离散","线代","模电","数据结构","汇编","数电"};
struct Prize_punish
{
	string name;
	char nature;
};
class Pp_group
{
	public:
		int num;
		Prize_punish sin[20];
		Pp_group(){num=0;}
		void add_(string name_,char nature_)
		{
			sin[num].name=name_;
			sin[num].nature=nature_;
			num++;
		}
		void delete_(int n)
		{
			for(int i=n+1;i<num;i++)
			{
				sin[i-1]=sin[i];
			}
			num--;
		}
		void change_(int n,string name_,char nature_)
		{
			sin[n].name=name_;
			sin[n].nature=nature_;
		}
		void display_one(string name_)
		{
			int i;
			for(i=0;i<num;i++)
			{
				if(sin[i].name==name_)
				{
					cout<<sin[i].name<<" ";
					if(sin[i].nature=='T') cout<<"奖"<<endl;
					else cout<<"惩"<<endl; 
					break;
				}
			}
			if(i==num) cout<<"查询失败！"<<endl;
		}
		void display_all()
		{
			if(num==0) cout<<"无奖惩"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<sin[i].name<<" ";
				if(sin[i].nature=='T') cout<<"奖"<<endl;
				else cout<<"惩"<<endl;
			}
		}
};
struct Courses_selected
{
	int id;
	double mark;
};
class Courses_selected_group
{
	public:
		int num;
		Courses_selected sin[10];
		Courses_selected_group(){num=0;}
		void add_(int id_)
		{
			sin[num].id=id_;
			sin[num].mark=-1;
			num++;
		}
		void delete_(int n)
		{
			for(int j=n+1;j<num;j++)
			{
				sin[j-1]=sin[j];
			}
			num--;
		}
		void delete_1(int id_)
		{
			for(int i=0;i<num;i++)
			{
				if(sin[i].id==id_)
				{
					for(int j=i+1;j<num;j++)
					{
						sin[j-1]=sin[j];
					}
					break;
				}
			}
			num--;
		}
		void change_mark(int n,double mark_)
		{
			sin[n].mark=mark_;
		}
		void display_all()
		{
			if(num==0) cout<<"无课程"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<i+1<<"\t"<<sta[sin[i].id]<<" "<<sin[i].mark<<endl;
			}
		}
};
class Student
{
	public:
		int id;
		string name;
		char sex;
		Pp_group t;
		Courses_selected_group c;
		friend class Courses_group;
		friend class Student_group;
		void change_base(int id_,string name_,char sex_)
		{
			id=id_;
			name=name_;
			sex=sex_;
		}
		void display_all()
		{
			cout<<id<<" "<<name<<"\t"<<sex<<endl;
			c.display_all();
			t.display_all();
		}
		void display_base()
		{
			cout<<id<<" "<<name<<"\t"<<sex<<endl;
		}
};
class Student_group
{
	public:
		int num;
		Student stu[400];
		Student_group(){num=0;}
		void add_(int id_,string name_,char sex_)
		{
			stu[num].change_base(id_,name_,sex_);
			num++;
		}
		void delete_(int n)
		{
			for(int i=n+1;i<num;i++)
			{
				stu[i-1]=stu[i];
			}
			num--;
		}
		void display_all()
		{
			for(int i=0;i<num;i++)
			{
				cout<<i+1<<"\t";
				stu[i].display_base();
				cout<<endl;
			}
		}
		void display_one(int id_)
		{
			int i;
			for(i=0;i<num;i++)
			{
				if(stu[i].id==id_)
				{
					stu[i].display_all();
					break;
				}
			}
			if(i==num) cout<<"查询失败！"<<endl;
		}
};

Student_group a;

struct Teacher
{
	int id;
	string name;
	double mark;	
};
class Courses
{
	public:
		int id;
		int tea_num;
		Teacher t[5];
		int stu_num;
		int stu_list[100];
		Courses(){
			tea_num=0;
			stu_num=0;
		}
		void add_tea(int id_,string name_)
		{
			if(tea_num<5)
			{
				t[tea_num].id=id_;
				t[tea_num].name=name_;
				tea_num++;
			}
			else
			cout<<"error!"<<endl;
		}
		void delete_tea(int n)
		{
			for(int j=n+1;j<tea_num;j++)
			{
				t[j-1]=t[j];
			}
			tea_num--;
		}
		void display_tea()
		{
			for(int i=0;i<tea_num;i++)
			{
				cout<<t[i].id<<" "<<t[i].name<<endl;
			}
		}
		void add_stu(int id_)//课程端加学生，学生端也应该加课程 
		{
			stu_list[stu_num]=id_;
			stu_num++;
		}
		void delete_stu(int n)
		{
			for(int j=n+1;j<stu_num;j++)
			{
				stu_list[j-1]=stu_list[j];
			}
			stu_num--;
		}
		void display_stu_one(int id_)//显示学生 
		{
			int i;
			for(i=0;i<stu_num;i++)
			{
				if(stu_list[i]==id_)
				{
					for(int j=0;j<a.num;j++)
					{
						if(a.stu[j].id==id_)
						cout<<id_<<" "<<a.stu[j].name<<" "<<a.stu[j].sex<<endl;
						break;
					}
					break;
				}
			}
			if(i==stu_num) cout<<"查询失败！"<<endl;
		}
		void display_stu_all()
		{
			for(int i=0;i<stu_num;i++)
			{
				cout<<i+1<<"\t";
				for(int j=0;j<a.num;j++)
				{
					if(stu_list[i]==a.stu[j].id)
					{
						cout<<a.stu[j].id<<" "<<a.stu[j].name<<" "<<a.stu[j].sex<<endl;
						break;
					}
				}
				cout<<endl;
			}
		}
		
};
class Courses_group
{
	public:
		int num;
		Courses_group()
		{
			num=0;
		}
		Courses c[6];
		void add_(int id_)
		{
			c[num].id=id_;
			num++;
		}
		void delete_(int n)
		{
			for(int j=n+1;j<num;j++)
			{
				c[j-1]=c[j];
			}
			num--;
		}
		void display_all()
		{
			for(int i=0;i<num;i++)
			{
				cout<<i+1<<"\t"<<sta[c[i].id]<<endl;
			}
		}
};
void display_mainmenu()
{
	cout<<"------------------菜单-----------------"<<endl;
	cout<<"(1)学生信息管理"<<endl;
	cout<<"(2)课程信息管理"<<endl;
	cout<<"(3)教师评分系统"<<endl; 
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择："; 
}
void display_secmenu1()//学生的二级目录 
{
	cout<<"------------------学生菜单-----------------"<<endl;
	cout<<"(1)显示所有学生"<<endl;
	cout<<"(2)添加学生"<<endl;
	cout<<"(3)删除学生"<<endl;
	cout<<"(4)查询学生全部信息"<<endl;
	cout<<"(5)修改基本信息"<<endl;
	cout<<"(6)添加奖惩信息"<<endl;
	cout<<"(7)删除奖惩信息"<<endl;
	cout<<"(8)修改奖惩信息"<<endl; 
	cout<<"(9)课程成绩录入或修改"<<endl;
	cout<<"(10)课程成绩查询"<<endl; 
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";
}
void display_secmenu2()//课程的二级目录 
{
	cout<<"------------------课程菜单-----------------"<<endl;
	cout<<"(1)显示所有课程"<<endl;
	cout<<"(2)添加课程"<<endl;
	cout<<"(3)删除课程"<<endl;
	cout<<"(4)显示所有任课老师"<<endl;
	cout<<"(5)添加任课老师"<<endl;
	cout<<"(6)删除任课老师"<<endl;
	cout<<"(7)显示所有选某课的学生(选课系统)"<<endl;//课程选择学生，学生端自动添加该课程 
	cout<<"(8)添加选某课的学生(选课系统)"<<endl;
	cout<<"(9)删除选某课的学生(选课系统)"<<endl;
	cout<<"(10)查询某一个选此课的学生"<<endl; 
	cout<<"(0)退出"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"请输入序号并按回车以选择：";	
}
int main()
{
	Courses_group b;
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
						int id_;
						string name_;
						char sex_;
						cout<<"请输入学号：";
						cin>>id_;
						cout<<"请输入姓名：";
						cin>>name_;
						cout<<"请输入性别(男性->M，女性->F)：";
						cin>>sex_;
						a.add_(id_,name_,sex_);
						break;
					}
					case 3:{
						if(a.num<=0) cout<<"不可进行删除操作！"<<endl;
						else
						{
							a.display_all();
							int n;
							cout<<"请输入要删除的学生序号(第一列)：";
							cin>>n;
							a.delete_(n-1);
						}
						break;
					}
					case 4:{
						int id_;
						cout<<"请输入所查询学生学号：";
						cin>>id_;
						a.display_one(id_); 
						break;
					}
					case 5:{
						int id_;
						string name_;
						char sex_;
						if(a.num<=0) cout<<"无学生"<<endl;
						else
						{
							a.display_all();
							int n;
							cout<<"请输入要修改的学生序号(第一列)：";
							cin>>n;
							cout<<"请输入学号：";
							cin>>id_;
							cout<<"请输入姓名：";
							cin>>name_;
							cout<<"请输入性别(男性->M，女性->F)：";
							cin>>sex_;
							a.stu[n-1].change_base(id_,name_,sex_); 
						}
						break;
					}
					case 6:{
						int n;
						string name_;
						char nature_;
						a.display_all();
						cout<<"请输入学生序号(第一列)：";
						cin>>n;
						cout<<"请输入名称：";
						cin>>name_;
						cout<<"请输入性质(奖->T,惩->F)：";
						cin>>nature_;
						a.stu[n-1].t.add_(name_,nature_);				
						break;
					}
					case 7:{
						int n;
						a.display_all();
						cout<<"请输入学生序号(第一列)：";
						cin>>n;
						int n_sec;
						if(a.stu[n-1].t.num<=0) cout<<"不可进行删除操作！"<<endl;
						else
						{
							a.stu[n-1].t.display_all();
							cout<<"请输入奖惩序号(第一列)：";
							cin>>n_sec;
							a.stu[n-1].t.delete_(n_sec-1);
						}
						break;
					}
					case 8:{
						int n;
						int n_sec;
						string name_;
						char nature_;
						a.display_all();
						cout<<"请输入学生序号(第一列)：";
						cin>>n;
						if(a.stu[n-1].t.num<=0) cout<<"无奖惩"<<endl;
						else
						{
							a.stu[n-1].t.display_all();
							cout<<"请输入奖惩序号(第一列)：";
							cin>>n_sec;
							cout<<"请输入名称：";
							cin>>name_;
							cout<<"请输入性质(奖->T,惩->F)：";
							cin>>nature_; 
							a.stu[n-1].t.change_(n_sec-1,name_,nature_);
						}
						break;
					}
					case 9:{
						int n;
						int n_sec;
						a.display_all();
						cout<<"请输入学生序号(第一列)：";
						cin>>n;
						double mark_; 
						if(a.stu[n-1].c.num<=0) cout<<"无课程"<<endl;
						else
						{
							a.stu[n-1].c.display_all();
							cout<<"请输入课程序号(第一列)：";
							cin>>n_sec;
							cout<<"请输入成绩：";
							cin>>mark_;
							a.stu[n-1].c.change_mark(n_sec-1,mark_);
						}
						break;
					}
					case 10:{
						int n;
						a.display_all();
						cout<<"请输入学生序号(第一列)：";
						cin>>n;
						a.stu[n-1].c.display_all();
						break;
					} 
					case 0:{
						
						break;
					}
					default:{
						cout<<"输入有误!"<<endl;
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
						int id_; 
						for(int i=0;i<Max;i++)
						{
							cout<<i<<sta[i]<<" ";
						}
						cout<<endl;
						cout<<"请输入课程代码："<<endl;						
						cin>>id_;
						b.add_(id_);
						break;
					}
					case 3:{
						int n;
						if(b.num<=0) cout<<"不可进行删除操作！"<<endl;
						else
						{
							b.display_all();
							cout<<"请输入课程序号(第一列)：";
							cin>>n;
							for(int i=0;i<b.c[n-1].stu_num;i++)
							{
								for(int j=0;j<a.num;j++)
								{
									if(b.c[n-1].stu_list[i]==a.stu[j].id)
									{
										a.stu[j].c.delete_1(b.c[n-1].id);
										break;
									}
								}
							}
							b.delete_(n-1);
						}
						break;
					}
					case 4:{
						int n;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						b.c[n-1].display_tea(); 
						break;
					}
					case 5:{
						int n;
						int id_;
						string name_;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						cout<<"请输入老师工号：";
						cin>>id_;
						cout<<"请输入老师姓名：";
						cin>>name_;
						b.c[n-1].add_tea(id_,name_);
						break;
					}
					case 6:{
						int n;
						int n_sec;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						if(b.c[n-1].tea_num<=0) cout<<"不可进行删除操作！"<<endl;
						else
						{
							b.c[n-1].display_tea();
							cout<<"请输入老师序号(第一列)：";
							cin>>n_sec;
							b.c[n-1].delete_tea(n_sec-1);
						}
						break;
					}
					case 7:{
						int n;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						b.c[n-1].display_stu_all();
						break;
					}
					case 8:{//课程添加学生，学生端也要添加这个课程 
						int n;
						int id_;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						cout<<"请输入学生id：";
						cin>>id_;
						b.c[n-1].add_stu(id_);
						for(int i=0;i<a.num;i++)
						{
							if(a.stu[i].id==id_)
							{
								a.stu[i].c.add_(b.c[n-1].id);//学生端添加课程 
								break;
							}
						}
						break;
					}
					case 9:{//课程端、学生端同步删除 
						int n;
						int n_sec;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						if(b.c[n-1].stu_num<=0) cout<<"不可进行删除操作！"<<endl;
						else
						{
							b.c[n-1].display_stu_all();
							cout<<"请输入学生序号：";
							cin>>n_sec;
							for(int i=0;i<a.num;i++)
							{
								if(a.stu[i].id==b.c[n-1].stu_list[n_sec-1])//找到这个学生 
								{
									for(int j=0;j<a.stu[i].c.num;j++)//对其课程组遍历 
									{
										if(a.stu[i].c.sin[j].id==b.c[n-1].id)
										{
											a.stu[i].c.delete_(j);//在学生选课里删除这门课 
											break;
										}
									}
									break;
								}
							}
							b.c[n-1].delete_stu(n_sec-1);//在这门课里删除这个学生 
						}
						break;
					}
					case 10:{
						int n;
						int id_;
						b.display_all();
						cout<<"请输入课程序号(第一列)：";
						cin>>n;
						cout<<"请输入学号：";
						cin>>id_;
						b.c[n-1].display_stu_one(id_);
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"输入有误！"<<endl;
						break;
					}
				}
				break;
			}
			case 3:{
				int n;
				int id_; 
				double mark_;
				if(b.num==0) cout<<"无课程"<<endl;
				else
				{
					b.display_all();
					cout<<"请输入所评课程序号：";
					cin>>n;
					cout<<"任课老师如下："<<endl;
					b.c[n-1].display_tea();
					cout<<"请输入所评老师工号：";
					cin>>id_;
					for(int i=0;i<b.c[n-1].tea_num;i++)
					{
						if(b.c[n-1].t[i].id==id_)
						{
							cout<<"请输入分数：";
							cin>>mark_;
							b.c[n-1].t[i].mark=mark_;
							break;
						}
					}
				}
				break;
			}
			case 0:{
				f=0;
				break;
			}
			default:{
				cout<<"输入有误!"<<endl;
				break;
			}
		}
		
	}
	return 0;
}
