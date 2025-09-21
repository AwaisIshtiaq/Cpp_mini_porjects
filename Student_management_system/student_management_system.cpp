#include <iostream>
#include <fstream>

using namespace std;


class Temp{
	string  rollNum, name, fName, address, search;
	fstream file;
	public:
	void addStu();
	void viewStu();
	void searchStu();  
}obj;


int main(){
	char choice;
	
	cout <<"----------------------------\n";
	cout << "\n1- Add Student Record";
	cout <<"\n2- View all Student Record";
	cout << "\n3- Search Student Record";
	cout <<"\n4- Exist";
	cout << "\n----------------------------\n";
	cin>>choice;
	switch (choice){
	
		case '1':
			obj.addStu();
			break;
		case '2':
			obj.viewStu();
			break;
		case '3':
			obj.searchStu();
			break;
		case '4':
			return 0;
			break;
		default:
			cout<< "Invalid Choice............!";
	}
	return 0;
}




void Temp :: addStu(){
	cout << "Enter Student Roll Number Please: \n";
	getline(cin, rollNum);
	cout << "\nEnter Student Name Please: ";
	getline(cin, name);
	cout <<"\nEnter Student Father Name Please : ";
	getline(cin, fName);
	cout<<"\nEnter Student Address Please: ";
	getline(cin, address);
	
	file.open("studentdata.txt", ios::out | ios:: app);
	file<<rollNum<<"*";
	file<<name<<"*";
	file<<fName<<"*";
	file<<address<<endl;
	file.close();
}




void Temp :: viewStu(){
	file.open("studentdata.txt", ios::in);
	getline(file, rollNum,'*');
	getline(file , name, '*');
	getline(file, fName, '*');
	getline(file,address,'\n');
	while(!file.eof()){
		cout<<"\n";
		cout<<"Student Roll Number: " <<rollNum;
		cout <<"Student Name:" <<name;
		cout<<"Student Father Name: "<<fName;
		cout<<"Student Address"<<address;
		
		getline(file, rollNum,'*');
		getline(file , name, '*');
		getline(file, fName, '*');
		getline(file,address,'\n');
		
	}
	file.close();
}




void Temp :: searchStu(){
	cout<<"Enter Student Roll Number";
	getline(cin, search);
	
	file.open("studentdata.txt", ios::in);
	getline(file, rollNum,'*');
	getline(file , name,'*');
	getline(file, fName, '*');
	getline(file,address,'\n');
	while(!file.eof()){
		if(rollNum == search){
			cout<<endl;
			cout<<"Student Roll Number: " <<rollNum;
			cout <<"Student Name:" <<name;
			cout<<"Student Father Name: "<<fName;
			cout<<"Student Address"<<address;
			
			getline(file, rollNum,'*');
			getline(file , name, '*');
			getline(file, fName, '*');
			getline(file,address,'\n');
			
		}
		file.close();	}
	
}
