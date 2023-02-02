#include <iostream>
#include <cmath>
using namespace std;

// MeNU

void hw1(int &a, int &b, int &c,int & d)
{
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    cout << " c = ";
    cin >> c;
    cout << " d = ";
    cin >> d;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void mainhw1(int &a, int &b, int &c,int & d)
{
    swap(a,d);
    swap(b,c);

    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    cout << " c = " << c << endl;
    cout << " d = " << d << endl;
    
}

void chose1()
{
    int a, b, c, d;
    hw1(a, b ,c ,d);
    mainhw1(a, b ,c ,d);
}

//>>>> 2 <<<<

void hw2(int &s)
{
    cout << " ใส่วินาที = ";
    cin >> s;
}

void mainhw2(int & h,int &m,int &s)
{
    h = (s / 3600);
    m = (s % 3600) / 60;
    s = (s % 3600) % 60;

    cout << "เวลาที่ได้ทั้งหมด คือ " << h << " ชั่วโมง " << m << " นาที " << s << " วินาที " << endl; 
}

void chose2()
{
int h, m, s;
hw2( s );
mainhw2(h, m, s);
}

//>>>>>> 3 <<<<<

float findarea(float radius)
{
    return 3.14 * pow(radius, 2);
}

float findlongarea(float radius)
{
    return 2 * 3.14 * radius;
}

void hw3(float & radius)
{
    cout << " radius = ";
    cin >> radius;
}

void pir(float & area, float & radius, float & longarea)
{   
    cout << " พื้นที่วงกลบ = " << findarea(radius) << endl;
    cout << " ความยาวเส้นรอบวง  = " << findlongarea(radius) << endl;
} 

void chose3()
{
    float radius, area, longarea;
    hw3(radius);
    pir(area, radius, longarea);
}
//>>>>>>>>> 4 <<<<<<<<<
using namespace std;

float findintest(float p, float r, float &money)
{
    return p * (r / 100);
}

void findcompound(float &p, float &r, float &money)
{
    money = findintest(p, r, money) + p;
}

void input4(float &p, float &r, float &money)
{
    cout << " ใส่เงินฝากของคุณ = "; cin >> p;
    cout << " ใส่อัตราดอกเบี้ย = "; cin >> r;
}

void output4(float &p, float &r, float &money)
{
    cout << " ดอกเบี้ยที่ได้ คือ " << findintest(p, r, money) << endl;
    cout << " เงินทบดอกเบีย คือ  " << money << endl;
}

void chose4()
{
    float p, r, money;
    input4(p, r, money);
    findintest(p, r, money);
    findcompound(p, r, money);
    output4(p, r, money);
}





//MENU
void menu()
{
    cout << " >>>>>>>>>> MENU <<<<<<<<<<" << endl;
    cout << " 1.สลับเลข " << endl;
    cout << " 2.แปรวินาทีรวม " << endl;
    cout << " 3.หาพื้นที่ และ เส้นรอบวง " << endl;
    cout << " 4.หาดวกเบี้ยทบต้น 1 ปี่ " << endl;
}

void loop(int &select)
{
    do
    {
        cout << " 1-4 ?" << endl;
        cin >> select;
    } while (select < 1 or select > 4);
    
}


int main()
{
    int select;
    menu();
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
        case 4:
            chose4();
            break; 
        }
    return 0;
}