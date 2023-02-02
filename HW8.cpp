#include <iostream>
#include <cmath>
using namespace std;


//EP1

void FindUnion(const int x[], const int y[], int size_x, int size_y, int ar_union[])
{
    int size = 0;
    for (int i = 0; i < size_x; i++)
    {
        ar_union[size] = x[i];
        size++;
    }
    for (int j = 0; j < size_y; j++)
    {
        bool is_duplicate = false;
        for (int i = 0; i < size_x; i++)
        {
            if (y[j] == x[i])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            ar_union[size] = y[j];
            size++;
        }
    }
}

// A - B
void FindDiff(const int x[], const int y[], int size_x, int size_y, int ar_diff[])
{
    for (int i = 0; i < size_x; i++)
    {
        bool is_duplicate = false;
        for (int j = 0; j < size_y; j++)
        {
            if (x[i] == y[j])
            {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate)
        {
            ar_diff[i] = x[i];
        }
    }
}

// A n B
void FindInter(int x[], int y[], int size_x, int size_y, int ar_inter[])
{
    int size = 0;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            if (x[i] == y[j])
            {
                ar_inter[size] = x[i];
                size++;
            }
        }
    }
}

void output(int ar_u[], int ar_d[], int ar_i[], int size)
{
    cout << "A U B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_u[i] > 0)
        {
            cout << ar_u[i];
            if (ar_u[i + 1] != 0)
            {
                cout << ", ";
            }
        }
    }
    cout << "}";
    cout << endl;

    cout << "A - B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_d[i] > 0)
        {
            cout << ar_d[i];
            cout << ", ";
        }
    }
    cout << "}";
    cout << endl;

    cout << "A Inter B = {";
    for (int i = 0; i < size; i++)
    {
        if (ar_i[i] > 0)
        {
            cout << ar_i[i];
            cout << ", ";
        }
    }
    cout << "}";
    cout << endl;
}

void chose1()
{   int a,b;
    
   
    cout <<"ต้องการขนานของ setA  เท่าไหร่: ";
    cin >> a;
    
    cout <<"ต้องการขนานของ setB เท่าไหร่ :" ; 
    cin >> b;
    
    int A[a] = {0};
    int B[b] = {0};
   cout <<"ป้อนตัวเลขของ setA จำนวน : "<<a<<" ตัว"<<endl;
    for(int i=0;i<a;i++){
        cout << "satA ตัวที่ "<<i+1<<" : ";
        cin >> A[i];
    }
    cout <<"ป้อนตัวเลขของ setA จำนวน : "<<b<<" ตัว"<<endl;
   for(int i=0;i<b;i++){
       cout << "satB ตัวที่ "<<i+1<<" : ";+1;
        cin >> B[i];
    }
    
    
    int sizeA = a; // 4
    int sizeB = b; // 4
    int sizeAB = sizeA + sizeB;            // 4 + 4 = 8
    cout << sizeA;
    int AUB[sizeAB] = { 0 }; // UNION
    int ADB[sizeAB] = { 0 }; // DIFF
    int AIB[sizeAB] = { 0 }; // INTER

    FindUnion(A, B, sizeA, sizeB, AUB);
    FindDiff(A, B, sizeA, sizeB, ADB);
    FindInter(A, B, sizeA, sizeB, AIB);
    output(AUB, ADB, AIB, sizeAB);
}

void Ep2(float ar[], int &index, float &insert)
{
    int size = 0;
    for (int i = 0; i < 20; i++)
    {
        do
        {
            cout << "Input Number at " << i + 1 << " : ";
            cin >> ar[i];
        } while (ar[i] <= 0 && ar[i] != -999);
        if (ar[i] == (-999))
        {
            ar[i] = 0;
            break;
        }
        size++;
    }
    do
    {
        cout << "Index to insert: ";
        cin >> index;
    } while (index > size);

    do
    {
        cout << "insert data: ";
        cin >> insert;
    } while (insert < 0);

    int temp = 0.0, before = 0.0;
    for (int i = 0; i < 10; i++)
    {
        if (i == index)
        {
            temp = ar[i];
            ar[i] = insert;
        }
        else if (i > index)
        {
            before = ar[i];
            ar[i] = temp;
            temp = before;
        }
    }
    cout << "Array = {";
    for (int i = 0; i < 100; i++)
    {
        if (ar[i] != 0)
        {
            cout << ar[i];
            if (ar[i + 1] != 0)
            {
                cout << ", ";
            }
        }
    }
    cout << "}";
}

void chose2()
{
    float ar[100] = {};
    int index = 0;
    float insert = 0;
    Ep2(ar, index, insert);

}
//3
void input3(int &n)
{
    cout << "Input n : ";
    cin >> n;
}

void inputArray(int ar[], int &n, float &sum)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Input index at " << i << ": ";
        cin >> ar[i];
        sum += ar[i];
    }
}

float process3(const int ar[], int &n, float mean)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow((ar[i] - mean), 2);
    }
    return sqrt(sum / (n - 1));
}

void output3(float sum)
{
    cout << "variance is " << sum << endl;
}

void chose3()
{
    float sum = 0;
    int n = 0;
    input3(n);
    int ar[n] = {0};
    inputArray(ar, n, sum);
    cout << "mean is " << sum / n << endl;
    output3(process3(ar, n, sum / n));
}

void Menu()
{
   cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
   cout << "1. : " << endl;
   cout << "2. : " << endl;
   cout << "3. : " << endl;
}
void loop(int & select)
{
    do
    {
        cout << "1-3" << endl;
        cin >> select ;
    } while (select < 1 || select > 3);
    
}

int main ()
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

