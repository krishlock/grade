#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <cstring>
using namespace std;
class student
{
public:
    int rollno;
    char name[50];
    int fs_marks, st_marks, web_marks, dm_marks, scm_marks, fslab_marks, stlab_marks, apklab_marks;
    float per;
    char grade;
    int std;
    void calculate();
    void getdata();
    void showdata();
    void unpack();
    void show_tabular();
};
struct studentDet
{
    char rollno[10];
    char name[50];
    char fs_marks[3], st_marks[3], web_marks[3], dm_marks[3], scm_marks[3], fslab_marks[3], stlab_marks[3], apklab_marks[3];
    char per[5];
    char grade[1];
    char std[3];
};
student st;
void student::calculate()
{
    int fs1 = (((fs_marks / 10) + 1) * 4);
    int st1 = (((st_marks / 10) + 1) * 4);
    int web1 = (((web_marks / 10) + 1) * 4);
    int dm1 = (((dm_marks / 10) + 1) * 3);
    int scm1 = (((scm_marks / 10) + 1) * 3);
    int fslab1 = (((fslab_marks / 10) + 1) * 2);
    int stlab1 = (((stlab_marks / 10) + 1) * 2);
    int apklab1 = (((apklab_marks / 10) + 1) * 2);
    per = (fs1 + st1 + web1 + dm1 + scm1 + stlab1 + fslab1 + apklab1) / 24.00;
    if (per >= 9)
        grade = 'S';
    else if (per >= 8)
        grade = 'A';
    else if (per >= 7)
        grade = 'B';
    else if (per >= 6)
        grade = 'C';
    else if (per >= 5)
        grade = 'D';
    else
        grade = 'F';
}

//input from user
// 1
void student::getdata()
{
    system("color 3F");
    cout << "\t\t\t  -------------------------------"
         << "\n";
    cout << "\t\t\t     ENTER THE STUDENT DETAILS"
         << "\n";
    cout << "\t\t\t  -------------------------------"
         << "\n\n";
    cout << "\t\tNAME OF THE STUDENT    : ";
    cin >> name;
    cout << "\t\tROLL NUMBER            : ";
    cin >> rollno;
    cout << "\t\t\t  -----------------------------"
         << "\n";
    cout << "\t\t\t     ENTER THE SUBJECT MARKS"
         << "\n";
    cout << "\t\t\t  -----------------------------"
         << "\n\n";
    cout << "\t\t\t       FILE STRUCTURES       : ";
    cin >> fs_marks;
    cout << "\t\t\t       SOFTWARE TESTING      : ";
    cin >> st_marks;
    cout << "\t\t\t       WEB TECHNOLOGY        : ";
    cin >> web_marks;
    cout << "\t\t\t       DATA MINING           : ";
    cin >> dm_marks;
    cout << "\t\t\t       SUPPLY CHAIN          : ";
    cin >> scm_marks;
    cout << "\t\t\t       FILE STRUCTURES LAB   : ";
    cin >> fslab_marks;
    cout << "\t\t\t       SOFTWARE TESTING LAB  : ";
    cin >> stlab_marks;
    cout << "\t\t\t       MOB APP DEVELOPMENT   : ";
    cin >> apklab_marks;
    calculate();
}

//output from user

