#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;
//list class

bool create_file(string file){
	string file_name = file.append(".txt");
	const char *char_file_name = file_name.c_str(); 
	fstream new_file;
	new_file.open(char_file_name,ios::out);
	if(new_file.is_open() == true){
		return true;
	}else{
		return false;
	}
}

bool reg_file(string file_name, string reg_file){
	string name = file_name.append(".txt");
	const char *char_file_name = file_name.c_str();
	
	
	fstream new_file;
	new_file.open(char_file_name,ios::app);
	if(new_file.is_open() == false){
		cout<<"failed to append the file";
		return true;
		}
		
		new_file << reg_file;
  		new_file.close();
  		return true;
}

struct node{
	string number;
	node *next;
};

bool isEmpty(node *head);
char menu();
void insertAsFirstElement(node *&head, node*&last, string number);
void insert(node *&head, node*&last, string number);
void remove(node *&head, node*&last);
void showList(node *current);


bool isEmpty(node *head){
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}


char menu(){
	char choice;
	cout<<"MENU\n";
	cout<<"1.add an item.\n";
	cout<<"2.remove an item.\n";
	cout<<"3.show the list.\n";
	cout<<"4.exit.\n";
	
	cin>> choice;
	
	return choice;
}


void insertAsFirstElement(node *&head, node*&last, string number){
	node *temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;
	
}
void insert(node *&head, node*&last, string number){
	if(isEmpty(head)){
		insertAsFirstElement(head,last,number);
	}else{
		node *temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void remove(node *&head, node*&last){
		if(isEmpty(head)){
			cout<<"the list is already empty.\n";
		}
			else if(head == last){
				delete head;
				head = NULL;
				last = NULL;
				
			}else{
				node *temp = head;
				head = head->next;
				delete temp;
			}
		}
void showList(node *current){
	if(isEmpty(current)){
			cout<<"the list is empty\n";
	}
else{
	cout<<"the list contains: \n";
	while(current != NULL){
		cout<<current->number<<endl;
		current = current->next;
	}
}
}

//end of list class

void write_memory(){
	fstream reg_file;
	reg_file(reg_file.open("bobox.txt",ios::in));
	if(!reg_file.good()){
		throw "FAILED_TO_READ_FILE";
	}
}

int main(){
	node *head = NULL;
	node *temp = NULL;
	node *last = NULL;
	
	//linst of academics files
	//insert(head,last,"hellow");
	//insert(head,last,"wolrd");
	//insert(head,last,"of depercy1");
	//showList(head);
	
	if(reg_file("bobox","add the second to the list\n")){
		cout<<"file written well";
	}else{
		cout<<"failed";
	}
	
}
