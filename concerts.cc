#include "concerts.h"
//#include "performance.h"
#include <iostream>
#include "assert.h"
using namespace std;

Concerts::Concerts()
{
    //stores the pointer to first address of the data array
    data = new Performance[5];
    used = 0;
    current_index = 0;
    capacity = 5;

}

//Deconstructor
Concerts::~Concerts()
{
    delete[] data;
     cout << "deleted" << endl;
}
Concerts::Concerts(const Concerts& other)
{
    capacity = other.capacity;
    used = other.used;
    data = new Performance [capacity];
    copy(other.data, other.data + used, data);
}

void Concerts::operator = (const Concerts& other)
{
    if(this == &other)
    {
        return;
    }
    if(capacity!= other.capacity)
    {
        delete[] data;
        capacity = other.capacity;
        data = new Performance [capacity];
    }
    used = other.used;
    copy(other.data, other.data + used, data);
}


//internal iterator
 void Concerts::start()
 {
     current_index = 0;
     used = 0;

 }

void Concerts::advance()
  {
      if(is_item() == true)
      {
          current_index++;
      }
}

Performance current()const
{
    return data[current_index];
}

void Concerts::insert(const Performance& p)
{
    int i;
    assert ( used < capacity);
    if (is_item() == false)
    {
        current_index=0;
    }
    for (i= used; i>current_index;i--)
    {
        data[i] = data [i-1];
    }
    data[current_index]= p;
    used++;


}
void Concerts::attach(const Performance& p)
{
    size_t i;

      assert(used < capacity);

      if(!is_item())
      {
         current_index = used - 1;
      }
      for(i=used; i > current_index + 1; --i)
      {
         data[i] = data[i-1];
      ++current_index;
      data[current_index] = p;
      ++used;
}
}
void Concerts::remove_current()
{
    size_t i;

    assert(is_item());

    for(i = current_index + 1; i < used; ++i)
    {
         data[i-1] = data[i];
      --used;
    }
}

void Concerts::load(istream& ins)
{
   
    while(!ins.eof() && used < capacity)
    {
        ins >> data[used];

        used++;
    }
}

void Concerts::save(std::ostream& ofs)const
 {
     //loop through array and output it to the file
    for (size_t i; i < used; i++)
    {
			ofs << data[i] << endl;
	}
 }

bool Concerts::is_item()const
 {
     if (current_index < used)
     {
         return true;
     }
 }
 void Concerts::show_all(std::ostream& outs)const
 {
 	if(used == 0)
    {
	    cout<<"Empty list.\n";
    }
	else
    {
        //if list isnt empty output the entire list
	    for(size_t i = 0; i<used; ++i)
        {
		    outs<<data[i]<<endl;
        }
    }
}

bool Concerts::already_in(const Performance& p)const
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

