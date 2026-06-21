#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class capacityExceeded {
public:
	string what() {
		return "Capacity Exceeded";
	}
};
class overDue {
private:
	double fine;
public:
	overDue(double f) {
		fine = f;
	}
	string what() {
		return "Over Due. Fine: ";
	}
	double getFine() {
		return fine;
	}

};

class Person {
private:
	string name;
	string CNIC;
	string contact;
	int age;
public:
	Person(string n, string c, string con, int a) :
		name(n), CNIC(c), contact(con), age(a) {
	}
		
	virtual ~Person(){}
	virtual void displayInfo() = 0;
	string getName() {
		return name;
	}
	string getCNIC() {
		return CNIC;
	}
	string getContact() {
		return contact;
	}
	int getAge() {
		return age;
	}
};

class Student : public Person {
private:
	int rollNo;
	int semester;
	double GPA;
	string enrolledCourses[6];
	int courseCount;
	public
		Student(string n, string c, string con, int a, int r, int s, double g)
		:Person(n, c, cont, a), rollNo(r), semester(s), GPA(g), courseCount(0) {
	}
	void displayInfo(){
		cout << "Student: " << name << " | Roll Np: " << rollNo << " | GPA: " << GPA << " |Semester: " << semester << endl;
	}
	void calculateGrade() {
		if (GPA >= 3.5) {
			cout << "Grade: A" << endl;
		}
		else if (GPA >= 3.0) {
			cout << "Grade: B" << endl;
		}
		else if (GPA >= 2.0) {
			cout << "Grade: C" << endl;
		}
		else {
			cout << "Grade: F" << endl;
		}
		int getRollNo() {
			return rollNo;
		}
		double getGPA() {
			return GPA;
		}
		void setGPA(double g) {
			GPA = g;
		}
		void addCourse(string course) {
			if (courseCount < 6) {
				enrolledCourses[courseCount++] = course;
			}

		}
	};
	class Faculty :public Person {
	private:
		int employeeID;
		string department;
		string designation;
	public:
		Faculty(string n, string c, string con, int a, int eID, string dept, string desig)
			:Person(n, c, cont, a), employeeID(eID), department(dept), designation(desig) {
		}
		void displayInfo() {
			cout << "Faculty: " << name << " | Employee ID: " << employeeID << " | Department: " << department << " | Designation: " << designation << endl;
		}
		int getEmployeeID() {
			return employeeID;
		}
		string getDepartment() {
			return department;
		}
		string getDesignation() {
			return designation;
		}
	};
	class GraduateStudent :public Student {
	private:
		string researchTopic;
		string supervisor;
	public:
		GraduateStudent(string n, string c, string con, int a, int r, int s, double g, string topic, string sup)
			:Student(n, c, cont, a, r, s, g), researchTopic(topic), supervisor(sup) {
		}
		void displayInfo() {
			cout << "Graduate Student: " << name << " | Roll No: " << getRollNo() << " | GPA: " << getGPA() << " | Semester: " << semester << " | Research Topic: " << researchTopic << " | Supervisor: " << supervisor << endl;
		}
		string getResearchTopic() {
			return researchTopic;
		}
		string getSupervisor() {
			return supervisor;
		}
	};

	//member 2

	class Course {
	private:
		string courseCode, courseName;
		int creditHours, maxCapacity, enrolledCount;
		string instructorName;
		Student* enrolledStudents[30];
	public:
		Course(string code, string name, int hours, int capacity)
			: courseCode(code), courseName(name), creditHours(hours), maxCapacity(capacity), enrolledCount(0) {
		}

		// Encapsulation
		string getCourseCode() { return courseCode; }
		string getCourseName() { return courseName; }
		void setInstructor(string name) { instructorName = name; }

		// Operator overloading (==)
		bool operator==(Course& other) {
			return courseCode == other.courseCode;
		}

