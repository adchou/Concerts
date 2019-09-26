/******************************************************************
    Andrew Chou's performance implementation file for project 2.
    September 25, 2019 
*******************************************************************/
#include "performance.h"


using namespace std;

Performance::Performance(const string& w1, const string& w2, const Date& d1, double c)
{
    who = w1;
    where = w2;
    when = d1;
    cost = c;
}

istream& operator >> (std::istream& ins, Performance& p)
{
    p.input(ins);
    return ins;
}
ostream& operator << (std::ostream& outs, const Performance& p)
{
    p.output(outs);
    return outs;
}

void Performance::input(std::istream& ins)
{
    
    if(&cin == &ins)
    {
        cout << "Please enter the name of the group" << endl;
        
            while(ins.peek() == '\n' || ins.peek() == '\r')
            {
            ins.ignore();
            }
        getline(cin, who);
        
        cout << "Please enter location of the concert" << endl;
        
        while(ins.peek() == '\n' || ins.peek() == '\r')
            {
            ins.ignore();
            }
            getline(cin , where); 

        cout << "Please enter the date of the concert" << endl;
        cin >> when;

        cout << "Please enter the price of the concert" << endl;
        cin >>cost;
    }
    else
    {
        
        
   
        while(ins.peek() == '\n' || ins.peek() == '\r')
            {
            ins.ignore();
            }

            getline(ins, who);
     
        while(ins.peek() == '\n' || ins.peek() == '\r')
            {
            ins.ignore();
            }

            getline(ins, where);


        ins >> when;
        ins >> cost;
    }
}
void Performance::output(std::ostream& outs)const
{
cout << "Name of group: " << who << endl;
cout << "Location: " << where << endl;
cout << "Date: " << when << endl;
cout << "Cost: " << cost << endl;


}
bool Performance::operator ==(const Performance&p)const
{
    
    if(where == p.where && when == p.when)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Performance::operator !=(const Performance&p)const
{
    
    if(where != p.where && when != p.when)
    {
        return true;
    }
    else
    {
        return false;
    }
}

