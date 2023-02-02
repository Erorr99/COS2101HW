#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string findHexSwitch(int n)
{
    int x;
    string h = "";
    while (n > 0)
    {
        int x = n % 16;
        if (x >= 0 && x <= 9)
        {
            h = to_string(x) + h;
        }
        else
        {
            switch (x)
            {
            case 10:
                h = "A" + h;
                break;
            case 11:
                h = "B" + h;
                break;
            case 12:
                h = "C" + h;
                break;
            case 13:
                h = "D" + h;
                break;
            case 14:
                h = "E" + h;
                break;
            case 15:
                h = "F" + h;
                break;
            }
        }
        n = n / 16;
    }
    return h;
}

void output(int & base10, string & h, int &n)
{
    cout << "ฐาน 10 คือ ";
    cin >> n;
    cout << "ฐาน 16 คือ " << h << endl;
}

void chose1()
{
    int base10,n;
    string base,h;
    findHexSwitch( n);
    output(base10, h, n);
}

//EP2

float Ep2(int n)
{
    float sum = 0.0, i = 1.0;
    while (sum <= n)
    {
        sum += (i) / (i + 1);
        i++;
    }
    return sum;
}

void output2(int &n)
{
    do {
    cout << "ใส่จำนวนที่ต้องการ run = " ;
    cin >> n;
    } while ( n <= 0 );

    cout << "ค่าที่ได้ คือ " << Ep2(n) << endl;
}

void chose2()
{
    int n;
    float sum , i;
    Ep2(n);
    output2(n);
}

// Ep3

void Ep3(int &i ,int &odd, int &even, int & Aeven,int &Aodd ,int &a)
{
    odd = 0;
    even = 0;
    Aeven = 0;
    Aodd = 0;
    cout << "ใส่เลขทั้งหมด 10 ครั้ง "<< endl;
   while ( i < 10)
    {
        cout << "ใส่เลขครั้งที่ " << i+1 << ": ";
        cin >> a;

        if (i % 2 == 0)
        {
            even += a;
            Aeven++; 
        }
        else
        {
            odd += a;
            Aodd++;
        }
        i++;
    }

}

void all(int & odd, int & even, int & Aeven,int & Aodd)
{
    cout << "จำนวนเลขคู่มีทั้งหมด: " << even << endl;
    cout << "จำนวนเลขคู่รวม: " << Aeven << endl;
    cout << "จำนวนเลขคี่ทั้งหมด: " << odd << endl;
    cout << "จำนวนเลขคี่รวม: " << Aodd << endl;
}

void chose3()
{
    int i,odd, even, Aodd, Aeven,a;
    Ep3(i,odd, even, Aodd, Aeven,a);
    all(odd, even, Aodd, Aeven);
}

//HEll4
void Ep4(int &i ,int &odd, int &even, int & Aeven,int &Aodd ,int &a)
{
    odd = 0;
    even = 0;
    Aeven = 0;
    Aodd = 0;
    
   while (true)
    {
        cout << "ใส่เลขครั้งที่ " << i+1 << ": ";
        cin >> a;
        if (a == -999)
        {
            break;
        }
        if (a % 2 == 0)
        {
            even += a;
            Aeven++; 
        }
        else
        {
            odd += a;
            Aodd++;
        }
        i++;
    
    }

}

void all2(int & odd, int & even, int & Aeven,int & Aodd)
{
    cout << "จำนวนเลขคู่มีทั้งหมด: " << even << endl;
    cout << "จำนวนเลขคู่รวม: " << Aeven << endl;
    cout << "จำนวนเลขคี่ทั้งหมด: " << odd << endl;
    cout << "จำนวนเลขคี่รวม: " << Aodd << endl;
}

void chose4()
{
    int i,odd, even, Aodd, Aeven,a;
    Ep4(i,odd, even, Aodd, Aeven,a);
    all2(odd, even, Aodd, Aeven);
}




//Menu
void Menu()
{
   cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
   cout << "1.ฐาน 10 เป็น ฐาน 16 : " << endl;
   cout << "2.หาผลรวม : " << endl;
   cout << "3. รับเลขจำนวนเต็ม 10 : " << endl;
   cout << "4. รับเลขไม่ทราบจำนวน : " << endl;
}

void loop(int & select)
{
    do
    {
        cout << "1-4" << endl;
        cin >> select ;
    } while (select < 1 || select > 4);
    
}

int main()
{
    int select;
    Menu();
    loop(select);
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
    default:
        chose4();
        break;
    }
return 0;
}   