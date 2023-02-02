#include <iostream>
using namespace std;



//EP1
void EP1(int & num)
{
    cout << " ใส่อะไรก็ได้ลงไป : ";
    cin >> num ;
}

void numAll(int & num)
{
    if (num > 0)
    {
        cout << " 1 " << endl;
    }
    if (num == 0)
    {
        cout << " 0 " << endl;
    }
    if (num < 0 ){
        cout << " -1 " << endl;
    }
    
}
void chose1()
{
    int num;
    EP1(num);
    numAll(num);
}

//EP2

void EP2(int & meter)
{
  cout << "ใส่ค่อมิตเตอร์ของคุณ: ";
  cin >> meter;
}

int findmeter(int meter)
{
    int pay = 0;
    if (meter > 100) {
        pay += (meter - 100) * 30;
        meter = 100;
    }
    if (meter >= 51 && meter <= 100) {
        pay += (meter - 50) * 25;
        meter = 50;
    }
    if (meter >= 21 && meter <= 50) {
        pay += (meter - 20) * 20;
        meter = 20;
    }
    if (meter >= 0 && meter <= 20) {
        pay += meter * 15;
    }
    return pay;
}

void main2(int & meter)
{
    cout << "ค่าน้ำที่คุณต้องจ่าย คือ " << findmeter(meter) << endl;
}

void chose2()
{
    int meter;
    EP2( meter);
    findmeter(meter);
    main2(meter);

}

//Ep3



void birthage(int & currentDay, int &currentMonth, int &currentYear,int &birthDay, int &birthMonth, int &birthYear,int &years, int &months)
{

    years = currentYear - birthYear;
    
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
    {
        years--;
    }
    
    months = currentMonth - birthMonth;
    
    if (currentMonth < birthMonth)
    {
        months += 12;
    }
    
    if (currentMonth == birthMonth && currentDay < birthDay)
    {
        months--;
    }
}

void main3(int & currentDay, int &currentMonth, int &currentYear,int &birthDay, int &birthMonth, int &birthYear,int &years, int &months)
{
    
    cout << "ใส่วันปัจจุบัน: ";
    cin >> currentDay ;
    cout << "ใส่เดือน ปัจจุบัน: ";
    cin >> currentMonth ;
    cout << "ใส่ปีปัจจุบัน: ";
    cin >> currentYear;
    cout << "ใส่วันเกิด: ";
    cin >> birthDay;
    cout << "ใส่เดือนเกิด: ";
    cin >> birthMonth;
    cout << "ใส่ปีเกิด: ";
    cin >> birthYear;
    birthage(currentDay, currentMonth, currentYear, birthDay, birthMonth, birthYear, years, months);
    
    cout << "อายุของคุณคือ: " << years << " ปีกับอีก " << months << " เดือน" << endl;
}

void chose3()
{
    int years, months , currentMonth, currentYear, birthDay, birthMonth, birthYear, currentDay;
    birthage(currentDay, currentMonth, currentYear, birthDay, birthMonth, birthYear , years, months);
    main3(currentDay, currentMonth, currentYear, birthDay, birthMonth, birthYear , years, months);
}

//Menu
void Menu()
{
   cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
   cout << "1.เต็มลบ เต็มศูนย์ เต็มบวก : " << endl;
   cout << "2.คิดค่าน้ำ : " << endl;
   cout << "3.หาอายุ ด้วยวันเกิด : " << endl;
}

void loop(int & select)
{
    do
    {
        cout << "1-3" << endl;
        cin >> select ;
    } while (select < 1 || select > 3);
    
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
        break;
    }
return 0;
}