		// Friend function for << operator
		friend ostream& operator<<(ostream& out, Course& c) {
			out << "Course: " << c.courseName << " (" << c.courseCode << ") | Credits: " << c.creditHours;
			return out;
		}

		// Operator + to merge waiting lists
		string operator+(Course& other) {
			return "Merged: " + courseName + " with " + other.courseName;
		}

		bool enrollStudent(Student* s) {
			if (enrolledCount >= maxCapacity) {
				throw CapacityExceededException();
			}
			enrolledStudents[enrolledCount] = s;
			enrolledCount++;
			s->addCourse(courseName);
			return true;
		}

		void displayCourse() {
			cout << *this << " | Enrolled: " << enrolledCount << "/" << maxCapacity << endl;
		}
	};







	//member 1
	class LibraryItem {
	private:
		string itemID, title, author;
		int publicationYear;
	public:
		LibraryItem(string id, string t, string a, int year) : itemID(id), title(t), author(a), publicationYear(year) {}
		virtual ~LibraryItem() {}
		virtual void displayInfo() = 0;
		string getItemID() { return itemID; }
		string getTitle() { return title; }
		string getAuthor() { return author; }
		int getPublicationYear() { return publicationYear; }
	};
	class Book :public LibraryItem {
	private:
		string ISBN, genre;
		int copiesAvailable;
	public:
		Book(string id, string t, string a, int year, string isbn, string g, int copies)
			:LibraryItem(id, t, a, year), ISBN(isbn), genre(g), copiesAvailable(copies) {
		}
		void displayInfo() {
			cout << "Book: " << getTitle() << " | Author: " << getAuthor() << " | Year: " << getPublicationYear() << " | ISBN: " << ISBN << " | Genre: " << genre << " | Copies Available: " << copiesAvailable << endl;
		}
		string getISBN() { return ISBN; }
		string getGenre() { return genre; }
		int getCopiesAvailable() { return copiesAvailable; }
		 setCopiesAvailable(int copies) { copiesAvailable = copies; }
		 void checkOut() {
			 if (copiesAvailable > 0) {
				 copiesAvailable--;
			 }
			 else {
				 throw capacityExceeded();
			 }
		 
		 }
		 void returnItem() {
			 copiesAvailable++;
		 }
	};
	class Journal :public LibraryItem {
	private:
		string ISSN;
		int volume, issueNo;
		public
			Journal(string id, string t, string a, int year, string issn, int vol, int issue)
			:LibraryItem(id, t, a, year), ISSN(issn), volume(vol), issueNo(issue) {
		}
		void displayInfo() {
			cout << "Journal: " << getTitle() << " | Author: " << getAuthor() << " | Year: " << getPublicationYear() << " | ISSN: " << ISSN << " | Volume: " << volume << " | Issue No: " << issueNo << endl;
		}
		string getISSN() { return ISSN; }
		int getVolume() { return volume; }
		int getIssueNo() { return issueNo; }
		
	};
	struct issueItem {
		int rollNo;
		string itemID;
	};
	class Library{
	private:
		LibraryItem* catalog[10];
		int itemCount;
		issueItem issuedItems[15];
		int issuedCount;
	public:
		Library() : itemCount(0), issuedCount(0) {}

		~Library() {
			for (int i = 0;i < itemCount;i++) {
				delete catalog[i];
			}
		}
		void addItem(LibraryItem* item) {
			if (itemCount < 20) {
				catalog[itemCount] = item;
				itemCount++;
			}
		}
		void searchByTitle(string title) {
			for (int i = 0;i < itemCount;i++) {
				if (catalog[i]->getTitle() == title) {
					catalog[i]->displayInfo();
					return;
				}
			}
			cout << "Item not found." << endl;
		}
		void saveTofile(string filename) {
			ofstream outFile(filename);
			if (outFile.is_open()) {
				for (int i = 0;i < itemCount;i++) {
					outFile << catalog[i]->getItemID() << "," << catalog[i]->getTitle() << "," << catalog[i]->getAuthor() << "," << catalog[i]->getPublicationYear() << endl;
				}
				outFile.close();
			}
		}

