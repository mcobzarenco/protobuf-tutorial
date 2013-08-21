#include <iostream>
#include <fstream>
#include <string>

#include "address-cpp/addressbook.pb.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
	cerr << "Usage: " << argv[0] << " <file>" << endl;
	exit(-1);
    }

    GOOGLE_PROTOBUF_VERIFY_VERSION;


    addressbook::AddressBook address_book;
    fstream in(argv[1], ios::in | ios::binary );
    if (!address_book.ParseFromIstream(&in)) {
	cerr << "Could not parse file '" << argv[1] << "'" << endl;
	exit(-1);
    }

    size_t book_size = address_book.person_size();
    cout << "The address book in file '" << argv[1] << "' contains " << book_size << " entries." << endl;
    for(size_t i = 0; i < book_size; i++) {
	const addressbook::Person& person = address_book.person(i);
	cout << "ID: " << person.id() << endl;
	cout << "name: " << person.name() << endl;
	if (person.has_email()) {
	    cout << "email: " << person.email() << endl;
	} else {
	    cout << "no email set" << endl;
	}
    }

    in.close();
    return 0;
}
