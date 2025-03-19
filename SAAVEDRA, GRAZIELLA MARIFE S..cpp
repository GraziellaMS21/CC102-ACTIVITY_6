#include <iostream>
using namespace std;

struct Student{
    int studentID;
    string firstN;
    string lastN;
    string course;
    string prevSemGPA;
};

void addStudent(Student p[], int counter){
    cout<<"-----ADD STUDENT DATA-----"<<endl;
    cout<<"Enter Student ID: ";
    cin>>p[counter].studentID;
    cout<<"Enter Student First Name: ";
    cin>>p[counter].firstN;
    cout<<"Enter Student Last Name: ";
    cin>>p[counter].lastN;
    cout<<"Enter Course: ";
    cin>>p[counter].course;
    cout<<"Enter Previous Semestral GPA: ";
    cin>>p[counter].prevSemGPA;
}

void validateID(Student p[], int counter) {
    if (counter > 0) {
        while (true) {
            bool isDuplicate = false;
            for (int i = 0; i < counter; i++) {
                if (p[counter].studentID == p[i].studentID) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) break;
            cout << "This ID is Invalid, Please Try Again!\n" << endl;
            cout << "Enter Student ID: ";
            cin >> p[counter].studentID;
        }
    }
}

void searchStudent(Student p[], int counter, int id) {
    for (int i = 0; i < counter; i++) {
        if (id == p[i].studentID) {
            cout << "\n======================" << endl;
            cout << "Student ID: " << p[i].studentID << endl;
            cout << "Student First Name: " << p[i].firstN << endl;
            cout << "Student Last Name: " << p[i].lastN << endl;
            cout << "Student Course: " << p[i].course << endl;
            cout << "Student Previous Semestral GPA: " << p[i].prevSemGPA << endl;
            cout << "======================" << endl;
            return;
        }
    }
    cout << "\nStudent not found.\n" << endl;

}

void validateEditID(Student p[], int counter, int index) {
    if (counter > 0) {
        while (true) {
            bool isDuplicate = false;
            for (int i = 0; i < counter; i++) {
                if (p[index].studentID == p[i].studentID && i != index) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) break;
            cout << "This ID is Invalid, Please Try Again!\n" << endl;
            cout << "Enter Student ID: ";
            cin >> p[index].studentID;
        }
    }
}

void editStudent(Student p[], int counter, int id) {
    for (int i = 0; i < counter; i++) {
        if (id == p[i].studentID) {
            cout << "Enter Student ID: ";
            cin >> p[i].studentID;
            validateEditID(p, counter, i);
            cout << "Enter Student First Name: ";
            cin >> p[i].firstN;
            cout << "Enter Student Last Name: ";
            cin >> p[i].lastN;
            cout << "Enter Course: ";
            cin >> p[i].course;
            cout << "Enter Previous Semestral GPA: ";
            cin >> p[i].prevSemGPA;
        }
    }
    cout<<"\nStudent Data Edited Successfully!\n"<<endl;

}

void removeStudent(Student p[], int counter, int id){
    for (int i=0; i<counter-1; i++){
        if (id == p[i].studentID){
            p[i] = p[i+1];
        }
    }
    cout<<"\nStudent Removed Successfully!"<<endl;
}


void viewStudent(Student p[], int counter){
    for (int i=0; i<counter; i++){
        cout<<"\n======================"<<endl;
        cout<<"Student ID: "<<p[i].studentID<<endl;
        cout<<"Student First Name: "<<p[i].firstN<<endl;
        cout<<"Student Last Name: "<<p[i].lastN<<endl;
        cout<<"Student Course: "<<p[i].course<<endl;
        cout<<"Student Previous Semestral GPA: "<<p[i].prevSemGPA<<endl;
        cout<<"======================"<<endl;
    }
}

void viewStudentAlphabetical(Student p[], int counter){
    for(int i=0; i<counter; i++){
        for(int i=0; i<counter-1; i++){
            for(int j=0; j<counter-i-1; j++){
                if (p[j].lastN> p[j+1].lastN){
                Student temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                }
            }
        }
    }
    viewStudent(p, counter);
}

void viewStudentGPA(Student p[], int counter){
    for(int i=0; i<counter-1; i++){
        for(int j=0; j<counter-i-1; j++){
            if (p[j].prevSemGPA > p[j+1].prevSemGPA){
            Student temp = p[j];
            p[j] = p[j+1];
            p[j+1] = temp;
            }
        }
    }
    viewStudent(p, counter);
}

int main(){
    int opt;
    int n=0;
    Student p[10000];
    int counter=0;

    while(true){
        cout<<"=====STUDENT RECORD MENU====="<<endl;
        cout<<"1] Add Student"<<endl;
        cout<<"2] Edit Student"<<endl;
        cout<<"3] Delete Student"<<endl;
        cout<<"4] View Student"<<endl;
        cout<<"5] Exit Program"<<endl;
        cout<<"Enter Option: ";
        cin>>opt;
        system("cls");

        switch(opt){
            case 1:
                addStudent(p, counter);
                validateID(p, counter);
                counter++;
                cout<<"\nStudent Was Successfully Added!\n"<<endl;
            break;

            case 2:
                if(counter==0){
                    cout<<"\nThe Student List is Empty!\n"<<endl;
                }
                else{
                    int id;
                    cout<<"-----EDIT STUDENT DATA-----"<<endl;
                    cout<<"Enter Student ID to Edit: ";
                    cin>>id;
                    searchStudent(p, counter, id);
                    cout<<endl;
                    editStudent(p, counter, id);
                }
            break;

            case 3:
                if(counter==0){
                    cout<<"\nThe Student List is Empty!"<<endl;
                }
                else{
                    int id;
                    string ans;
                    cout<<"\n-----DELETE STUDENT DATA-----"<<endl;
                    cout<<"Enter Student ID: ";
                    cin>>id;

                    searchStudent(p, counter, id);
                    cout<<"\nDelete?";
                    cin>> ans;
                    if(tolower(ans[0]) == 'y'){
                        removeStudent(p, counter, id);
                        counter--;
                        }
                    else
                        break;
                }
            break;

            case 4:
                int optSort;
                do{
                    system("cls");
                    cout<<"-----VIEWING OPTIONS-----"<<endl;
                    cout<<"1] Alphabetically"<<endl;
                    cout<<"2] GPA"<<endl;
                    cout<<"3] Return"<<endl;
                    cout<<"Enter Option: ";
                    cin>>optSort;

                    switch(optSort){
                        case 1:
                            {
                                viewStudentAlphabetical(p, counter);
                                string ans;
                                cout<<"\nReturn to Viewing Options? (Yes / No): ";
                                cin>>ans;
                                if(tolower(ans[0]) == 'n'){
                                   cout<<"\nThank You for Using my Program!"<<endl;
                                   return 0;
                                }
                            }
                        break;

                        case 2:
                                viewStudentGPA(p, counter);
                                string ans;
                                cout<<"\nReturn to Viewing Options? (Yes / No): ";
                                cin>>ans;
                                if(tolower(ans[0]) == 'n'){
                                   cout<<"\nThank You for Using my Program!"<<endl;
                                   return 0;
                                }
                        break;
                    }
                }while(optSort != 3);
            cout<<endl;
            break;

            case 5:
                cout<<"\nThank You for Using my Program!"<<endl;
                return 0;
        }
    }
    return 0;
}
