//Roll No :
//19f - 0345	Ameer Hamza
//19f - 0296	Abdul wahab
//19f - 0266 	Muhammad Imtanan Wali//////////////////////////////////////////////
////////////////////// START ////////////////////////////////////////////
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<Windows.h>
using namespace std;
class Sign_In {
public:
	string user_name, Passward;
	void getUserName(void);
	void getPassward(void);
	void checking(int selection);
};
void inline Sign_In::getUserName(void)
{
	cout << "\nEnter Username: ";
	cin >> user_name;
}
void inline Sign_In::getPassward(void)
{
	cout << "\nEnter Passward: ";
	cin >> Passward;
}
void inline Sign_In::checking(int selection)
{
	switch (selection)
	{
	case 1:
	{
		while (true)
		{
			getUserName();
			getPassward();
			if (user_name == "Admin" && Passward == "Admin")
			{
				break;
			}
			else
			{
				cout << "Username & Passward incorrect.\a" << endl;
			}
		}
	}
	break;
	case 2:
	{
		while (1)
		{
			getUserName();
			getPassward();
			if (user_name == "Teacher" && Passward == "TEACHER")
			{
				break;
			}
			else
			{
				cout << "\nUsername & Passward incorrect.\a" << endl;
			}
		}
	}
	break;
	default:
	{
		cout << "Wrong Input.....\a" << endl;
	}
	break;
	}
}
class Person {
public:
	string first_name, last_name, contact, gender, address;
	Person() {};
	Person(string, string, string, string, string);
	void setFirstName(string);
	void setLastName(string);
	void setContact(string);
	void setGender(string);
	void setAddress(string);
	string getFirstName();
	string getLastName();
	string getContact();
	string getGender();
	string getAddress();
};
void inline Person::setFirstName(string f)
{
	first_name = f;
}
string inline Person::getFirstName()
{
	return first_name;
}
void inline Person::setLastName(string l)
{
	last_name = l;
}
string inline Person::getLastName()
{
	return last_name;
}
void inline Person::setContact(string c)
{
	if (c.length() == 11)
	{
		contact = c;
	}
	else
	{
		contact = c.substr(0, 12);
	}
}
string inline Person::getContact()
{
	return contact;
}
void inline Person::setAddress(string a)
{
	address = a;
}
string inline Person::getAddress()
{
	return address;
}
void inline Person::setGender(string g)
{
	if (g == "Male" || g == "male" || g == "Female" || g == "female")
	{
		gender = g;
	}
	else
	{
		gender = "Others";
	}

}
string inline Person::getGender()
{
	return gender;
}
Person::Person(string f, string l, string c, string a, string g)
{
	//calling setters functions to initialize data members....
	setFirstName(f);
	setLastName(l);
	setContact(c);
	setAddress(a);
	setGender(g);
}
//end of class person...
//start of class student inherited with class person...
class Father
{
	string* father_profession, * father_name, * parent_contact_no;
public:
	Father(string, string, string);
	void setFatherProfession(string);
	string getFatherProfession(void) const;
	void setFatherName(string);
	string getFatherName(void);
	void setParentContactNo(string);
	string getParentContactNo(void);
	~Father(void);
};
Father::Father(string pr, string n, string cn)
{
	father_profession = new string;
	father_name = new string, parent_contact_no = new string;
	setFatherName(n);
	setFatherProfession(pr);
	setParentContactNo(cn);
}
void inline Father::setFatherProfession(string p)
{
	*father_profession = p;
}
string inline Father::getFatherProfession(void) const
{
	return *father_profession;
}
void inline Father::setFatherName(string n)
{
	*father_name = n;
}
string inline Father::getFatherName(void)
{
	return *father_name;
}
void inline Father::setParentContactNo(string cn)
{
	*parent_contact_no = cn;
}
string inline Father::getParentContactNo(void)
{
	return *parent_contact_no;
}
Father::~Father(void)
{
	//deallocation of all memory....
	delete father_profession, father_name, parent_contact_no;
}
//class Student starts here...
class Student :public Person, public Father {
protected:
	static int student_number;
	string Class, roll, registered_date, fee_submitted, blood_group;
public:
	Student(string, string, string, string, string, string, string, string, string, string, string, string);//constructor
	int incrementStudent();
	void setClass(string);
	string getClass(void);
	void setRegisteredDate(string);
	string getRegisteredDate(void);
	void setFee(string);
	string getFee(void);
	void setBloodGroup(string);
	string getBloodGroup(void);
	void setRollNo();
	string getRollNo();
};
Student::Student(string cl, string b, string fee, string r, string f, string l, string c, string a, string g, string pr, string n, string pcn) :Person(f, l, c, a, g), Father(pr, n, pcn)
{
	setClass(cl);
	setRegisteredDate(r);
	setBloodGroup(b);
	setFee(fee);
}
void inline Student::setClass(string c)
{
	int n = atof(c.c_str());
	if (n >= 1 && n <= 10)
	{
		Class = c;
	}
	else
	{
		Class = "10";
	}
}
string inline Student::getClass(void)
{
	return Class;
}
void inline Student::setBloodGroup(string bg)
{
	blood_group = bg;
}
string inline Student::getBloodGroup(void)
{
	return blood_group;
}
void inline Student::setRegisteredDate(string rd)
{
	registered_date = rd;
}
string inline Student::getRegisteredDate(void)
{
	return registered_date;
}
int inline Student::incrementStudent()
{
	ifstream read;
	read.open("Student.txt");
	if (read.fail())
	{
		cerr << "Open file error." << endl << endl;
	}
	else
	{
		char ch;
		student_number = 0;
		while (!read.eof())
		{
			read.get(ch);
			if (ch == '\n')
			{
				student_number++;
			}
		}
		read.close();
	}
	student_number = student_number - 2;
	return student_number;
}
void inline Student::setFee(string f)
{
	int n = atof(f.c_str());
	if (n > 0)
	{
		fee_submitted = f;
	}
	else
	{
		fee_submitted = "-";
	}

}
string inline Student::getFee(void)
{
	return fee_submitted;
}

