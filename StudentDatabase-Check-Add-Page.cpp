#include <iostream>
using namespace std;
struct Student
{
    Student* next = NULL;
    Student* prev = NULL;
    string firstName,lastName,sex,course,year,standing;
};

void MainMenu(int&); 
void AddStudentRecord(Student*&, Student*&, Student*&, int&);
void DisplayStudentRecord(int, Student*, Student*);
Student* AddNewStudent();

int main() 
{
    int choice, playerToDelete, studentInput = 0;
    Student* head = NULL,* tail = NULL,* temp = NULL;

    do {
        MainMenu(choice);
        switch (choice) {
            case 1:
                AddStudentRecord(head, tail, temp, studentInput);
                break;
                case 2:
                	system("cls");
                    DisplayStudentRecord(studentInput, head, temp);
                    system ("pause");
                    break;
                    case 3:
                    return 0;
                    break;
                default:
                break;
        }
    } while (true);

    return 0;
}

void MainMenu(int & choice) 
{
	system ("cls");
    cout << "-----------------------------------\n";
    cout << "\tMain Menu\n";
    cout << "-----------------------------------\n";
    cout << "1. Add a new record\n";
    cout << "2. Check a record list\n";
    cout << "3. Exit\n"<< endl;
    cout << "Enter your choice: ";
    cin >> choice;
}

Student* AddNewStudent() {
	system ("cls");
    Student* StudentInformaton;
    StudentInformaton = new Student;
    cout << "Student Information Form\n\n";
    cout << "Enter First Name: ";
    cin >> StudentInformaton -> firstName;
    cout << "Enter Last Name: ";
    cin >> StudentInformaton -> lastName;
    cout << "Enter Student Course: ";
    cin >> StudentInformaton -> course;
    cout << "Enter Student Year: ";
    cin >> StudentInformaton -> year;
    return StudentInformaton;
}

void AddStudentRecord(Student* & head, Student* & tail, Student* & temp, int & studentInput) {
    temp = AddNewStudent();
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
    studentInput++;
}
                    void DisplayStudentRecord(int studentInput, Student* head, Student* temp) {
                        cout << "Student Record List\n";
                        if (studentInput == 0) {
                            cout << "No records found\n";
                        } else {
                            temp = head;
                            while (temp != NULL) {
                                cout << "First Name: " << temp->firstName << endl;
                                cout << "Last Name: " << temp->lastName << endl;
                                cout << "Course: " << temp->course << endl;
                                if (!temp->year.empty()) {
                                    cout << "Year: " << temp->year << endl;
                                }
                                cout << "-----------------------------------\n";
                                cout << "1. Next\n";
                                cout << "2. Previous\n";
                                cout << "3. Exit\n";
                                int choice;
                                cout << "Enter your choice: ";
                                cin >> choice;
                                system("cls");
                                if (choice == 1) {
                                    if (temp->next == NULL) {
                                    } else {
                                        temp = temp->next;
                                    }
                                } else if (choice == 2) {
                                    if (temp->prev == NULL) {
                                    } else {
                                        temp = temp->prev;
                                    }
                                } else if (choice == 3) {
                                    break;
                                } else {
                                    cout << "Invalid choice\n";
                                }
                            }
                        }
                    }
