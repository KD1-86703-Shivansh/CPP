#include  <bits/stdc++.h>
using namespace std;

class Product{                       //base class declaration
	protected :
	   int id;
	   string title;
	   double price;
	public :
		Product()                   //default constructor
		{
			this->id=0;
			this->title="";
			this->price=0;
		}
		void setId(int id)           //mutater for id
		{
			this->id=id;
		}
		void setTitle(string title) //mutater for title
		{
			this->title=title;
		}
		void setPrice(double price) //mutator for price
		{
			this->price=price;
		}
		int getId()                 //inspector for id 
		{
			return id;
		}
		string getTitle()           //inspector for title
		{
			return title;
		}
		double getPrice()           //inspector for price
		{
			return price;
		}
		virtual void accept()               //falicitator to get values
		{
			int id;
			string title;
			float price;
			cout<<"\tId          : ";
			cin>>id;
			setId(id);
			getchar();
			cout<<"\tTitle       : ";
			getline(cin,title);
			setTitle(title);
			cout<<"\tPrice       : ";
			cin>>price;
			setPrice(price);
			getchar();
		}
		virtual double display()               //falicitator to display data members
		{
			cout<<"\tId          : "<<getId()<<endl;
			cout<<"\tTitle       : "<<getTitle()<<endl;
			cout<<"\tPrice       : "<<getPrice()<<endl;
			return getPrice();
		}
		virtual ~Product()
		{
		}
};

class Book : public Product          //Derived class derivation
{
	protected : 
	    string author;
	public :
		Book()                       //Parameterless constructor
		{
			this->author="";
		}
		string setAuthor(string author) //mutater for author
		{
			this->author=author;
		}
		string getAuthor()           //inspector for author
		{
			return author;
		}
		void accept()                //Overriden accept method
		{
			cout<<"Enter Book Details : "<<endl;
			Product :: accept();
			cout<<"\tAuthor      : ";
			getline(cin,author);
			setAuthor(author);
		}
		double display()              //Overriden Display class
		{
			cout<<"Book Details :"<<endl;
			double price=Product :: display();
			cout<<"\tAuthor      : "<<getAuthor()<<endl;
			cout<<"\t10% discount: "<<price*0.9<<endl;
			return price*0.9;
		}
};
class Tape : public Product          //Derived class derivation
{
	protected : 
	    string artist;
	public :
		Tape()                       //Parameterless constructor
		{
			this->artist="";
		}
		string setArtist(string artist)           //mutator for artist
		{
			this->artist=artist;
		}
		string getArtist()           //inspector for artist
		{
			return artist;
		}
		void accept()                //Overriden method of base class
		{
			cout<<"Enter Tape Details : "<<endl;
			Product :: accept();
			cout<<"\tArtist      : ";
			getline(cin,artist);
			setArtist(artist);
		}
		double display()               //Overriden method of base class
		{
			cout<<"Tape Details :"<<endl;
			double price=Product :: display();
			cout<<"\tArtist      : "<<getArtist()<<endl;
			cout<<"\t5% discount : "<<price*0.95<<endl;
			return price*0.95;
		}
};
enum emenu
{
	Exit,
	Buy_Book,
	Buy_Tape,
	Display_Bill
};
int menu()
{
    int choice;
    cout << "********************************" << endl;
    cout << "What would you like to buy....? " << endl;
    cout << "\t0. EXIT" << endl;
    cout << "\t1. Buy Book" << endl;
    cout << "\t2. Buy Tape" << endl;
    cout << "\t3. Display Bill" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "********************************" << endl;

    return choice;
}
int main()
{
	Product *p[3];
	int index=0;
	int choice;
	double tot=0;
	while((choice=menu())!= Exit)
	{
	  switch(emenu(choice))
	  {
		case Buy_Book:
			if(index<3)
			{
				p[index]=new Book;
				p[index]->accept();
				index++;
			}
			else 
			    cout<<"You cannot buy more than three products!"<<endl;
			break;
		case Buy_Tape:
			if(index<3)
			{
				p[index]=new Tape;
				p[index]->accept();
				index++;
			}
			else 
			    cout<<"You cannot buy more than three products!"<<endl;
		    break;
		case Display_Bill:
			cout<<"INOVICE"<<endl;
			cout << "--------------------------------" << endl;
			for(int i=0;i<index;i++)
			{
				cout<<"Ttem "<<i+1<<" : "<<endl;
				tot=tot+p[i]->display();
			}
			cout << "--------------------------------" << endl;
			cout<<"Total = "<<tot<<endl;
			cout << "--------------------------------" << endl;
			break;
		default:
                cout << "Invalid choice ! " << endl;
                break;
      }
	}
	for(int i=0;i<3;i++)
	{
	    delete p[i];
	    p[i]=NULL;
	}
}

