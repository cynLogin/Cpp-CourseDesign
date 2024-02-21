#include<iostream>
#include<fstream>
#define Max 6
using namespace std;
string sta[15]={"��ɢ","�ߴ�","ģ��","���ݽṹ","���","����"};
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
					if(sin[i].nature=='T') cout<<"��"<<endl;
					else cout<<"��"<<endl; 
					break;
				}
			}
			if(i==num) cout<<"��ѯʧ�ܣ�"<<endl;
		}
		void display_all()
		{
			if(num==0) cout<<"�޽���"<<endl;
			for(int i=0;i<num;i++)
			{
				cout<<sin[i].name<<" ";
				if(sin[i].nature=='T') cout<<"��"<<endl;
				else cout<<"��"<<endl;
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
			if(num==0) cout<<"�޿γ�"<<endl;
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
			if(i==num) cout<<"��ѯʧ�ܣ�"<<endl;
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
		void add_stu(int id_)//�γ̶˼�ѧ����ѧ����ҲӦ�üӿγ� 
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
		void display_stu_one(int id_)//��ʾѧ�� 
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
			if(i==stu_num) cout<<"��ѯʧ�ܣ�"<<endl;
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
	cout<<"------------------�˵�-----------------"<<endl;
	cout<<"(1)ѧ����Ϣ����"<<endl;
	cout<<"(2)�γ���Ϣ����"<<endl;
	cout<<"(3)��ʦ����ϵͳ"<<endl; 
	cout<<"(0)�˳�"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"��������Ų����س���ѡ��"; 
}
void display_secmenu1()//ѧ���Ķ���Ŀ¼ 
{
	cout<<"------------------ѧ���˵�-----------------"<<endl;
	cout<<"(1)��ʾ����ѧ��"<<endl;
	cout<<"(2)���ѧ��"<<endl;
	cout<<"(3)ɾ��ѧ��"<<endl;
	cout<<"(4)��ѯѧ��ȫ����Ϣ"<<endl;
	cout<<"(5)�޸Ļ�����Ϣ"<<endl;
	cout<<"(6)��ӽ�����Ϣ"<<endl;
	cout<<"(7)ɾ��������Ϣ"<<endl;
	cout<<"(8)�޸Ľ�����Ϣ"<<endl; 
	cout<<"(9)�γ̳ɼ�¼����޸�"<<endl;
	cout<<"(10)�γ̳ɼ���ѯ"<<endl; 
	cout<<"(0)�˳�"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"��������Ų����س���ѡ��";
}
void display_secmenu2()//�γ̵Ķ���Ŀ¼ 
{
	cout<<"------------------�γ̲˵�-----------------"<<endl;
	cout<<"(1)��ʾ���пγ�"<<endl;
	cout<<"(2)��ӿγ�"<<endl;
	cout<<"(3)ɾ���γ�"<<endl;
	cout<<"(4)��ʾ�����ο���ʦ"<<endl;
	cout<<"(5)����ο���ʦ"<<endl;
	cout<<"(6)ɾ���ο���ʦ"<<endl;
	cout<<"(7)��ʾ����ѡĳ�ε�ѧ��(ѡ��ϵͳ)"<<endl;//�γ�ѡ��ѧ����ѧ�����Զ���Ӹÿγ� 
	cout<<"(8)���ѡĳ�ε�ѧ��(ѡ��ϵͳ)"<<endl;
	cout<<"(9)ɾ��ѡĳ�ε�ѧ��(ѡ��ϵͳ)"<<endl;
	cout<<"(10)��ѯĳһ��ѡ�˿ε�ѧ��"<<endl; 
	cout<<"(0)�˳�"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"��������Ų����س���ѡ��";	
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
						cout<<"������ѧ�ţ�";
						cin>>id_;
						cout<<"������������";
						cin>>name_;
						cout<<"�������Ա�(����->M��Ů��->F)��";
						cin>>sex_;
						a.add_(id_,name_,sex_);
						break;
					}
					case 3:{
						if(a.num<=0) cout<<"���ɽ���ɾ��������"<<endl;
						else
						{
							a.display_all();
							int n;
							cout<<"������Ҫɾ����ѧ�����(��һ��)��";
							cin>>n;
							a.delete_(n-1);
						}
						break;
					}
					case 4:{
						int id_;
						cout<<"����������ѯѧ��ѧ�ţ�";
						cin>>id_;
						a.display_one(id_); 
						break;
					}
					case 5:{
						int id_;
						string name_;
						char sex_;
						if(a.num<=0) cout<<"��ѧ��"<<endl;
						else
						{
							a.display_all();
							int n;
							cout<<"������Ҫ�޸ĵ�ѧ�����(��һ��)��";
							cin>>n;
							cout<<"������ѧ�ţ�";
							cin>>id_;
							cout<<"������������";
							cin>>name_;
							cout<<"�������Ա�(����->M��Ů��->F)��";
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
						cout<<"������ѧ�����(��һ��)��";
						cin>>n;
						cout<<"���������ƣ�";
						cin>>name_;
						cout<<"����������(��->T,��->F)��";
						cin>>nature_;
						a.stu[n-1].t.add_(name_,nature_);				
						break;
					}
					case 7:{
						int n;
						a.display_all();
						cout<<"������ѧ�����(��һ��)��";
						cin>>n;
						int n_sec;
						if(a.stu[n-1].t.num<=0) cout<<"���ɽ���ɾ��������"<<endl;
						else
						{
							a.stu[n-1].t.display_all();
							cout<<"�����뽱�����(��һ��)��";
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
						cout<<"������ѧ�����(��һ��)��";
						cin>>n;
						if(a.stu[n-1].t.num<=0) cout<<"�޽���"<<endl;
						else
						{
							a.stu[n-1].t.display_all();
							cout<<"�����뽱�����(��һ��)��";
							cin>>n_sec;
							cout<<"���������ƣ�";
							cin>>name_;
							cout<<"����������(��->T,��->F)��";
							cin>>nature_; 
							a.stu[n-1].t.change_(n_sec-1,name_,nature_);
						}
						break;
					}
					case 9:{
						int n;
						int n_sec;
						a.display_all();
						cout<<"������ѧ�����(��һ��)��";
						cin>>n;
						double mark_; 
						if(a.stu[n-1].c.num<=0) cout<<"�޿γ�"<<endl;
						else
						{
							a.stu[n-1].c.display_all();
							cout<<"������γ����(��һ��)��";
							cin>>n_sec;
							cout<<"������ɼ���";
							cin>>mark_;
							a.stu[n-1].c.change_mark(n_sec-1,mark_);
						}
						break;
					}
					case 10:{
						int n;
						a.display_all();
						cout<<"������ѧ�����(��һ��)��";
						cin>>n;
						a.stu[n-1].c.display_all();
						break;
					} 
					case 0:{
						
						break;
					}
					default:{
						cout<<"��������!"<<endl;
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
						cout<<"������γ̴��룺"<<endl;						
						cin>>id_;
						b.add_(id_);
						break;
					}
					case 3:{
						int n;
						if(b.num<=0) cout<<"���ɽ���ɾ��������"<<endl;
						else
						{
							b.display_all();
							cout<<"������γ����(��һ��)��";
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
						cout<<"������γ����(��һ��)��";
						cin>>n;
						b.c[n-1].display_tea(); 
						break;
					}
					case 5:{
						int n;
						int id_;
						string name_;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						cout<<"��������ʦ���ţ�";
						cin>>id_;
						cout<<"��������ʦ������";
						cin>>name_;
						b.c[n-1].add_tea(id_,name_);
						break;
					}
					case 6:{
						int n;
						int n_sec;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						if(b.c[n-1].tea_num<=0) cout<<"���ɽ���ɾ��������"<<endl;
						else
						{
							b.c[n-1].display_tea();
							cout<<"��������ʦ���(��һ��)��";
							cin>>n_sec;
							b.c[n-1].delete_tea(n_sec-1);
						}
						break;
					}
					case 7:{
						int n;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						b.c[n-1].display_stu_all();
						break;
					}
					case 8:{//�γ����ѧ����ѧ����ҲҪ�������γ� 
						int n;
						int id_;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						cout<<"������ѧ��id��";
						cin>>id_;
						b.c[n-1].add_stu(id_);
						for(int i=0;i<a.num;i++)
						{
							if(a.stu[i].id==id_)
							{
								a.stu[i].c.add_(b.c[n-1].id);//ѧ������ӿγ� 
								break;
							}
						}
						break;
					}
					case 9:{//�γ̶ˡ�ѧ����ͬ��ɾ�� 
						int n;
						int n_sec;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						if(b.c[n-1].stu_num<=0) cout<<"���ɽ���ɾ��������"<<endl;
						else
						{
							b.c[n-1].display_stu_all();
							cout<<"������ѧ����ţ�";
							cin>>n_sec;
							for(int i=0;i<a.num;i++)
							{
								if(a.stu[i].id==b.c[n-1].stu_list[n_sec-1])//�ҵ����ѧ�� 
								{
									for(int j=0;j<a.stu[i].c.num;j++)//����γ������ 
									{
										if(a.stu[i].c.sin[j].id==b.c[n-1].id)
										{
											a.stu[i].c.delete_(j);//��ѧ��ѡ����ɾ�����ſ� 
											break;
										}
									}
									break;
								}
							}
							b.c[n-1].delete_stu(n_sec-1);//�����ſ���ɾ�����ѧ�� 
						}
						break;
					}
					case 10:{
						int n;
						int id_;
						b.display_all();
						cout<<"������γ����(��һ��)��";
						cin>>n;
						cout<<"������ѧ�ţ�";
						cin>>id_;
						b.c[n-1].display_stu_one(id_);
						break;
					}
					case 0:{
						
						break;
					}
					default:{
						cout<<"��������"<<endl;
						break;
					}
				}
				break;
			}
			case 3:{
				int n;
				int id_; 
				double mark_;
				if(b.num==0) cout<<"�޿γ�"<<endl;
				else
				{
					b.display_all();
					cout<<"�����������γ���ţ�";
					cin>>n;
					cout<<"�ο���ʦ���£�"<<endl;
					b.c[n-1].display_tea();
					cout<<"������������ʦ���ţ�";
					cin>>id_;
					for(int i=0;i<b.c[n-1].tea_num;i++)
					{
						if(b.c[n-1].t[i].id==id_)
						{
							cout<<"�����������";
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
				cout<<"��������!"<<endl;
				break;
			}
		}
		
	}
	return 0;
}
