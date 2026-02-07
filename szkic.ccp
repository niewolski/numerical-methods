#include ...
#include <string>
#include <iostream>
#include "student.h"


typedef multi_index_container<
...
> student_multi;

...

int main()
{
  student_multi students;

  students.insert({"Ewa", "Kowalska", 1, "Kobieta"});
  students.insert({"Jan", "Wojcik", 3, "Mezczyzna"});
  students.insert({"Zofia", "Wojcik", 4, "Kobieta"});
  students.insert({"Adam", "Nowak", 2, "Mezczyzna"});

  cout<<endl<<"wg. :nazwiska "<<endl;
  for(nazwisko_type::iterator ...  ++it)
    it->show();

  cout<<endl<<"wg. indeksu: "<<endl;
  for(indeks_type::iterator ... ++it)
    it->show();

  cout<<"wg. plci"<<endl;
  for(plec_type::iterator ... ++it)
    it->show();

  return 0;
}
