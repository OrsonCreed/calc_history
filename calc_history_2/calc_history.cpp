//system constants
//#define SYSTEM_READY = 0


//includes
#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
//second part
#include<direct.h>

using namespace std;
//list class

bool create_file(string file) { // function to create a file
	string file_name = file.append(".txt");
	const char* char_file_name = file_name.c_str();
	fstream new_file;
	new_file.open(char_file_name, ios::out);
	if (new_file.is_open() == true) {
		return true;
	}
	else {
		return false;
	}
}

bool reg_file(string file_name, string reg_file) { //no .txt extension must be appended here
	string name = file_name.append(".txt");
	const char* char_file_name = file_name.c_str();


	fstream new_file;
	new_file.open(char_file_name, ios::app);
	if (new_file.is_open() == false) {
		cout << "failed to append the file";
		return true;
	}

	new_file << reg_file<<"\n";
	new_file.close();
	return true;
}

struct node {
	string number;
	node* next;
};

bool isEmpty(node* head);
char menu();
void insertAsFirstElement(node*& head, node*& last, string number);
void insert(node*& head, node*& last, string number);
void remove(node*& head, node*& last);
void showList(node* current);


bool isEmpty(node* head) {
	if (head == NULL) {
		return true;
	}
	else {
		return false;
	}
}


char menu() {
	char choice;
	cout << "MENU\n";
	cout << "1.add an item.\n";
	cout << "2.remove an item.\n";
	cout << "3.show the list.\n";
	cout << "4.exit.\n";

	cin >> choice;

	return choice;
}


void insertAsFirstElement(node*& head, node*& last, string number) {
	node* temp = new node;
	temp->number = number;
	temp->next = NULL;
	head = temp;
	last = temp;

}
void insert(node*& head, node*& last, string number) {
	if (isEmpty(head)) {
		insertAsFirstElement(head, last, number);
	}
	else {
		node* temp = new node;
		temp->number = number;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void remove(node*& head, node*& last) {
	if (isEmpty(head)) {
		cout << "the list is already empty.\n";
	}
	else if (head == last) {
		delete head;
		head = NULL;
		last = NULL;

	}
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
}
void showList(node* current) {
	if (isEmpty(current)) {
		cout << "the list is empty\n";
	}
	else {
		cout << "the list contains: \n";
		while (current != NULL) {
			cout << current->number << endl;
			current = current->next;
		}
	}
}

//end of list class

void write_memory(){
	//int a = count_reg_files("sample_file");
	//i failed to make an auto count, to make a const valiable, so by now the programmer must insert 
	//the value manualy
	const int num_of_record = 3;
	string swap; //using to put the swapped file_name from the list int an array
	string registered_files[num_of_record];
	fstream reg_file;
	reg_file.open("sample_file.txt", ios::in); //where the list of files are written
	if (!reg_file.good()) {
		throw "FAILED_TO_READ_FILE";
	}
	int i = 0;
	reg_file >> swap;
	while (reg_file.good()) {
		registered_files[i] = swap;
		reg_file >> swap;
		++i;
	}

	/*
	* loop to check if the array is functioning well
	int j = 0;
	while (j < num_of_record) {
		cout << registered_files[j]<<endl;
		++j;
	}
	
	*/
	
	


}


void read() {
	string txt;
	fstream read_file;
	read_file.open("sample_file.txt", ios::in);
	read_file >> txt;
	//cout << txt << endl;;
	while (read_file.good()) {
		cout << txt << endl;
		read_file >> txt;
	}
}


int count_reg_files(string file_name) {
	string txt = file_name;
	string filename = file_name.append(".txt");
	const char *fname = filename.c_str();
	int count;
	count = 0;
	fstream read_file;
	read_file.open(fname, ios::in);
	read_file >> txt;
	while (read_file.good()) {
		read_file >> txt;
		++count;
	}
	return count;
}


//second part of the system

class sym{//system class
private:
	bool SYSTEM_READY = false;
	string WORKING_DIR;//for storing the working directories
	string dirs[20]; //this is highly space consuming, you should use list or vectors to serve the space

	//already runned functions //some are templates not already setted
	bool install_system_conf = false;
	bool set_sym_exitst_conf = false;
	//bool install_system_conf;
	//bool install_system_conf;
	//bool install_system_conf;
	//bool install_system_conf;

	//system installation
public:

	string test_var;
	bool install_system() {
		//creating directories
		create_dir(dirs[0], "");
		create_dir(dirs[5], "");
		create_dir(dirs[1], "");
		//creating files


		//last file to be created in the system file
		create_file("success", dirs[0]);

		return true;
	}

	bool set_sym_exist() {
		string p = dirs[0].append("success.txt");
		const char* path = p.c_str();
		fstream confilm;
		confilm.open(path, ios::out);
		if (!confilm.is_open()) {
			return false;
		}
			confilm.close();
		}
	bool check_sym_exist() {
		string name = "\\success.txt";
		string p = WORKING_DIR + dirs[0] + name;
		//leason studied,append modifies the subject,and realy changes permanently
		//it is efficient on temporally variables but not permanent ones as it modifies its original
		//bobox the progressing and prommising programmer!
		const char* path = p.c_str();
		fstream confilm;
		confilm.open(path, ios::in);
		if (!confilm.is_open()) {
			return false;
		}
		else
		{
			SYSTEM_READY = true;
			return true;
		}
		confilm.close();
	}

	bool create_file(string fname,string path) { //fname for file name, path argument must be on of the dirs array
		fstream write_file;
		string file_dir = WORKING_DIR + path.append("\\");
		string f = file_dir + fname.append(".txt"); // for now i am creating .txt files only!
		const char *file = f.c_str();
		write_file.open(file, ios::out);
		if (!write_file.is_open()) {
			return false;
		}
		else {
			return true;
		}
		
	}

	bool create_dir(string dir_name, string path) {//path must be a member of dir array
		string dir;
		dir = WORKING_DIR + path.append("\\");
		dir = dir + dir_name;
		const char *directory = dir.c_str();
		if (_mkdir(directory) == -1) {
			return false;
		}
		else {
			return true;
		}


	}

	sym() {
		WORKING_DIR = "C:\\Users\\AM_CURRENT_USER\\source\\repos\\calc_history\\calc_history";
		/*
		* first 5 indexes is for the system path
		* second 5 is for the user directory
		*/
		dirs[0] = "\\system";
		dirs[1] = "\\system\\academics";
		dirs[5] = "\\users";

		if (!check_sym_exist()) {
			install_system();
		}//future cpp debugger bbx
	}








};


class user{
public:
	void hello() {
		cout << "hello world!";
	}
};



class mathematics_ops{};


class physics_ops{};



class sym_opes{};


int main() {
	node* head = NULL;
	node* temp = NULL;
	node* last = NULL;

	//linst of academics files
	//insert(head,last,"hellow");
	//insert(head,last,"wolrd");
	//insert(head,last,"of depercy1");
	//showList(head);
	
	
	/*
	
	
	*/
	

	//write_memory();
	sym test;
	
	if (test.check_sym_exist()) {
		cout << "success";
	}
	else {
		cout << "failed";
	}

	return 0;
}