		void loadFromFile(string filename) {
			ifstream inFile(filename);
			if (inFile.is_open()) {
				string line;
				while (getline(inFile, line)) {
					// Parse line and create LibraryItem objects
				}
				inFile.close();
			}
		}
		void issueItemToStudent(int rollNo, string itemID) {
			for (int i = 0;i < itemCount;i++) {
				if (catalog[i]->getItemID() == itemID) {
					try {
						catalog[i]->checkOut();
						issuedItems[issuedCount++] = { rollNo, itemID };
						cout << "Item issued successfully." << endl;
						return;
					}
					catch (capacityExceeded& e) {
						cout << e.what() << endl;
						return;
					}
				}
			}
			cout << "Item not found." << endl;
		}
		void displayIssuedItems() {
			for (int i = 0;i < issuedCount;i++) {
				cout << "Roll No: " << issuedItems[i].rollNo << " | Item ID: " << issuedItems[i].itemID << endl;
			}
		}
	};


	//member 2


	class Invoice {
	private:
		int invoiceID;
		string date;
		double totalAmount;
		static int invoiceCounter; // Static member

	public:
		Invoice(string d, double amount) : date(d), totalAmount(amount) {
			invoiceCounter++;
			invoiceID = invoiceCounter;
		}

		// Copy constructor
		Invoice(const Invoice& other) {
			invoiceID = other.invoiceID;
			date = other.date;
			totalAmount = other.totalAmount;
		}

		// Destructor
		~Invoice() {
			cout << "Invoice " << invoiceID << " destroyed" << endl;
		}

		static int getInvoiceCounter() {
			return invoiceCounter;
		}

		void display() {
			cout << "Invoice #" << invoiceID << " | Date: " << date << " | Total: Rs." << totalAmount << endl;
		}
	};

	int Invoice::invoiceCounter = 0;

	class FeeRecord {
	private:
		int studentRollNo;
		double semesterFee, hostelFee, libraryFine, totalPaid, balance;

	public:
		FeeRecord(int roll, double sFee, double hFee)
			: studentRollNo(roll), semesterFee(sFee), hostelFee(hFee), libraryFine(0), totalPaid(0), balance(sFee + hFee) {
		}

		// Copy constructor (Deep Copy)
		FeeRecord(const FeeRecord& other) {
			studentRollNo = other.studentRollNo;
			semesterFee = other.semesterFee;
			hostelFee = other.hostelFee;
			libraryFine = other.libraryFine;
			totalPaid = other.totalPaid;
			balance = other.balance;
		}

		// Copy assignment operator
		FeeRecord& operator=(const FeeRecord& other) {
			if (this != &other) {
				studentRollNo = other.studentRollNo;
				semesterFee = other.semesterFee;
				hostelFee = other.hostelFee;
				libraryFine = other.libraryFine;
				totalPaid = other.totalPaid;
				balance = other.balance;
			}
			return *this;
		}

		// Operator -= overloading
		void operator-=(double amount) {
			totalPaid += amount;
			balance -= amount;
			cout << "Payment of Rs." << amount << " recorded. Remaining balance: Rs." << balance << endl;
		}

		void addFine(double fine) {
			libraryFine = fine;
			balance += fine;
		}

		void display() {
			cout << "Student Roll: " << studentRollNo << " | Balance: Rs." << balance << " | Paid: Rs." << totalPaid << endl;
		}
	};




	//member 1

