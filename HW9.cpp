// รับค่าคะแนนของนักศึกษา n คน เก็บใน array 2 5x5

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Ep1()
{
    int n;
    int G = 0;
    int P = 0;
    int F = 0;
    int Sumscore = 0;
    int Avgscore = 0;
    int Num_n = 0;
    bool is_continue = true;
    n = 5;
    int score[n][5] = {0};

    for (int i = 0; i < n; i++)
    {
        // cout << "นักศึกษาคนที่ " << i + 1 << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "คะแนนครั้งที่ " << Num_n + 1 << ": ";
            cin >> score[i][j];
            if (score[i][j] == -999)
            {
                is_continue = false;
                score[i][j] = 0;
                break;
            }
            if (score[i][j] > 79)
            {
                G++;
            }
            else if (score[i][j] > 59)
            {
                P++;
            }
            else
            {
                F++;
            }

            Sumscore += score[i][j];
            Num_n++;
        }

        if (!is_continue)
        {
            break;
        }
    }
    Avgscore = Sumscore / Num_n;

    cout << "คะแนนทั้งหมด: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "| ลำดับ " << i + 1 << " |";
        for (int j = 0; j < 5; j++)
        {
            cout << "   " << setw(2) << left << score[i][j] << "   |";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------" << endl;

    cout << "จำนวนนักศึกษาที่ได้เกรด G: " << G << endl;
    cout << "จำนวนนักศึกษาที่ได้เกรด P: " << P << endl;
    cout << "จำนวนนักศึกษาที่ได้เกรด F: " << F << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "คะแนนเฉลี่ยของนักศึกษาทั้งหมด: " << Avgscore << endl;
    cout << "คะแนนนักศึกษาทั้งหมด: " << Sumscore << endl;
    cout << "-------------------------------------------------------" << endl;
}

void chose1()
{
    Ep1();
}

// Ep2
void Ep2()
{
    int sales[4][3] = {0};
    string name[4];
    int total[4] = {0};
    int max = 0;
    int money[4] = {0};
    string topsales;
    for (int i = 0; i < 4; i++)
    {
        cout << " ชื่อ " << i + 1 << endl;
        cin >> name[i];
        for (int j = 0; j < 3; j++)
        {
            cout << " เดือนที่ " << j + 1 << ": ";
            cin >> sales[i][j];
            total[i] += sales[i][j];
            if (total[i] > max)
            {
                max = total[i];
                topsales = name[i];
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {

        if (total[i] >= 100)
        {
            money[i] += 8 ;
            
            
        }
        else if (total[i] >= 80)
        {
            money[i] += 5 ;
        }
        else if (total[i] >= 50)
        {
            money[i] += 3 ;
        }
        else
        {
            money[i] += 1 ;
        }
    }

    cout << "-----------------------------------------------------------------" << endl;
    cout << "|          ชื่อ          |   เม.ย   |   พ.ค   |  มิ.ย   |   โบนัส  |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "|        " << setw(10) << left << name[i] << "    |";
        for (int j = 0; j < 3; j++)
        {
            cout << "    " << setw(4) << left << sales[i][j] << " |";
        }
        cout << "    " << setw(4) << left << money[i] << " |";
        cout << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << " ชื่อ " << name[i] << " ขายได้ " << total[i] << " ได้โบนัสทั้งหมด " << money[i] << " เดือน" << endl;
    }
    cout << " คนที่ขายได้เยอะที่สุด << " << topsales << " >> จำนวน " << max << endl;
}

void chose2()
{
    Ep2();
}

void Menu()
{
    cout << ">>>>>>>>> MENU <<<<<<<<<<" << endl;
    cout << "1. : " << endl;
    cout << "2. : " << endl;

}
void loop(int &select)
{
    do
    {
        cout << "1-2" << endl;
        cin >> select;
    } while (select < 1 || select > 2);
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
    }

    return 0;
}