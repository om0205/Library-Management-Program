#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
using namespace std;
class Library
{
public:
    char name[50],aname[50],id[50];
    int p,q;
    void student();
    void librarian();
    void home();
    void pass();
    void booklist(int);
    int branch(int);
    void input();
    void searchb();
    void modify();
    void issue();
};
int Library::branch(int i)
{
    system("cls");
    int c;
      cout<<"\n\t\t>>Please Choose a Branch :\n";
      cout<<"\n\t\t1.FIRST YEAR\n\n\t\t2.CS\n\n\t\t3.ETC\n\n\t\t4.CIVIL\n\n\t\t5.MECHANICAL\n\n\t\t6.GO TO MENU\n";
      cout<<"\n\t\tEnter your choice : ";
      cin>>c;
      switch(c)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: system("cls");
                  if(i==1)
                  student();
                  else
                    librarian();
          default : cout<<"\n\t\tPlease enter correct option !";
                    getch();
                    system("cls");
                    branch(i);
        }
}
void Library::student()
{
    int i;
    cout<<"\n\t!!!!!!!!!!!! WELCOME STUDENT !!!!!!!!!!!!\n";
    cout<<"\n\t\t>>Choose One Option<< \n";
    cout<<"\n\t\t1.List of Books\n\n\t\t2.Search a Book\n\n\t\t3.Go to Main Menu\n\n\t\t4.Quit\n";
    cout<<"\n\t\tEnter Your Choice : "; cin>>i;
    if(i==1)
        booklist(1);
    else if(i==2)
      {//  searchb(1);
      }
    else if(i==3)
        {
            system("cls");
            home();
        }
        else if(i==4)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option !";
            getch();
            system("cls");
            student();
        }
}
void Library::home()
{
    int i;
    cout<<"\n\t!!!!!!!!!!!!!!! LIBRARY MANAGEMENT !!!!!!!!!!!!!!!\n";
    cout<<"\n\t\t>>Please Choose Login Option<< \n";
    cout<<"\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Quit\n";
    cout<<"\n\t\tEnter your choice : "; cin>>i;
    if(i==1)
        {
            system("cls");
            student();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tPlease enter correct option !";
            getch();
            system("cls");
           home();
        }
}
void Library::pass()
{
    int c=0,z=0;
    cin.ignore();
    char pas[20], pas1[20]="pass";
    cout<<"\n\t\tENTER PASSWORD: ";
    while((c=getch())!=13)
    {
      pas[z++]=c;
      cout<<"*";
    }
    pas[z]='\0';
    /*cout<<"\n\t\tEnter Password : ";cin.getline(pas,20);*/
    if(strcmp(pas,pas1)==0)
    {
        cout<<"\n\t\tWelcome Librarian!";
        getch();
        librarian();
    }
    else
    {
        cout<<"\n\tWrong Password try again...";
        getch();
        system("cls");
        pass();
    }

}
void Library::librarian()
{
        system("cls");
        int i;
        cout<<"\n\t!!!!!!!!!!!! WELCOME LIBRARIAN !!!!!!!!!!!!\n";
        cout<<"\n\t\t>>Please Choose One Option<<\n";
        cout<<"\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Add Book\n\n\t\t4.Issue Book\n\n\t\t5.Go to main menu\n\n\t\t6.Close Application\n";
        cout<<"\n\t\tEnter your choice : ";
        cin>>i;
        switch(i)
        {
            case 1:booklist(2);
                     break;
          /* case 2:searchb(2);
                     break;*/
            case 3:modify();
                     break;
           /* case 4:issue();
                     break; */
            case 5:system("cls");
                     home();
                     break;
            case 6:exit(0);
            default:cout<<"\n\t\tPlease enter correct option !";
            getch();
            system("cls");
            librarian();
        }
}
void Library::booklist(int i)
{
    int b;
    string data;
    b=branch(i);

    ifstream book;
    switch(b)
    {
        case 1: book.open("FYEAR.txt");
                break;
        case 2: book.open("CS.txt");
                break;
        case 3: book.open("ETC.txt");
                break;
        case 4: book.open("CIVIL.txt");
                break;
        case 5: book.open("MECH.txt");
                break;
    }
    system("cls");
    while(!book.eof())
    {
        while(getline(book,data))
        {
            cout<<"\n\t\t"<<data;
        }
    }
    book.close();
    cout<<"\n\t\tEnter to continue....";
    getch();
    if(i==1)
        student();
    else
        librarian();

}
/*void Library::searchb()
{

}*/
void Library::modify()
{
    system("cls");
    int b;
    b=branch(0);
    system("cls");
    string datam;
    ofstream bookm;
    switch(b)
    {
        case 1: bookm.open("FYEAR.txt",ios::app);
                break;
        case 2: bookm.open("CS.txt",ios::app);
                break;
        case 3: bookm.open("ETC.txt",ios::app);
                break;
        case 4: bookm.open("CIVIL.txt",ios::app);
                break;
        case 5: bookm.open("MECH.txt",ios::app);
                break;
    }
    cin.ignore();
    input();
    bookm<<"\t"<<name<<"\t"<<"\t"<<aname<<"\t"<<"\t"<<id<<"\t"<<"\t"<<p<<"\t"<<"\t"<<q<<endl;
    bookm.close();
    cout<<"\n\t\tBook added successfully.....";
    getch();
    librarian();
}
/*
void Library::issue()
{

}
*/
void Library::input()
{
    cout<<"\n";
    cout<<"\n\t\tBook Name : "; cin.getline(name,50);
    cout<<"\n\t\tAuthor Name : "; cin.getline(aname,50);
    cout<<"\n\t\tBook ID : "; cin.getline(id,50);
    cout<<"\n\t\tBook Price : "; cin>>p;
    cout<<"\n\t\tBook Quantity : "; cin>>q;

}


int main()
{
    Library lib;
    lib.home();
    return 0;
}