	class Accomodation {
	public:
		virtual void allocateRoom(int rollNo) = 0;
		virtual void vacateRoom(int roomNo) = 0;
	};
	class Reportable {
	public:
		virtual void generateReport() = 0;
	};
	class Room {
	private:
		int roomNo, floor;
		string type;
		int occupants[4];
		int occupantCount;
	public:
		Room(int rNo, int f, string t) : roomNo(rNo), floor(f), type(t), occupantCount(0) {
			for (int i = 0;i < 4;i++) {
				occupants[i] = -1; 
			}
		}
		void addOccupant(int rollNo) {
			if (occupantCount < 4) {
				occupants[occupantCount++] = rollNo;
			}
			else {
				throw capacityExceeded();
			}
		}
		void removeOccupant(int rollNo) {
			for (int i = 0;i < occupantCount;i++) {
				if (occupants[i] == rollNo) {
					for (int j = i;j < occupantCount - 1;j++) {
						occupants[j] = occupants[j + 1];
					}
					occupantCount--;
					return;
				}
			}
		}
		void displayInfo() {
			cout << "Room No: " << roomNo << " | Floor: " << floor << " | Type: " << type << " | Occupants: ";
			for (int i = 0;i < occupantCount;i++) {
				cout << occupants[i] << " ";
			}
			cout << endl;
		}
		class Hostel:
	private:
		string blockName;
		Room* rooms[10];
		int roomCount;
	public:
		Hostel(string name) : blockName(name), roomCount(0) {}
		void addRoom(Room* room) {
			if (roomCount < 10) {
				rooms[roomCount++] = room;
			}
		}
		void allocateRoom(int rollNo) {
			for (int i = 0;i < roomCount;i++) {
				try {
					rooms[i]->addOccupant(rollNo);
					cout << "Room allocated successfully." << endl;
					return;
				}
				catch (capacityExceeded& e) {
					continue;
				}
			}
			cout << "No available rooms." << endl;
		}
		void vacateRoom(int roomNo) {
			for (int i = 0;i < roomCount;i++) {
				if (rooms[i]->getRoomNo() == roomNo) {
					rooms[i]->removeOccupant(rollNo);
					cout << "Room vacated successfully." << endl;
					return;
				}
			}
			cout << "Room not found." << endl;
		}
		void displayRooms() {
			for (int i = 0;i < roomCount;i++) {
				rooms[i]->displayInfo();
			}
		}
		class HostelManager :public Accomodation, public Reportable {
		private:
			HostelBlock* blocks[3];
			int blockCount;
		public:
			HostelManager() : blockCount(0) {}
			void addBlock(HostelBlock* block) {
				if (blockCount < 3) {
					blocks[blockCount++] = block;
				}
			}
			void allocateRoom(int rollNo) {
				for (int i = 0;i < blockCount;i++) {
					blocks[i]->allocateRoom(rollNo);
				}
			}
			void vacateRoom(int roomNo) {
				for (int i = 0;i < blockCount;i++) {
					blocks[i]->vacateRoom(roomNo);
				}
			}
			void generateReport() {
				for (int i = 0;i < blockCount;i++) {
					blocks[i]->displayRooms();
				}
			}
		};


		//member 2

		class Utils {
		public:
			static string formatDate(int day, int month, int year) {
				// Simple concatenation without to_string
				string date = "";
				date += char(day / 10 + '0');
				date += char(day % 10 + '0');
				date += "/";
				date += char(month / 10 + '0');
				date += char(month % 10 + '0');
				date += "/";
				date += char(year / 1000 + '0');
				date += char((year / 100) % 10 + '0');
				date += char((year / 10) % 10 + '0');
				date += char(year % 10 + '0');
				return date;
			}

			static bool validateAge(int age) {
				return age >= 16 && age <= 100;
			}

			static void printLine() {
				cout << "========================================" << endl;
			}

			static int getIntInput(string prompt) {
				int value;
				cout << prompt;
				cin >> value;
				return value;
			}

			static string getStringInput(string prompt) {
				string value;
				cout << prompt;
				cin.ignore();
				getline(cin, value);
				return value;
			}

			static double getDoubleInput(string prompt) {
				double value;
				cout << prompt;
				cin >> value;
				return value;
			}
		};

