#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Temp{
	string id, name, author, search;
	fstream file;
	public:
		void addBook();
		void showAll();
		void extractBook();
}obj;








int main(){
	char choice;
	cout <<"-------------------------------\n";
	cout<<"1-Show All Books\n";
	cout<<"2-Select The Book\n";
	cout<<"3-Add Book (Admin)\n";
	cout<<"4-Exit\n";
	cout<<"--------------------------------\n";
	cout<<"Enter Your Choice\n";
	cin>>choice;
	switch(choice){
		case '1':
			cin.ignore();
			obj.showAll();
			
			break;
		case '2':
			cin.ignore();
			obj.extractBook();			
			break;
		case '3':
			cin.ignore();
			obj.addBook();
			break;
		case '4':
			return 0;
			
			break;
		defult:
			cout<<"Invalid Option";
	}
	
	
	return 0;
}




void Temp :: addBook(){
	cout <<"\nEnter a Book ID:";
	getline(cin, id);
	cout << "\nEnter a Book name:";
	getline(cin, name);
	cout << "\nEnter a Author Name:";
	getline(cin,author);
	
	file.open("bookdata.txt", ios:: out | ios :: app );
		file<<id<<"*"<<name<<"*"<<author<<endl;
		file.close();
}





void Temp::showAll() {
    file.open("bookdata.txt", ios::in);

    if (!file) {
        cout << "Error: Could not open file!" << endl;
        return;
    }

    cout << "\n\n";
    cout << "\t\t Book Id \t\t\t Book Name \t\t\t Author's Name" << endl;

    string id, name, author;
    
    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author, '\n')) {
        cout << "\t\t " << id << "\t\t\t " << name << "\t\t\t " << author << endl;
    }

    file.close();
}



void Temp :: extractBook(){
	showAll();
	cout<<"Enter a Book Id \n";
	getline(cin, search);
	
	
	
	file.open("bookdata.txt", ios::in);
		getline(file,id,'*');
		getline(file, name, '*');
		getline(file , author, '\n');
		cout<<"\n\n";
		cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
		
		while(!file.eof()){
			if(search==id){
				cout<<"\t\t " <<id<<"\t\t\t "<<name<<"\t\t\t "<<author<<endl;
				cout << "Book Extracted Sucessfully";
				
			}
		getline(file,id,'*');
		getline(file, name, '*');
		getline(file , author, '\n');
			
		}
		file.close();
		
}