//4
void student::showdata()
{
    system("color F1");
    cout << "----------------------------------------";
    cout << "---------------------------------------\n";
    cout << "                        CANARA ENGINEERING COLLEGE\n\n";
    cout << "                             STUDENT GRADE POINT\n";
    cout << "----------------------------------------";
    cout << "---------------------------------------\n\n";
    cout << "                         ------------------------\n";
    cout << "                             PERSONAL DETAILS\n";
    cout << "                         ------------------------\n\n";
    cout << "\t\t\tNAME: " << name << "\t  ";
    cout << "ROLL NO: " << rollno << "\n\n";
    cout << "                        ----------------------------\n";
    cout << "                            ACADEMIC PERFORMANCE\n";
    cout << "                        ----------------------------\n\n";
    cout << "                 ---------------------------------------\n";
    cout << "                                  MARKS\n";
    cout << "                 ---------------------------------------\n";
    cout << "\t\t  FILE STRUCTURES\t\t" << fs_marks << "\n";
    cout << "\t\t  SOFTWARE TESTING\t\t" << st_marks << "\n";
    cout << "\t\t  WEB TECHNOLOGY\t\t" << web_marks << "\n";
    cout << "\t\t  DATA MINING\t\t\t" << scm_marks << "\n";
    cout << "\t\t  SUPPLY CHAIN\t\t\t" << dm_marks << "\n";
    cout << "\t\t  FILE STRUCTURE LAB\t\t" << fslab_marks << "\n";
    cout << "\t\t  SOFTWARE TESTING LAB\t\t" << stlab_marks << "\n";
    cout << "\t\t  MOB APP DEVELOPMENT\t\t" << apklab_marks << "\n";
    cout << "                -------------------        ------------\n";
    cout << "                 GRADE POINT: " << fixed << setprecision(2) << per << "           ";
    cout << "GRADE: " << grade << "\n";
    cout << "                -------------------        ------------\n\n";
}

void student::show_tabular()
{
    cout << st.rollno << "\t  " << st.name << "\t\t" << st.fs_marks << " \t" << st.st_marks << " \t" << st.web_marks << " \t" << st.dm_marks << " \t" << st.scm_marks << " \t" << st.fslab_marks << " \t" << st.stlab_marks << " \t" << st.apklab_marks << " \t" << st.per << " \t" << st.grade << "\n";
}

fstream fp;

//2
void write_student()
{
    fp.open("student.txt", ios::out | ios::app);
    st.getdata();
    fp << st.rollno << ' ' << st.name << ' ' << st.fs_marks << ' ' << st.st_marks << ' ' << st.web_marks << ' ' << st.dm_marks << ' ' << st.scm_marks << ' ' << st.fslab_marks << ' ' << st.stlab_marks << ' ' << st.apklab_marks << ' ' << st.per << ' ' << st.grade << '\n';

    fp.close();
    cout << "\n\nstudent record Has Been Created ";
    _getch();
}

