#include "person.pb.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  Serialize::Address address;
  address.set_building(15);
  address.set_street("Burn");
  *address.mutable_street() += "out";

  cout << address.street() << ", " << address.building() << endl;

  Serialize::Person person;
  person.add_phone_number("+7-777-777-77-77");
  person.add_phone_number("+7-666-666-66-66");

  for (const string &phone : person.phone_number())
  {
    cout << phone << endl;
  }

  *person.mutable_address() = address;

  ofstream output("person.bin", std::ios_base::binary);
  person.SerializeToOstream(&output);

  output.close();

  cout << "-----\n";

  ifstream input("person.bin", std::ios_base::binary);
  Serialize::Person parsed_person;

  if (parsed_person.ParseFromIstream(&input))
  {
    cout << "Name: " << parsed_person.name() << endl;
    cout << "Phone number count: " << parsed_person.phone_number_size() << endl;
    if (parsed_person.has_address())
    {
      cout << "Street: " << parsed_person.address().street() << endl;
    }
    else
    {
      cout << "No address" << endl;
    }
  }
  else
  {
    cout << "Failed to parse" << endl;
  }

  return 0;
}
