#include<bits/stdc++.h>
using namespace std;
class Employee{
	int id;
	double sal;
	public :
		Employee()
		{
			this->id=0;
			this->sal=0;
		}
		Employee(int id,double sal)
		{
			this->id=id;
			this->sal=sal;
		}
		void setId(int id)
		{
			this->id=id;
		}
		void setSal(double sal)
		{
			this->sal=sal;
		}
		int getId()
		{
			return id;
		}
		double getSal()
		{
			return sal;
		}
		virtual void accept()
		{
		  int id;
		  double sal;
          cout<<"\tId         : ";
          cin>>id;
          setId(id);
          cout<<"\tSalary     : ";
          cin>>sal;
          setSal(sal);
		}
		virtual void display()
		{
          cout<<"\tId         : "<<getId()<<endl;
          cout<<"\tSalary     : "<<getSal()<<endl;
		}
};
class Manager : virtual public Employee{
	protected : 
	double bonus;
	public :
		Manager()
		{
			bonus=0;
		}
		Manager(int id,double sal,double bonus):Employee(id,sal)
		{
			this->bonus=bonus;
		}
		void setBonus(double bonus)
		{
			this->bonus=bonus;
		}
		double getBonus()
		{
			return bonus;
		}
		void acceptManager()
		{
			double bonus;
			cout<<"\tBonus      : ";
			cin>>bonus;
			setBonus(bonus);
		}
		void displayManager()
		{
			cout<<"\tBonus      : "<<getBonus()<<endl;
		}
		void accept()
		{
			Employee::accept();
			acceptManager();
		}
		void display()
		{
			Employee::display();
			displayManager();
		}
};
class Salesman : virtual public Employee{
	protected : 
	double commission ;
	public :
		Salesman()
		{
			commission=0;
		}
		Salesman(int id,double sal,double commission):Employee(id,sal)
		{
			this->commission=commission;
		}
		void setcommission(double commission)
		{
			this->commission=commission;
		}
		double getcommission()
		{
			return commission;
		}
		void acceptSalesman()
		{
			double commission;
			cout<<"\tCommission : ";
			cin>>commission;
			setcommission(commission);
		}
		void displaySalesman()
		{
			cout<<"\tCommission : "<<getcommission()<<endl;
		}
		void accept()
		{
			Employee::accept();
			acceptSalesman();
		}
		void display()
		{
			Employee::display();
			displaySalesman();
		}
};
class SalesManager : public Manager , public Salesman {
	public :
		SalesManager()
        {
        }
        SalesManager(int id, double sal, double bonus, double commission) : Employee(id, sal)
        {
        }
		void accept()
		{ 
		    cout<<"Enter Details : "<<endl;
			Employee::accept();
			acceptManager();
			acceptSalesman();
		}
		void display()
		{
			cout<<"Details : "<<endl;
			Employee::display();
			displayManager();
			displaySalesman();
		}
};
int main()
{
    Employee *e = new SalesManager;
    e->accept();
    e->display();
    delete e;
    e=NULL;

    return 0;
}

