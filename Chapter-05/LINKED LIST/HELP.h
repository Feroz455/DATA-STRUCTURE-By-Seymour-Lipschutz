#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void PRINT_LINE(char ch);
void PRINT_LINE(string ch);
void PRINT_LINE(int wirdth = 50, char ch = '_');


void PRINT_LINE(int wirdth, char ch)
{
    while (wirdth-- != 0)
    {
        cout << ch;
    }
    cout << "\n";   
}
void PRINT_LINE(char ch)
{
    int wirdth = 50;
    while (wirdth-- != 0)
    {
        cout << ch;
    }
    cout << "\n";   
}
void PRINT_LINE(string ch)
{
    int wirdth = 50;
    while (wirdth-- != 0)
    {
        cout << ch;
    }
    cout << "\n";   
}

void OPTION()
{
    int i = 1;
    int check = 0;
    cout << "**ENTER YOUR CHOISE**\n";
    cout << setw(3) << (check+=i) << ". INPUT RECORD \n";
    cout << setw(3) << (check+=i) << ". SHOW RECORD\n";
    cout << setw(3) << (check+=i) << ". DELETE ALL RECORD\n";
    cout << setw(3) << (check+=i) << ". INSERT AN ITEM\n";
    cout << setw(3) << (check+=i) << ". DELETE AN ITEM\n";
    cout << setw(3) << (check+=i) << ". SHOW NUMBER OF ELEMENT\n";
    cout << setw(3) << (check+=i) << ". REPLACE A RECORD\n";
    cout << setw(3) << (check+=i) << ". RSEARCH ITEM\n";
    cout << setw(3) << (check+=i) << ". EXIT\n";
    return;
}
void INSERT_OPTION()
{
    int i = 1, check = 0;
    cout << setw(3) << (check+=i) << ". INSERT BEGINING OF THE LIST\n";
    cout << setw(3) << (check+=i) << ". INSERT END OF THE LIST\n"; 
    cout << setw(3) << (check+=i) << ". INSERT AFTER A RECORD OF THE LIST\n";
    cout << setw(3) << (check+=i) << ". INSERT BEFOR A RECORD OF THE LIST\n";
}
void DELETE_OPTION()
{
    int i = 1, check = 0;
    cout << setw(3) << (check+=i) << ". DELETE FIRST RECORD\n";
    cout << setw(3) << (check+=i) << ". DELETE LAST RECORD\n"; 
    cout << setw(3) << (check+=i) << ". DELETE SPACIFIC SINGLE RECORD\n";
    cout << setw(3) << (check+=i) << ". DELETE SPACIFIC ALL RECORD\n";
}