void inline Student::setRollNo()
{
	//converting int to string and using concatination generating roll no...
	if (incrementStudent() <= 9)
	{
		roll = ((getClass()) + "-0" + (to_string(incrementStudent())));
	}
	else
	{
		roll = ((getClass()) + "-" + (to_string(incrementStudent())));
	}
}
string inline Student::getRollNo(void)
{
	setRollNo();
	return roll;
}
int Student::student_number = 0;
//Start of class Teacher....
class Teacher : public Person {
protected:
	string* email, * joiningDate, * Passward, * conformPassward, * cnic, * qualification, * dob, * salary;
public:
	Teacher(string, string, string, string, string, string, string, string, string, string, string, string, string);
	void setEmail(string);
	string getEmail(void);
	void setJoiningDate(string);
	string getJoiningDate(void);
	void setPassward(string);
	string getPassward1(void);
	void setConformPassward(string);
	string getConformPassward(void);
	void setCnic(string);
	string getCnic(void);
	void setQualification(string);
	string getQualification(void);
	void setDob(string);
	string getDob(void);
	void setSalery(string);
	string getsalery(void);
	void addNewTeacher();//function for adding new teacher.
	~Teacher();
};
Teacher::Teacher(string f, string l, string c, string a, string g, string em, string jd, string pass, string cPassward, string Cnic, string qua, string Dob, string sal)
	:Person(f, l, c, a, g)
{		//Allocation of memory
	email = new string, joiningDate = new string, Passward = new string, conformPassward = new string, cnic = new string, qualification = new string, dob = new string, salary = new string;
	setEmail(em);
	setJoiningDate(jd);
	setPassward(pass);
	setConformPassward(cPassward);
	setCnic(Cnic);
	setQualification(qua);
	setDob(Dob);
	setSalery(sal);
}
void Teacher::addNewTeacher()
{
	ofstream outfile;
	outfile.open("Teacher.txt", ios::ate | ios::app);
	if (outfile.fail())
	{
		cout << "Open file error.\a" << endl;
	}
	else
	{
		outfile << endl;
		outfile << getFirstName() << " | ";
		outfile << getLastName() << " | ";
		outfile << getEmail() << " | ";
		outfile << getJoiningDate() << " | ";
		outfile << getPassward1() << " | ";
		outfile << getCnic() << " | ";
		outfile << getGender() << " | ";
		outfile << getQualification() << " | ";
		outfile << getContact() << " | ";
		outfile << getDob() << " | ";
		outfile << getAddress() << " | ";
		outfile << getsalery();
	}
	outfile.close();
	system("Teacher.txt");

}

void inline Teacher::setEmail(string e) {
	*email = e;
}
string inline Teacher::getEmail(void) {
	return *email;
}
void inline Teacher::setJoiningDate(string jd) {
	*joiningDate = jd;
}
string inline Teacher::getJoiningDate(void)
{
	return *joiningDate;
}
void inline Teacher::setPassward(string pass) {
	*Passward = pass;
}
string inline Teacher::getPassward1(void) {
	return *Passward;
}
void inline Teacher::setConformPassward(string cPassward) {
	*conformPassward = cPassward;
	if (getPassward1() == *conformPassward)
	{
		cout << "Passward Confirmed." << endl;
	}
	else
	{
		cout << "Passward not Confirmed." << endl;
	}
}
string inline Teacher::getConformPassward()
{
	return *conformPassward;
}
void inline Teacher::setCnic(string cn)
{
	*cnic = cn;
}
string inline Teacher::getCnic(void)
{
	return *cnic;
}
void inline Teacher::setQualification(string qual)
{
	*qualification = qual;
}
string inline Teacher::getQualification(void)
{
	return *qualification;
}
void inline Teacher::setDob(string Dob)
{
	*dob = Dob;
}
string inline Teacher::getDob(void)
{
	return *dob;
}
void inline Teacher::setSalery(string sal)
{
	*salary = sal;
}
string inline Teacher::getsalery(void)
{
	return *salary;
}
Teacher::~Teacher()
{
	//deallocation of memory
	delete email, joiningDate, Passward, conformPassward, cnic, qualification, dob, salary;
}
class Addnewcourse
{
protected:
	string courseName, courseCode, parentCourse;
	int selectClass;
public:
	Addnewcourse(void);
	void SetData(string, string, string);
	int SetClass();
	void writtingData();
};
Addnewcourse::Addnewcourse()
{
	courseName = "Null";
	courseCode = "Null";
	parentCourse = "Null";
	selectClass = 0;
}
int inline Addnewcourse::SetClass()
{
	int counter = 0, Class;
	string C;
	cout << "Enter class for assigning course: ";
	while (1)
	{
		cin >> C;
		Class = atof(C.c_str());
		if (Class >= 1 && Class <= 10)
		{
			this->selectClass = Class;
			cout << "Course assigned." << endl;
			counter = 1;
			break;
		}
		else
		{
			cout << "Wrong Input.....\nTry Again " << endl;
		}
		if (counter == 1)
		{
			break;
		}
	}
	return (Class);
}
void inline Addnewcourse::writtingData()
{
	ofstream writeData;
	writeData.open("Courses.txt", ios::app);
	if (writeData.fail())
	{
		cerr << "Open file error.\a" << endl;
		exit(1);
	}
	else
	{
		writeData << this->courseName << "	             | " << this->courseCode << "	 | "
			<< this->parentCourse << "	| " << this->selectClass << endl;
	}
	writeData.close();
	system("courses.txt");
}
void inline Addnewcourse::SetData(string couseName, string courseCode, string parentCourse)
{
	this->courseName = couseName;
	this->courseCode = courseCode;
	this->parentCourse = parentCourse;
	this->selectClass = selectClass;
	SetClass();
	writtingData();
}
class AssignCourse
{
protected:
	string teacher, course, Class, section;
public:
	void SelectTeacher();
	void SelectCourse();
	void SetTeacher(string);
	string GetTeacher();
	void setcourse(string);
	string getCourse();
	void setSection(string);
	string getSection();
	void setClass(string);
	string getClass();
	void WritingData();
};
void inline AssignCourse::SetTeacher(string teacher)
{
	this->teacher = teacher;
}
string inline AssignCourse::GetTeacher() { return (teacher); }
void inline AssignCourse::setcourse(string course)
{
	this->course = course;
}
string inline AssignCourse::getCourse() { return (course); }
void inline AssignCourse::setClass(string c)
{
	int n;
	n = atof(c.c_str());
	if (n >= 1 && n <= 10)
	{
		this->Class = c;
	}
	else
	{
		this->Class = "10";
	}
}
string inline AssignCourse::getClass()
{
	return (Class);
}
void inline AssignCourse::setSection(string s)
{
	this->section = s;
}
string inline AssignCourse::getSection()
{
	return (section);
}
void inline AssignCourse::SelectTeacher()
{
	string t, teacher;
	int count = 0;
	char ch;
	ifstream read;
	read.open("Teacher.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
		exit(1);
	}
	else
	{
		while (!read.eof())
		{
			read.get(ch);
			cout << ch;
		}
	}
	read.close();
	read.open("Teacher.txt");
	if (read.fail())
	{
		cerr << "error\a" << endl;
		exit(1);
	}
	else
	{
		cout << "Enter Teacher Name: ";
		while (true)
		{
			cin >> teacher;
			//for bringing pointer to zero position....
			read.seekg(0);
			while (!(read.eof()))
			{
				read >> t;
				if (teacher == t)
				{
					SetTeacher(teacher);
					cout << "Assign Course." << endl;
					count = 1;
					break;
				}
			}
			if (count == 1)
			{
				SelectCourse();
				WritingData();
				break;
			}
			else
			{
				cout << "Name doesn't exit." << endl;
			}
		}
	}
	read.close();
}
void inline AssignCourse::SelectCourse()
{
	string course, c;
	char ch;
	int count = 0;
	cout << "Enter course for Mr." << GetTeacher();
	cout << endl;
	ifstream read;
	read.open("Courses.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
	}
	else
	{
		while (!(read.eof()))
		{
			read.get(ch);
			cout << ch;
		}
		read.close();
		cout << endl;
		cout << "\nEnter course name: ";
		while (1)
		{
			cin >> course;
			read.open("Courses.txt");
			while (!(read.eof()))
			{
				read >> c;
				if (course == c)
				{
					setcourse(course);
					cout << "Course assigned to Mr." << GetTeacher() << endl;
					count = 1;
					break;
				}
			}
			if (count == 1)
			{
				break;
			}
			else
			{
				cout << "Course Doesn't exist.\nTry Again." << endl;
			}
			read.close();
		}
	}
}
void inline AssignCourse::WritingData()
{
	string Class, section;
	cout << "\nEnter class for Mr." << GetTeacher() << " to teach " << getCourse() << endl;
	cin >> Class;
	setClass(Class);
	cout << endl;
	cout << "\nEnter section for Mr." << GetTeacher() << " to teach " << getCourse() << endl;
	cin >> section;
	setSection(section);
	ofstream write("Teacher_Course.txt", ios::app);
	if (write.fail())
	{
		cerr << "Open file error.\a" << endl;
	}
	else
	{
		write << GetTeacher() << "    |" << getCourse() << " |" << getClass() << "   |" << getSection() << " |" << endl;
	}
	write.close();
}
////////////////////////////////////////////////////////
class EditStudentDetail
{
protected:
	ifstream read;
	ofstream write;
	char ch;
public:

