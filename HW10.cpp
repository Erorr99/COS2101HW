#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void output1(string word[], int &count)
{
    do
    {
        cout << "Enter a word: " << count + 1 << ": ";
        cin >> word[count++];
    } while (word[count - 1] != "###");
}

bool is_palindrome(string &text)
{
    int len = text.length();
    int mid = len / 2;

    string first = "";
    string last = "";

    // ทำแบบ loop เดียว
    for (int i = 0; i < len; i++)
    {
        if (i < mid)
        {
            first += text[i];
        }
        else if (i > mid)
        {
            last = text[i] + last;
        }
    }
    return first == last;
}

void chose1()
{
    int count = 0;
    int palindrome = 0;
    int not_palindrome = 0;
    string word[100] = {};
    output1(word, count);

    cout << "---------------------------------------------" << endl;
    cout << "|  ครั้งที่  |        คำ        | เป็น หรือ ไม่เป็น | " << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < count; i++)
    {   
        
        if (word[i] == "###")
        {
            break;
        }
        cout << "|  " << setw(3) <<  right <<  i + 1  << "   |" ;
        cout << "        " << setw(7) << left << word[i] << "   |" ;
        
        if (is_palindrome(word[i]))
        {
            cout << "    "<< setw(5) << right << " เป็น       |" << endl;
            palindrome += 1;
        }
        else
        {
            cout << "   " <<setw(4) << right << "  ไม่เป็น     |" << endl;
            not_palindrome += 1;
        }
    }
    cout << "---------------------------------------------" << endl;
    cout << "จำนวนคำที่เป็น palindrome: " << palindrome << endl;
    cout << "จำนวนคำที่ไม่เป็น palindrome: " << not_palindrome << endl;
    cout << "---------------------------------------------" << endl;
}

bool isPalindrome2(string str, int first, int last) {
    if (first == last) 
        return true;
    if (str[first] != str[last]) 
        return false;
    if (first < last + 1) 
        return isPalindrome2(str, first + 1, last - 1);
    return true;
}


void chose2(){
    int count = 0;
    int palindrome = 0;
    int not_palindrome = 0;
   string str[100];
    do
    {
        cout << "Enter a word: " << count + 1 << ": ";
        cin >> str[count++];
    } while (str[count - 1] != "###");

    cout << "---------------------------------------------" << endl;
    cout << "|  ครั้งที่  |        คำ        | เป็น หรือ ไม่เป็น | " << endl;
    cout << "---------------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        if (str[i] == "###")
        {
            break;
        }
        cout << "|  " << setw(3) <<  right <<  i + 1  << "   |" ;
        cout << "        " << setw(7) << left << str[i] << "   |" ;
        if (isPalindrome2(str[i], 0, str[i].length() - 1)){
            cout << "    "<< setw(5) << right << " เป็น       |" << endl;
            palindrome += 1;
        }
        else
        {
            cout << "   " <<setw(4) << right << "  ไม่เป็น     |" << endl;
            not_palindrome += 1;
        }
    }
    cout << "---------------------------------------------" << endl;
    cout << "จำนวนคำที่เป็น palindrome: " << palindrome << endl;
    cout << "จำนวนคำที่ไม่เป็น palindrome: " << not_palindrome << endl;
    cout << "---------------------------------------------" << endl;
}

string convert(int num, int base)
{
    if (num == 0)
    {
        return "";
    }
    else
    {
        return convert(num / base, base) + to_string(num % base);
    }
}

void chose3()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "-----------------------------" << endl;
    cout << "| ฐาน 2 |" << "      " << setw(5) << right << convert(num, 2) << "      |"<< endl;
    cout << "-----------------------------" << endl;
}

void Menu()
{
    cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
    cout << "1. : " << endl;
    cout << "2. : " << endl;
    cout << "3. : " << endl;
}
void loop(int &select)
{
    do
    {
        cout << "1-3" << endl;
        cin >> select;
    } while (select < 1 || select > 3);
}

int main()
{
    int select;
    Menu();
    cin >> select;
    switch (select)
    {
    case 1:
        chose1();
        break;
    case 2:
        chose2();
        break;
    case 3:
        chose3();
        break;
    }

    return 0;
}