//3
void display_all()
{
    system("cls");
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("student.txt", ios::in);
    while (fp >> st.rollno >> st.name >> st.fs_marks >> st.st_marks >> st.web_marks >> st.dm_marks >> st.scm_marks >> st.fslab_marks >> st.stlab_marks >> st.apklab_marks >> st.per >> st.grade)
    {
        st.showdata();
        cout << "\n\n====================================\n";
        // Sleep(2000);
        cin.ignore();
    }
    fp.close();
}
void display_sp(int n)
{
    int flag = 0;
    fp.open("student.txt", ios::in);
    while (fp >> st.rollno >> st.name >> st.fs_marks >> st.st_marks >> st.web_marks >> st.dm_marks >> st.scm_marks >> st.fslab_marks >> st.stlab_marks >> st.apklab_marks >> st.per >> st.grade)
    {
        if (st.rollno == n)
        {
            system("cls");
            st.showdata();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nrecord does not exist";
    _getch();
}

//5
void modify_student()
{
    struct studentDet s1[100];
    student ts[100];
    std::fstream f1;
    int i = 0, k, no;
    f1.open("student.txt", std::ios::in);
    while (!f1.eof())
    {
        f1.getline(s1[i].rollno, 10, ' ');
        f1.getline(s1[i].name, 50, ' ');
        f1.getline(s1[i].fs_marks, 10, ' ');
        f1.getline(s1[i].st_marks, 10, ' ');
        f1.getline(s1[i].web_marks, 10, ' ');
        f1.getline(s1[i].dm_marks, 10, ' ');
        f1.getline(s1[i].scm_marks, 10, ' ');
        f1.getline(s1[i].fslab_marks, 10, ' ');
        f1.getline(s1[i].stlab_marks, 10, ' ');
        f1.getline(s1[i].apklab_marks, 10, ' ');
        f1.getline(s1[i].per, 10, ' ');
        f1.getline(s1[i].grade, 10, '\n');
        cout << s1[i].rollno << " " << s1[i].name << " " << s1[i].fs_marks << " " << s1[i].st_marks << " " << s1[i].web_marks << " " << s1[i].dm_marks << " " << s1[i].scm_marks << " " << s1[i].fslab_marks << " " << s1[i].stlab_marks << " " << s1[i].apklab_marks << " " << s1[i].per << " " << s1[i].grade << "\n";

        ts[i].rollno = atoi(s1[i].rollno);
        ts[i].fs_marks = atoi(s1[i].fs_marks);
        ts[i].st_marks = atoi(s1[i].st_marks);
        ts[i].web_marks = atoi(s1[i].web_marks);
        ts[i].dm_marks = atoi(s1[i].dm_marks);
        ts[i].scm_marks = atoi(s1[i].scm_marks);
        ts[i].fslab_marks = atoi(s1[i].fslab_marks);
        ts[i].stlab_marks = atoi(s1[i].stlab_marks);
        ts[i].apklab_marks = atoi(s1[i].apklab_marks);
        strcpy(ts[i].name, s1[i].name);
        ts[i].grade = s1[i].grade[0];
        ts[i].per = atof(s1[i].per);
        i++;
    }
    int count = i;
    cout << "\n\n\tPlease Enter The roll number of student : ";
    cin >> no;
    for (int i = count - 1; i >= 0; i--)
    {
        if (ts[i].rollno == no)
        {
            ts[i].showdata();
            cout << "\nPlease Enter The New Details of student" << endl;
            ts[i].getdata();
            //  cout<<ts[i].rollno<<ts[i].name<<ts[i].fs_marks<<ts[i].st_marks<<ts[i].web_marks<<ts[i].dm_marks<<ts[i].scm_marks<<ts[i].fslab_marks<<ts[i].stlab_marks<<ts[i].apklab_marks<<ts[i].per<<ts[i].grade<<"\n";
        }
    }
    f1.close();
    f1.open("temp.txt", ios::out);
    for (int i = 0; i < count - 1; i++)
    {
        f1 << ts[i].rollno << ' ' << ts[i].name << ' ' << ts[i].fs_marks << ' ' << ts[i].st_marks << ' ' << ts[i].web_marks << ' ' << ts[i].dm_marks << ' ' << ts[i].scm_marks << ' ' << ts[i].fslab_marks << ' ' << ts[i].stlab_marks << ' ' << ts[i].apklab_marks << ' ' << ts[i].per << ' ' << ts[i].grade << '\n';
    }
    f1.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
    remove("temp.txt");
    cout << "RECORD UPDATED !!!";
    _getch();
}
void delete_student()
{
    int no;
    int flag = 0;
    system("cls");
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The roll number of student You Want To Delete : ";
    cin >> no;
    fp.open("student.txt", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.txt", ios::out);
    fp.seekg(0, ios::beg);
    while (fp >> st.rollno >> st.name >> st.fs_marks >> st.st_marks >> st.web_marks >> st.dm_marks >> st.scm_marks >> st.fslab_marks >> st.stlab_marks >> st.apklab_marks >> st.per >> st.grade)
    {
        if (st.rollno != no)
        {
            fp2 << st.rollno << ' ' << st.name << ' ' << st.fs_marks << ' ' << st.st_marks << ' ' << st.web_marks << ' '
                << st.dm_marks << ' ' << st.scm_marks << ' ' << st.fslab_marks << ' ' << st.stlab_marks << ' ' << st.apklab_marks << ' ' << st.per << ' ' << st.grade << '\n';
        }
        else
            flag = 1;
    }
    fp2.close();
    fp.close();
    remove("student.txt");
    rename("Temp.txt", "student.txt");
    if (flag == 1)
    {
        cout << "\n\n\tRecord Deleted ..";
        _getch();
    }
    else
    {
        cout << "\n\n\tRecord not found ..";
        _getch();
    }
}
void class_result()
{
    system("cls");
    fp.open("student.txt", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
        cout << "\n\n\n Program is closing ....";
        _getch();
        exit(0);
    }
    cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    cout << "====================================================================================================\n";
    cout << "Roll No.  Name          FS\tST \tWEB \tDM \tSCM \tFSLAB \tSTLAB \tMobAPP \tSGPA \tGrade\n";
    cout << "====================================================================================================\n";
    while (fp >> st.rollno >> st.name >> st.fs_marks >> st.st_marks >> st.web_marks >> st.dm_marks >> st.scm_marks >> st.fslab_marks >> st.stlab_marks >> st.apklab_marks >> st.per >> st.grade)
    {
        st.show_tabular();
    }
    fp.close();
    _getch();
}
void result()
{
    int ans, rno;
    char ch;
    system("cls");
    cout << "\n\n\nRESULT MENU";
    cout << "\n\n\n1. Class Result\n\n2. Student Report Card\n\n3. Back to Main Menu";
    cout << "\n\n\nEnter Choice (1/2)?  ";
    cin >> ans;
    switch (ans)
    {
    case 1:
        class_result();
        break;
    case 2:
    {
        char qn;
        do
        {
            system("cls");
            cout << "\n\nEnter Roll Number Of Student : ";
            cin >> rno;
            display_sp(rno);
            cout << "\n\nDo you want to See More Result (y/n)?  ";
            cin >> qn;
        } while (qn == 'y' || qn == 'Y');
        break;
    }
    case 3:
        break;
    default:
        cout << "\a";
    }
}
void intro()
{
    system("color b");
    system("cls");
    cout << "\n\n\n\t\t\t\t\tGRADE MANAGEMENT PROJECT";
    cout << "\n\n\t\t\t\t\tMADE BY : Krishna Rao\n\t\t\t\t\t\t  Neha Mudhol\n";
    _getch();
}
int entry_menu()
{
    system("cls");
    char ch2;
    cout << "\n\n\n\tENTRY MENU";
    cout << "\n\n\t1.CREATE STUDENT RECORD";
    cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
    cout << "\n\n\t3.SEARCH STUDENT RECORD ";
    cout << "\n\n\t4.MODIFY STUDENT RECORD";
    cout << "\n\n\t5.DELETE STUDENT RECORD";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    ch2 = getchar();
    switch (ch2)
    {
    case '1':
        system("cls");
        write_student();
        break;
    case '2':
        display_all();

        break;
    case '3':
        int num;
        system("cls");
        cout << "\n\n\tPlease Enter The roll number ";
        cin >> num;
        display_sp(num);
        break;
    case '4':
        modify_student();
        break;
    case '5':
        delete_student();
        break;
    case '6':
        break;
    default:
        cout << "\a";
        entry_menu();
    }
}
int main()
{
    char ch;
    system("color b");
    intro();
    do
    {
        cin.clear();
        fflush(stdin);
        system("cls");
        system("color b");
        cout << "\n\n\n\t\t===> 1. RESULT MENU\n";
        Sleep(250);
        cout << "\t\t===> 2. ENTRY/EDIT MENU\n";
        Sleep(250);
        cout << "\t\t===> 3. EXIT\n";
        Sleep(250);
        cout << "\n\n\n\t\tPLEASE SELECT YOUR OPTION (1-3) ";
        Sleep(250);
        ch = getchar();
        switch (ch)
        {
        case '1':
            system("cls");
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            system("cls");
            cout << endl
                 << endl;
            for (int i = 0; i < 25; i++)
            {
                cout << "*";
                Sleep(40);
            }
            for (int i = 0; i < 9; i++)
            {
                cout << "!";
                Sleep(50);
            }
            cout << "THANK YOU";
            for (int i = 0; i < 9; i++)
            {
                cout << "!";
                Sleep(40);
            }
            for (int i = 0; i < 25; i++)
            {
                cout << "*";
                Sleep(40);
            }
            cout << endl
                 << endl;
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
}