		class Reports {
		public:
			static void generateCampusReport(Student* students[], int studentCount, Library* lib) {
				Utils::printLine();
				cout << "=== CAMPUS REPORT ===" << endl;
				Utils::printLine();

				cout << "\nSTUDENTS:" << endl;
				for (int i = 0; i < studentCount; i++) {
					students[i]->displayInfo();
				}

				cout << "\nLIBRARY STATUS:" << endl;
				lib->displayCatalog();

				Utils::printLine();
			}

			static void sortStudentsByGPA(Student* students[], int count) {
				for (int i = 0; i < count - 1; i++) {
					for (int j = 0; j < count - i - 1; j++) {
						if (students[j]->getGPA() < students[j + 1]->getGPA()) {
							Student* temp = students[j];
							students[j] = students[j + 1];
							students[j + 1] = temp;
						}
					}
				}
				cout << "Students sorted by GPA!" << endl;	
			}
		};	
			
		int main() {
			cout << "\n========== SMART CAMPUS MANAGEMENT SYSTEM ==========\n" << endl;

			// Arrays to store data
			Student* students[50];
			int studentCount = 0;

			Course* courses[20];
			int courseCount = 0;

			int choice;

			do {
				cout << "\n========== MAIN MENU ==========" << endl;
				cout << "1. Add Student" << endl;
				cout << "2. Add Faculty" << endl;
				cout << "3. Add Course" << endl;
				cout << "4. Enroll Student in Course" << endl;
				cout << "5. Library Management" << endl;
				cout << "6. Fee Management" << endl;
				cout << "7. Hostel Management" << endl;
				cout << "8. Generate Reports" << endl;
				cout << "9. Display All Students" << endl;
				cout << "0. Exit" << endl;
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice) {
				case 1: {
					// Add Student
					string name, cnic, contact;
					int age, rollNo, semester;
					double gpa;

					cout << "\n--- Add New Student ---" << endl;
					cout << "Enter Name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter CNIC: ";
					getline(cin, cnic);
					cout << "Enter Age: ";
					cin >> age;
					cout << "Enter Contact: ";
					cin.ignore();
					getline(cin, contact);
					cout << "Enter Roll No: ";
					cin >> rollNo;
					cout << "Enter Semester: ";
					cin >> semester;
					cout << "Enter GPA: ";
					cin >> gpa;

					students[studentCount] = new Student(name, cnic, age, contact, rollNo, semester, gpa);
					studentCount++;
					cout << "Student added successfully!" << endl;
					break;
				}

				case 2: {
					// Add Faculty
					string name, cnic, contact, department, designation;
					int age, empID;

					cout << "\n--- Add New Faculty ---" << endl;
					cout << "Enter Name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter CNIC: ";
					getline(cin, cnic);
					cout << "Enter Age: ";
					cin >> age;
					cout << "Enter Contact: ";
					cin.ignore();
					getline(cin, contact);
					cout << "Enter Employee ID: ";
					cin >> empID;
					cout << "Enter Department: ";
					cin.ignore();
					getline(cin, department);
					cout << "Enter Designation: ";
					getline(cin, designation);

					Faculty* f = new Faculty(name, cnic, age, contact, empID, department, designation);
					cout << "Faculty added successfully!" << endl;
					delete f; // Just for demo
					break;
				}

				case 3: {
					// Add Course
					string code, name;
					int hours, capacity;

					cout << "\n--- Add New Course ---" << endl;
					cout << "Enter Course Code: ";
					cin >> code;
					cout << "Enter Course Name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter Credit Hours: ";
					cin >> hours;
					cout << "Enter Max Capacity: ";
					cin >> capacity;

					courses[courseCount] = new Course(code, name, hours, capacity);
					courseCount++;
					cout << "Course added successfully!" << endl;
					break;
				}

				case 4: {
					// Enroll Student
					if (studentCount == 0 || courseCount == 0) {
						cout << "Please add students and courses first!" << endl;
						break;
					}

					cout << "\n--- Enroll Student in Course ---" << endl;
					cout << "Available Students:" << endl;
					for (int i = 0; i < studentCount; i++) {
						students[i]->displayInfo();
					}

					int rollNo;
					cout << "Enter Student Roll No: ";
					cin >> rollNo;

					Student* selectedStudent = NULL;
					for (int i = 0; i < studentCount; i++) {
						if (students[i]->getRollNo() == rollNo) {
							selectedStudent = students[i];
							break;
						}
					}

					if (selectedStudent == NULL) {
						cout << "Student not found!" << endl;
						break;
					}

					cout << "Available Courses:" << endl;
					for (int i = 0; i < courseCount; i++) {
						courses[i]->displayCourse();
					}

					string courseCode;
					cout << "Enter Course Code: ";
					cin >> courseCode;

					Course* selectedCourse = NULL;
					for (int i = 0; i < courseCount; i++) {
						if (courses[i]->getCourseCode() == courseCode) {
							selectedCourse = courses[i];
							break;
						}
					}

					if (selectedCourse == NULL) {
						cout << "Course not found!" << endl;
						break;
					}

					try {
						if (selectedCourse->enrollStudent(selectedStudent)) {
							cout << "Student enrolled successfully!" << endl;
						}
					}
					catch (CapacityExceededException e) {
						cout << e.what() << endl;
					}
					break;
				}

				case 5: {
					// Library Management
					Library lib;
					lib.addItem(new Book("B001", "C++ Programming", "Stroustrup", 2018, "978-0321", "Technical", 3));
					lib.addItem(new Book("B002", "Data Structures", "Weiss", 2015, "978-0321", "Academic", 2));
					lib.displayCatalog();

					string title;
					cout << "\nEnter book title to search: ";
					cin.ignore();
					getline(cin, title);
					lib.searchByTitle(title);
					break;
				}

				case 6: {
					// Fee Management
					if (studentCount == 0) {
						cout << "No students available!" << endl;
						break;
					}

					int rollNo;
					cout << "Enter Student Roll No: ";
					cin >> rollNo;

					FeeRecord fee(rollNo, 50000, 30000);
					fee.display();

					double payment;
					cout << "Enter payment amount: ";
					cin >> payment;
					fee -= payment;

					Invoice inv("15-12-2024", payment);
					inv.display();
					break;
				}

				case 7: {
					// Hostel Management
					HostelBlock block("Azadi Block");
					Room r1(101, 1, "double");
					Room r2(102, 1, "single");
					block.addRoom(&r1);
					block.addRoom(&r2);

					HostelManager hm;
					hm.addBlock(&block);

					int rollNo;
					cout << "Enter Student Roll No for hostel allocation: ";
					cin >> rollNo;
					hm.allocateRoom(rollNo);
					hm.generateReport();
					break;
				}

				case 8: {
					// Generate Reports
					if (studentCount == 0) {
						cout << "No students to display!" << endl;
						break;
					}

					Library lib;
					Reports::generateCampusReport(students, studentCount, &lib);
					Reports::sortStudentsByGPA(students, studentCount);
					break;
				}

				case 9: {
					// Display All Students
					if (studentCount == 0) {
						cout << "No students added yet!" << endl;
					}
					else {
						cout << "\n=== ALL STUDENTS ===" << endl;
						for (int i = 0; i < studentCount; i++) {
							students[i]->displayInfo();
						}
					}
					break;
				}

				case 0:
					cout << "Exiting system..." << endl;
					break;

				default:
					cout << "Invalid choice!" << endl;
				}

			} while (choice != 0);

			// Cleanup
			for (int i = 0; i < studentCount; i++) {
				delete students[i];
			}
			for (int i = 0; i < courseCount; i++) {
				delete courses[i];
			}

			cout << "\n========== PROGRAM END ==========" << endl;

			return 0;
		}	