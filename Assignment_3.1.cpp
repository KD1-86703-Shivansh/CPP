#include <iostream>
using namespace std;

class Volume 
{
    float length;
    float width;
    float height;

    public :

    Volume()     // parameterless (default) const
    {
        length = 5;
        width = 5;
        height = 5;
    }

    Volume(float l, float w, float h)   // parameterized(with 3 parameters)
    {
        length = l;
        width = w;
        height = h;
    }

    Volume(float val)     // single paramaterized
    {
        length = val;
        width = val;
        height = val;
    }

    int display()
    {
        cout<<"Volume of the box : "<<length*width*height<<endl;
    }
};

int main()
{
    int choice;
    cout<<"Enter your choice"<<endl;
    cout<<"1. Calculate Volume with default values "<<endl;
    cout<<"2. Calculate Volume with length,breadth and height with same value "<<endl;
    cout<<"3. Calculate Volume with different length,breadth and height values "<<endl;
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            {
                Volume v1;
                v1.display();
                break;
            }
        case 2:
            {
                int val;
                cout<<"Enter a value : "<<endl;
                cin>>val;
                Volume v2(val);
                v2.display();
                break;
            }
        case 3:
            {
                int val1,val2,val3;
                cout<<"Enter the values for length, width and height : "<<endl;
                cin>>val1>>val2>>val3;
                Volume v3(val1,val2,val3);
                v3.display();
                break;
            }
        default: 
            cout<<"Enter valid value "<<endl;
            break;
    }

}