	void display();
	void Editing();
	void Changing(int);
};
void inline EditStudentDetail::display()
{
	char temp;
	ifstream read;
	read.open("Student.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
		exit(1);
	}
	else
	{
		while (!read.eof())
		{
			read.get(temp);
			cout << temp;
		}
	}
	read.close();
	Editing();
}
void inline EditStudentDetail::Editing()
{
	string temp, choice, sel;
	int s;
	cout << "\nEnter Roll No. for editing: ";
	cin >> temp;
	cout << endl;
	ifstream read;
	read.open("Student.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
	}
	else
	{
		while (!(read.eof()))
		{
			read >> choice;
			if (temp == choice)
			{
				cout << "Roll No. found." << endl;
				cout << read.tellg();
				read.close();
				cout << "\n\n\n\n\n\n\n\n \t\t\tEnter choice:" << endl
					<< "\n\n\t\t\t\t\t--> Edit First Name.\t\t\t(Press 1)" << endl
					<< "\n\n\t\t\t\t\t--> Edit Last Name.\t\t\t(Press 2)" << endl
					<< "\n\n\t\t\t\t\t--> Edit Fee.\t\t\t(Press 3)" << endl
					<< "\n\n\t\t\t\t\t--> Edit Address.\t\t\t(Press 4)" << endl
					<< "\n\n\t\t\t\t\t--> Edit Contact No..\t\t\t(Press 5)" << endl;
				while (true)
				{
					cin >> sel;
					int s = atof(sel.c_str());
					if (s == 1 || s == 2 || s == 3 || s == 4 || s == 5)
					{
						Changing(s);
						break;
					}
					else
					{
						cout << "\nWrong Input!\nTry Again." << endl;
					}
				}

				break;
			}
		}
	}
	read.close();
}
void inline EditStudentDetail::Changing(int s)
{
	int count = 0, n = 0;
	string fName, lName, fee, address, contactNo, temp;
	switch (s)
	{
		//Editing would perform here....
	case 1:
	{
		cout << "Enter First Name to edit: ";
		cin >> fName;
		read.open("Student.txt");
		write.open("Editted.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 1)
					{
						temp = fName;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("Editted.txt");
	}
	break;
	case 2:
	{

		cout << "Enter First Name to edit: ";
		cin >> lName;
		read.open("Student.txt");
		write.open("Editted.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 2)
					{
						temp = lName;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("Editted.txt");
	}
	break;
	case 3:
	{

		cout << "Enter Fee to edit: ";
		cin >> fee;
		read.open("Student.txt");
		write.open("Editted.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 10)
					{
						temp = fee;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("Editted.txt");
	}
	break;
	case 4:
	{
		cout << "Enter Address to edit: ";
		cin >> address;
		read.open("Student.txt");
		write.open("Editted.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 12)
					{
						temp = address;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("Editted.txt");
	}
	break;
	case 5:
	{
		cout << "Enter Contact to edit: ";
		cin >> contactNo;
		read.open("Student.txt");
		write.open("Editted.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 6)
					{
						temp = contactNo;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("Editted.txt");
	}
	break;
	default:
		cout << "Wrong Input" << endl;
		break;
	}
}
/////////////////////////////////////////////////
class EditTeacherDetail
{
protected:
	ifstream read;
	ofstream write;
public:
	void display();
	void editing();
	void changing(int);
};

void inline EditTeacherDetail::display()
{
	char ch;
	ifstream read;
	read.open("Teacher.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
		exit(1);
	}
	else
	{
		while (!read.eof())
		{
			read.get(ch);
			cout << ch;
		}
	}
	editing();
	read.close();
}
void inline EditTeacherDetail::editing()
{
	ifstream read;
	int n;
	string num, temp, choice;
	cout << "\nEnter number to edit Teacher details: " << endl;
	cin >> num;
	read.open("Teacher.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a";
		exit(1);
	}
	else
	{
		while (!read.eof())
		{
			read >> temp;
			if (temp == num)
			{
				cout << "\n\n\n\n\n\n\n\n \t\t\tEnter choice:" << endl
					<< "\n\n\t\t\t\t\t--> Address.\t\t\t(Press 1)" << endl
					<< "\n\n\t\t\t\t\t--> Contact No..\t\t\t(Press 2)" << endl
					<< "\n\n\t\t\t\t\t--> Qualifications.\t\t\t(Press 3)" << endl
					<< "\n\n\t\t\t\t\t--> Salary.\t\t\t(Press 4)" << endl;
				while (true)
				{
					cin >> choice;
					//conversion to int
					n = atof(choice.c_str());
					if (n >= 1 && n <= 4)
					{
						changing(n);
						break;
					}
					else
					{
						cout << "Wrong Input.\nTry Again." << endl;
					}
				}
				break;
			}
		}
	}
	read.close();
}
void inline EditTeacherDetail::changing(int n)
{
	string temp, contactNo, address, qualifications, salary;
	int count = 0, num = 0;
	switch (n)
	{
	case 1:
	{
		cout << "Enter Address to edit: ";
		cin >> address;
		cout << endl;
		read.open("Teacher.txt");
		write.open("TeacherEdit.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 11)
					{
						temp = address;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("TeacherEdit.txt");
	}
	break;
	case 2:
	{
		cout << "Enter Contact No. to edit: ";
		cin >> contactNo;
		cout << endl;
		read.open("Teacher.txt");
		write.open("TeacherEdit.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 9)
					{
						temp = contactNo;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("TeacherEdit.txt");
	}
	break;
	case 3:
	{
		cout << "Enter Qualifications to edit: ";
		cin >> qualifications;
		cout << endl;
		read.open("Teacher.txt");
		write.open("TeacherEdit.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 8)
					{
						temp = qualifications;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("TeacherEdit.txt");
	}
	break;
	case 4:
	{
		cout << "Enter Salary to edit: ";
		cin >> salary;
		cout << endl;
		read.open("Teacher.txt");
		write.open("TeacherEdit.txt");
		if (read.fail() || write.fail())
		{
			cerr << "Open file error.\a" << endl;
		}
		else
		{
			while (!read.eof())
			{
				n = 0;
				read >> temp;
				if (temp == "|")
				{
					count++;
					n = 1;
				}
				if (n == 0)
				{
					if (count == 12)
					{
						temp = salary;
						n = 1;
					}
				}
				write << temp;
			}
		}
		read.close();
		write.close();
		system("TeacherEdit.txt");
	}
	break;
	default:
	{
		cout << "Wrong Input." << endl;
	}
	break;
	}//end of switch....
}
/////////////////////////////////////////
class ViewAllStudents {

public:
	void fun();
	void Display();
	void Individual();
};
void inline ViewAllStudents::fun()
{
	string choice;
	cout << "\n\n\n\n\n\n\t  +++++++++ View All Students +++++++++\n\n" << endl;
	cout << "\n\t\t--> View all students.\t\t\t(Press 1)" << endl
		<< "\t\t--> Search individual student.\t\t\t(Press 2)" << endl;
	while (true)
	{
		getline(cin, choice);
		if (choice == "1")
		{
			Display();
			break;
		}
		else if (choice == "2")
		{
			Individual();
			break;
		}
		else
		{
			cout << "\nWrong Input.\nTry Again." << endl;
		}
	}
}
void inline ViewAllStudents::Individual()
{
	int n = 0, N = 0; char ch;
	string rollNo, temp;
	ifstream read;
	cout << "Enter Roll No. : ";
	getline(cin, rollNo);
	cin.ignore();
	read.open("Student.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
	}
	else
	{
		while (!read.eof())
		{
			read >> temp;
			if (rollNo == temp)
			{
				n = read.tellg();
				for (int i = n; i < (n + 108); i++)
				{
					ch = read.get();
					if ((ch != '\n') & (ch != EOF))
					{
						cout << ch;
					}

				}
			}
		}
		if (n == 0)
		{
			cout << "Roll No. doesn't exist." << endl;
		}
		cout << endl;
	}
	read.close();
}
void inline ViewAllStudents::Display()
{
	char temp;
	ifstream read;
	read.open("Student.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
		exit(1);
	}
	else
	{
		while (!read.eof())
		{
			read.get(temp);
			cout << temp;
		}
	}
	read.close();
}
//////////////////////////////////////
class ViewAllTeachers {
protected:

public:
	void print();
};
void inline ViewAllTeachers::print()
{
	ifstream read;
	char ch;
	read.open("Teacher.txt");
	if (read.fail())
	{
		cerr << "Open file error.\a" << endl;
	}
	else
	{
		while (!read.eof())
		{
			read.get(ch);
			cout << ch;
		}
	}
	cout << endl;
	read.close();
}
/////////////////////////////////////////////
class UpdateStudentMarks
{
public:
	void SetClass();
};
void inline UpdateStudentMarks::SetClass()
{
	int count = 0;
	char ch;
	string Class, Roll, temp, course, marks, totalMarks;
	ifstream read;
	cout << "Enter class (1-10):" << endl;
	while (true)
	{
		cin >> Class;
		int a = atof(Class.c_str());
		if (a >= 1 && a <= 10)
		{
			cout << "\nRoll No. of students enrolled in class " << a << " are: " << endl;
			read.open("Student.txt");
			if (read.fail())
			{
				cerr << "Error in Opening file.\a" << endl;
				exit(1);
			}
			else
			{
				while (!read.eof())
				{
					read >> Class;
					if (a == atof(Class.c_str()))
					{
						cout << Class << endl;
					}
				}
			}
			read.close();
			cout << "\nEnter Roll No. (From above) to update marks: " << endl;
			cin >> Roll;
			cout << endl;
			read.open("Student.txt");
			if (read.fail())
			{
				cerr << "Error in Opening file.\a" << endl;
				exit(1);
			}
			else
			{
				while (!read.eof())
				{
					read >> temp;
					if (Roll == temp)
					{
						cout << "Enter course: " << endl;
						cin >> course;
						cout << "Enter marks: " << endl;
						cin >> marks;
						cout << "\nEnter total marks: " << endl;
						cin >> totalMarks;
						break;
					}
				}
			}
			read.close();
			break;
		}
		else
		{
			cout << "Wrong Input.\nTry Again." << endl;
		}
	}
	ofstream write("Student_Marks.txt", ios::app);
	if (write.fail())
	{
		cerr << "Error in Opening file.\a" << endl;
	}
	else
	{
		write << Roll << "\t| " << course << "\t| " << marks << "\t| " << totalMarks << endl;
	}
	write.close();
}
///////////////////////////////////////////////
class ViewStudentMarks
{

public:
	void viewMarks();
};
void inline ViewStudentMarks::viewMarks()
{
	int a;
	string ClassOpt, temp;
	char ch;
	ifstream read;
	cout << "\nEnter class (1-10) to display marks: ";
	while (true)
	{
		cin >> ClassOpt;
		a = atof(ClassOpt.c_str());
		if (a >= 1 && a <= 10)
		{
			break;
		}
		else
		{
			cout << "Wrong Input.\nTry Again." << endl;
		}
	}
	read.open("Student_Marks.txt");
	if (read.fail())
	{
		cerr << "Error in Opening file.\a" << endl;
	}
	else
	{
		cout << "Roll No.\tCourseName\tMarks\tTotal Marks " << endl;
		while (!read.eof())
		{
			read >> temp;
			if (temp.substr(0, 2) == ClassOpt)
			{
				cout << temp << "\t";
				getline(read, temp);
				cout << temp;
				cout << endl;
			}
		}
		cout << endl;
	}
	read.close();
}
////////////////////////////////////
class ViewAllCourses
{
public:
	void fun();
};
void inline ViewAllCourses::fun()
{
	ifstream read;
	char ch;
	read.open("Courses.txt");
	if (read.fail())
	{
		cerr << "Error in Opening file.\a" << endl;
	}
	else
	{
		while (!read.eof())
		{
			read.get(ch);
			cout << ch;
		}
	}
	read.close();
}
class Administrator :public Sign_In, public Student {

protected:

public:
	Administrator(string, string, string, string, string, string, string, string, string, string, string, string);
	void addNewStudent();//function for adding new student.
};
Administrator::Administrator(string f, string l, string cl, string r, string g, string c, string fn, string fp, string pc, string fs, string bg, string a)
	:Student(cl, bg, fs, r, f, l, c, a, g, fp, fn, pc)
{
	//Empty body
}
void Administrator::addNewStudent()
{
	ofstream outfile;
	outfile.open("Student.txt", ios::app);
	if (outfile.fail())
	{
		cout << "Error in Opening file.\a" << endl;
		exit(1);
	}
	else
	{
		outfile << endl;
		outfile << getRollNo() << " | " << getFirstName() << " | "
			<< getLastName() << " | "
			<< getClass() << " | "
			<< getRegisteredDate() << " | "
			<< getGender() << " | "
			<< getContact() << " | "
			<< getFatherName() << " | "
			<< getFatherProfession() << " | "
			<< getParentContactNo() << " | "
			<< getFee() << " | "
			<< getBloodGroup() << " | "
			<< getAddress() << " | ";
	}
	outfile.close();
	system("Student.txt");

}//end of function addStudent
class Marks
{
public:
	void StudentMarks()
	{
		ifstream in;
		ofstream out;
		string a;
		string num; ;
		string use;
		string marks;
		int x = 1;
		while (x == 1)
		{
			cout << "\n\n\nEnter Roll No.: ";
			cin >> num;
			in.open("student.txt", ios::app);
			while (!in.eof())
			{
				in >> a;
				if (num == a)
				{
					cout << "\nRoll No. found." << endl;
					use = num;
					x = 2;
					break;
				}
			}
			in.close();
			if (num != a)
			{
				cout << "\nWrong Roll Number.\n" << endl;
			}
		}
		in.close();
		out.open("StudentMarks.txt", ios::app);
		out << "\n" << use;
		cout << "Enter the marks of the student: ";
		cin >> marks;
		out << "        " << marks;
		out.close();
	}
};
class Teacher_Course
{
public:
	ifstream in;
	ofstream out;
	string a;
	string name;
	char ch;
	int n, N;
	void CourseDetails()
	{
		cout << "\n\nEnter your name: ";
		cin >> name;
		cin.ignore();
		in.open("Teacher_Course.txt", ios::app);
		if (in.fail())
		{
			cerr << "Error." << endl;
		}
		n = in.tellg();
		while (!in.eof())
		{
			in >> a;
			if (a == name)
			{
				N = in.tellg();
				cout << "\nName found.\n";
				cout << endl;
				cout << "Searched name is: " << a;
				cout << endl << endl;
				break;
			}
		}
		cout << endl;
		in.get(ch);
		while (!in.eof())
		{
			if (ch == '\n')
			{
				break;
			}
			else
			{
				in.get(ch);
				cout << ch;
			}
		}
		cout << a;
		if (a != name)
		{
			cout << endl << "Your name is not found.";
		}
		in.close();
		system("Teacher_Course.txt");
	}
};
//////////////////////////////////////
class studentPortal
{
private:
	ifstream inpF;
	ofstream outF;
	string SName, SName1, SName2, pass, passward, choice, choice1, choice2, str, str1, string1[2], mark;
	int count[5], num, num1, totalFee, totalMarks, paidFee;
	char ch, S1;
	void check();
	void viewMarks();
	void viewFee();
public:
	studentPortal()
	{
		SName = " ";
		SName1 = " ";
		passward = " ";
		pass = " ";
		choice = " ";
		choice1 = " ";
		choice2 = " ";
		str = " ";
		S1 = ' ';
		ch = ' ';
		mark = " ";
		count[4] = 0;
		num = 0;
		totalFee = 10000;
		paidFee = 0;
		totalMarks = 1000;
	}
	void signIn();
};
void studentPortal::signIn()
{
	while (true)
	{
		Sleep(1500);
		system("cls");
		cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
		cout << "\n\n\n\n\n\n \t\t\tEnter choice:\n\n\n\t\t\t\t\t--> Sign In.\t\t\t\t(Press 1)\n\n\n\t\t\t\t\t--> Instructions to use the program.\t(Press 2)\n\n\n\t\t\t\t = ";
		cin >> choice2;
		if (choice2 == "1")
		{
			cout << "\n\n  \t\t\t\t\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			Sleep(1000);
			system("cls");
			cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
			while (true)
			{
				Sleep(1000);
				system("cls");
				inpF.open("Student.txt");
				cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
				cout << "\n\n\n\n\n\n\n \t\t\tUsername: ";
				getline(cin, SName);
				while (!(inpF.eof()))
				{
					inpF >> SName1;
					if (SName1 == SName)
					{
						num = inpF.tellg();
						check();
						count[0] = 1;
						break;
					}
				}
				if (count[0] == 1)
				{
					break;
				}
				else
				{
					cout << "Username doesn't Exist." << endl;
				}
				inpF.close();
			}
			if ((SName == SName1) && (passward == pass))
			{
				cout << "\n\n\n\n    \tLoading";
				for (int a = 0; a < 5; a++)
				{
					Sleep(700);
					cout << ".";
				}
				while (true)
				{
					while (true)
					{
						Sleep(1000);
						system("cls");
						cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
						cout << "\n\n\n\n\n\n\n\n\n\n \t\t\tEnter choice:\n\n\n\t\t\t\t\t--> View Marks.\t\t(Press 1)\n\n\n\t\t\t\t\t--> Fee Details.\t(Press 2)\n\n\n\t\t\t\t = ";
						cin >> choice;
						if (choice == "1")
						{
							cout << "\n\n  \t\t\t\t\tLoading";
							for (int a = 0; a < 5; a++)
							{
								Sleep(700);
								cout << ".";
							}
							viewMarks();
							break;
						}
						else if (choice == "2")
						{
							cout << "\n\n  \t\t\t\t\tLoading";
							for (int a = 0; a < 5; a++)
							{
								Sleep(700);
								cout << ".";
							}
							viewFee();
							break;
						}
						else
						{
							cout << "      \t\t\tTry Again.";
							continue;
						}
					}
					cout << "\n\n <--Back to Menu.\t(Y OR N)\n= ";
					cin >> choice1;
					if (choice1 == "Y" || choice1 == "y")
					{
						cout << "\n\n\tLoading";
						for (int a = 0; a < 5; a++)
						{
							Sleep(700);
							cout << ".";
						}
						continue;
					}
					else
						break;
				}
			}
			else
			{
				cout << "Incorrect\a" << endl;
			}
		}
		else if (choice2 == "2")
		{
			cout << "\n\n  \t\t\t\t\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			Sleep(1000);
			system("cls");
			cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
			cout << "\n\n\nIt takes \"Username\" & \"Passward\".";
			cout << "If \"Username\" & \"Passward\"\n\nare correct then it takes choice b/w \"Marks\" & \"Fee\"";
			cout << ". Then\n\naccording to your choice it open \"Fee details\" OR \"Marks detail\".\n" << endl;
			cout << "You also have option to \"Back into Menu\"." << endl;

			cout << "\n\n <--Back to Menu.\t(Y OR N)\n= ";
			cin >> choice1;
			if (choice1 == "Y" || choice1 == "y")
			{
				cout << "\n\n\tLoading";
				for (int a = 0; a < 5; a++)
				{
					Sleep(700);
					cout << ".";
				}
				continue;
			}
			else
				break;
		}
		else
		{
			cout << "Invalid try again.";
		}
	}
}
void studentPortal::check()
{
	while (true)
	{
		cout << "\n\n \t\t\tPassward: ";
		cin >> passward;
		inpF.seekg(num);
		ch = ' ';
		count[1] = 0;
		while (!(inpF.eof()))
		{
			inpF >> ch;
			if (ch == '|')
			{
				count[1]++;
			}
			if (count[1] == 14)
			{
				break;
			}
		}
		inpF >> pass;
		if (pass == passward)
		{
			count[0] = 2;
			break;
		}
		else
			cout << "Invalid Passward.\a\n";
		if (count[0] == 2)
		{
			break;
		}
	}
}
void studentPortal::viewMarks()
{
	Sleep(300);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n" << endl;
	cout << "\n\n\n\n\n\n\t  _ _ _ _ _ _Marks Status_ _ _ _ _ _\n\n" << endl;
	inpF.seekg(num);
	ch = ' ';
	count[3] = 0;
	while (!(inpF.eof()))
	{
		inpF >> ch;
		if (ch == '|')
		{
			count[3]++;
		}
		if (count[3] == 1)
		{
			inpF >> string1[0];
		}
		if (count[3] == 2)
		{
			inpF >> string1[1];
			break;
		}
	}
	str1 = string1[0] + " " + string1[1];
	cout << "\n\n Student Name: " << str1 << "\t\t";
	cout << "Roll Number: " << SName1 << endl << endl << endl;
	inpF.close();
	inpF.open("StudentMarks.txt", ios::app);
	while (!(inpF.eof()))
	{
		inpF >> SName2;
		if (SName2 == SName)
		{
			num1 = inpF.tellg();
			break;
		}
	}
	num1 = num1 + 2;
	inpF.seekg(num1);
	inpF >> mark;
	inpF.close();
	inpF >> mark;
	cout << "\t\tTotal Marks: " << mark << "\\" << totalMarks << endl;
}
void studentPortal::viewFee()
{
	Sleep(300);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t-------Student Portal-------\n\n\n" << endl;
	cout << "\n\n\n\n\n\n\t    _ _ _ _ _ _Fee Status_ _ _ _ _ _\n\n" << endl;
	inpF.seekg(num);
	ch = ' ';
	count[2] = 0;
	while (!(inpF.eof()))
	{
		inpF >> ch;
		if (ch == '|')
		{
			count[2]++;
		}
		if (count[2] == 10)
		{
			break;
		}
	}
	inpF >> str;
	paidFee = atof(str.c_str());
	inpF.seekg(num);
	ch = ' ';
	count[3] = 0;
	while (!(inpF.eof()))
	{
		inpF >> ch;
		if (ch == '|')
		{
			count[3]++;
		}
		if (count[3] == 1)
		{
			inpF >> string1[0];
		}
		if (count[3] == 2)
		{
			inpF >> string1[1];
			break;
		}
	}
	str1 = string1[0] + " " + string1[1];
	cout << "\n\n Student Name: " << str1 << "\t\t";
	cout << "Roll Number: " << SName1 << endl << endl << endl;
	cout << "\t\t\tTotal Fee: 10000.\n" << endl;
	cout << "\t\t\tPaid Fee: " << str << ".\n" << endl;
	cout << "\t\t\tRemaining Fee: " << totalFee - paidFee << ".\n" << endl;
}
/////////////////////////////////////
void AdministraterModule()
{
	Sign_In Lock;
	Lock.checking(1);
	Sleep(300);
	system("cls");
	cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
	cout << endl;
	cout << "\n\n\n";
	cout << "Enter Choice:\n\n\t     --> Add New Student.\t\t(Press 1)" << endl
		<< "\n\t     --> Add New Teacher.\t\t(Press 2)" << endl
		<< "\n\t     --> Add New Course.\t\t(Press 3)" << endl
		<< "\n\t     --> Assign Course.\t\t\t(Press 4)" << endl
		<< "\n\t     --> Edit Student Details.\t\t(Press 5)" << endl
		<< "\n\t     --> Teacher Details.\t\t(Press 6)" << endl
		<< "\n\t     --> View All Students.\t\t(Press 7)" << endl
		<< "\n\t     --> View All Teachers.\t\t(Press 8)" << endl
		<< "\n\t     --> All Courses.\t\t\t(Press 9)" << endl
		<< "\n\t     --> Update Student Marks.\t\t(Press 10)" << endl
		<< "\n\t     --> View Students Marks.\t\t(Press 11)" << endl
		<< "\n\t     --> View Fee Details.\t\t(Press 12)" << endl;
	string f, l, cl, r, g, c, fn, fp, pc, fs, bg, a, em, jd, pass, cpass, cnic, qua, dob, sal, Choice;
	cin >> Choice;
	int val = atof(Choice.c_str());
	if (val >= 1 && val <= 12)
	{
		switch (val)
		{
		case 1:
		{
			system("cls");
			system("color E");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Add New Student _ _ _ _ _ _\n\n" << endl;
			cout << "\n\n" << endl;
			cout << "Details about student:-\n" << endl;
			cout << "\n\t\tEnter First Name: ";
			cin >> f;
			cout << "\n\t\tEnter Last Name: ";
			cin >> l;
			cout << "\n\t\tEnter class No.: ";
			cin >> cl;
			cout << "\n\t\tEnter registeration date: ";
			cin >> r;
			cout << "\n\t\tEnter gender: ";
			cin >> g;
			cout << "\n\t\tEnter contact No.: ";
			cin >> c;
			cout << "\n\t\tEnter blood group: ";
			cin >> bg;
			cout << "\n\nDatails about parents:-\n" << endl;
			cout << "\n\t\tEnter father name: ";
			cin >> fn;
			cout << "\n\t\tEnter father profession: ";
			cin >> fp;
			cout << "\n\t\tEnter father contact No.: ";
			cin >> pc;
			cout << "\n\t\tEnter fees submitted: ";
			cin >> fs;
			cout << "\n\t\tEnter permanant address: ";
			cin >> a;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			Administrator obj(f, l, cl, r, g, c, fn, fp, pc, fs, bg, a);
			obj.addNewStudent();
			Sleep(2000);
		}
		break;
		case 2:
		{
			system("cls");
			system("color A");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Add New Teacher _ _ _ _ _ _\n\n" << endl;
			cout << "Enter First Name: ";
			cin >> f;
			cout << "\nEnter Last Name: ";
			cin >> l;
			cout << "Enter E-mail: ";
			cin >> em;
			cout << "\nEnter joining date: ";
			cin >> jd;
			cout << "\nEnter Passward: ";
			cin >> pass;
			cout << "\nConfirm Passward: ";
			cin >> cpass;
			cout << "\nEnter CNIC No.: ";
			cin >> cnic;
			cout << "\nEnter qualifications: ";
			cin >> qua;
			cout << "\nEnter date of birth: ";
			cin >> dob;
			cout << "\nEnter salarey: ";
			cin >> sal;
			cout << "\nEnter contact No.: ";
			cin >> c;
			cout << "\nEnter permanant address: ";
			cin >> a;
			cout << endl << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			Teacher t(f, l, c, a, g, em, jd, pass, cpass, cnic, qua, dob, sal);
			t.addNewTeacher();
			Sleep(2000);
		}
		break;
		case 3:
		{
			system("cls");
			system("color 3");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Add New Course _ _ _ _ _ _\n\n" << endl;
			string courseName, courseCode, parentCourse;
			cout << "Enter Course Name: ";
			cin >> courseName;
			cout << "\nEnter Course code: ";
			cin >> courseCode;
			cout << "\nEnter Parent code: ";
			cin >> parentCourse;
			cin.ignore();
			Addnewcourse obj;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			obj.SetData(courseName, courseCode, parentCourse);
			cout << endl;
		}
		break;
		case 4:
		{
			system("cls");
			system("color B");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Assign Course _ _ _ _ _ _\n\n" << endl;
			AssignCourse object;
			object.SelectTeacher();
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
		}
		break;
		case 5:
		{
			system("cls");
			system("color D");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Edit Student Details _ _ _ _ _ _\n\n" << endl;
			EditStudentDetail object;
			object.display();
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
		}
		break;
		case 6:
		{
			system("cls");
			system("color 8");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Edit Teacher Detail _ _ _ _ _ _\n\n" << endl;
			EditTeacherDetail obj1;
			obj1.display();
			cout << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
		}
		break;
		case 7:
		{
			system("cls");
			system("color E");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ View All Students _ _ _ _ _ _\n\n" << endl;
			ViewAllStudents obj;
			obj.fun();
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			Sleep(3000);
		}
		break;
		case 8:
		{
			system("cls");
			system("color D");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ View All Teachers _ _ _ _ _ _\n\n" << endl;
			ViewAllTeachers obj;
			obj.print();
			cout << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			Sleep(3000);
		}
		break;
		case 9:
		{
			system("cls");
			system("color C");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ View All Courses _ _ _ _ _ _\n\n" << endl;
			ViewAllCourses obj;
			obj.fun();
			cout << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
			Sleep(3000);
		}
		break;
		case 10:
		{
			system("cls");
			system("color 3");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ Update Student Marks _ _ _ _ _ _\n\n" << endl;
			UpdateStudentMarks obj;
			obj.SetClass();
			cout << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(1000);
				cout << ".";
			}
			cout << endl;
		}
		break;
		case 11:
		{
			system("cls");
			system("color 5");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ View Student Marks _ _ _ _ _ _\n\n" << endl;
			ViewStudentMarks obj;
			obj.viewMarks();
			cout << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(1000);
				cout << ".";
			}
			cout << endl;
			Sleep(2000);
		}
		break;
		case 12:
		{
			system("cls");
			system("color F");
			cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
			cout << "\n\n\n\n\t  _ _ _ _ _ _ View Fee Details _ _ _ _ _ _\n\n" << endl;
			cout << "In Construction......." << endl;
			cout << "\n\n\tLoading";
			for (int a = 0; a < 5; a++)
			{
				Sleep(700);
				cout << ".";
			}
			cout << endl;
		}
		break;
		default:
			break;
		}
	}
	else
	{
		cout << "Wrong Input.\nTry Again." << endl;
	}
}
void Interface(void)
{
	string f, l, cl, r, g, c, fn, fp, pc, fs, bg, a, em, jd, pass, cpass, cnic, qua, dob, sal, Choice;
	int N;
	while (true)
	{
		system("color F");
		cout << "\n\n\t\t\t\t\t\t\t-------------- School Management System --------------\n\n" << endl;
		cout << "\n\n\nEnter Choice:\n" << endl
			<< "\t     --> Administrater Module.\t\t(Press 1)" << endl
			<< "\n\t     --> Student Module.\t\t(Press 2)" << endl
			<< "\n\t     --> Teacher Module.\t\t(Press 3)" << endl
			<< "\n\t     --> Quit.\t\t\t\t(Press Q)\n" << endl
			<< "\t= ";
		cin >> Choice;
		if (Choice == "Q" || Choice == "q")
		{
			cout << "\n\n\t\t\tThanks for visit.\n" << endl;
			break;
		}
		else if (Choice == "1" || Choice == "2" | Choice == "3")
		{
			N = atof(Choice.c_str());
			switch (N)
			{
			case 1:
			{
				cout << "\n\n\t\tLoading";
				for (int a = 0; a < 7; a++)
				{
					Sleep(700);
					cout << ".";
				}
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t************* Administrater Module *************\n\n" << endl;
				AdministraterModule();
				Sleep(2000);
			}
			break;
			case 2:
			{
				cout << "\n\n\t\tLoading";
				for (int a = 0; a < 7; a++)
				{
					Sleep(700);
					cout << ".";
				}
				studentPortal S1, S2;
				S1.signIn();
				cout << endl;
				Sleep(2000);
			}
			break;
			case 3:
			{
				cout << "\n\n\t\tLoading";
				for (int a = 0; a < 7; a++)
				{
					Sleep(700);
					cout << ".";
				}
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t************* Teacher Module *************\n\n\n" << endl;
				Sign_In O;
				O.checking(2);
				cout << endl;
				cout << "\n\n\tLoading";
				for (int a = 0; a < 5; a++)
				{
					Sleep(700);
					cout << ".";
				}
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t************* Teacher Module *************\n\n\n" << endl;
				cout << "\n\n\n\nEnter Choice:\n" << endl
					<< "\n\t     --> Check Assigned Courses.\t(Press 1)" << endl
					<< "\n\t     --> Upload Student Marks.\t\t(Press 2)" << endl
					<< "\t= ";
				while (true)
				{
					cin >> Choice;
					if (Choice == "1")
					{
						Teacher_Course obj;
						obj.CourseDetails();
						Sleep(2000);
						break;
					}
					if (Choice == "2")
					{
						Marks obj2;
						obj2.StudentMarks();
						Sleep(2000);
						break;
					}
					else
					{
						cout << "\nWrong Input." << endl;
					}
				}
				Sleep(2000);
			}
			break;
			default:
			{
				cout << "\nWrong Input." << endl;
			}
			break;
			}
		}
		else
		{
			cout << "\nWrong Input.\nTry Again." << endl;
			system("cls");
		}
		system("cls");
	}
}
int main(void)
{
	Interface();
	cout << endl;
	system("pause");
	return 0;
}