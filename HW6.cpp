#include <iostream>
using namespace std;

// Ep1

void Ep1(int & count, int & n, int & j ,int & i) {
  count = 1; 
  cout << "ใส่จำนวนแถว : ";
  cin >> n;
  for (int i = 1; i <= n; i++)
   {
    for (int j = 1; j <= i; j++) 
    {
        cout << count << " ";
        count++;
    }
        cout << endl;
  }
}
void chose1()
{
    int count, n ,  j , i;
    Ep1(count, n ,  j , i);
}
//ep2

/*long fac(int n)
{
  long sum=1;
  int i;
  for (i=n; i > 1; i--)
  {
    sum=sum*i;
  }
  return sum;
}

long fac(int n)
{
  long sum=1;
  int i = n;
  while (i > 1)
  {
    sum = sum * i;
    i--;
  }
  return sum;
}*/

long fac(float n) {
  long sum = 1;
  int i = n;
  do {
    sum = sum * i;
    i--;
  } while (i > 1);
  return sum;
}

float permutation(float  n, float  r) {
  return fac(n) / fac(n - r);
}

float combination(float  n, float r) {
  return fac(n) / (fac(n-r) * fac(r));
} 

void output2(float & n, float & r) 
{
  cout << "ใส่ค่า n: "; cin >> n; 
  cout << "ใส่ค่า r: "; cin >> r;
  cout << "Permutation: " << permutation(n, r) << endl;
  cout << "Combination: " << combination(n, r) << endl;
}

void chose2()
{
    float n, r;
    long fac(n) ;
    permutation(n, r);
    combination(n,r );
    output2(n,r);
} 

//Ep3

void Ep3(int & binary, int & o , int &one) 
{
  cout << "binary: " ; cin >> binary ;
  o = 0 ;
  one = 1;
  while (binary > 0) {

    int digit = binary % 10;

    if (digit == 1) {
      o += one;
    }

    binary /= 10;
    one *= 2;
  }

  cout << o << endl;
}

void chose3()
{
    int binary, o, one;
    Ep3(binary, o , one);
}



void Menu()
{
   cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
   cout << "1.เลขแถว : " << endl;
   cout << "2.หา n,r : " << endl;
   cout << "3.ฐาน 2 เป็นฐาน 10  : " << endl;
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