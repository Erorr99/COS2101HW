#include <iostream>
#include <string>

using namespace std;
void Ep1()
{
    string text;

    cout << "write your word: " << endl;
    cin.ignore();
    getline(cin, text);

    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    int other = 0;
    for (char n : text) {
       switch (n)
        {
        case 'A':
        case 'a':
            a++;
            break;
        case 'E':
        case 'e':
            e++;
            break;
        case 'I':
        case 'i':
            i++;
            break;
        case 'O':
        case 'o':
            o++;
            break;
        case 'U':
        case 'u':
            u++;
            break;
        default:
        if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
            other++;
            break;
        
        }


    cout << "a = " << a << endl;
    cout << "e = " << e << endl;
    cout << "i = " << i << endl;
    cout << "o = " << o << endl;
    cout << "u = " << u << endl;    
    cout << "other = " << other << endl;

}
}


void chose1()
{
    Ep1();
}

void Ep2() 
{
    string text, add;
    char n;
    cout << "ใส่ข้อความลงไป: " ;
    cin.ignore();
    getline(cin, text);



    cout << "ใส่ตัวที่ให้แทน: " ;
    cin << n;


    cout << "ใส่ตัวที่จะให้ทับ: ";
    cin.ignore();
    getline(cin, add );

    int pos = text.find(n);
    for(; pos != -1 ;  pos = text.find(n, pos+2)){ //string::npos เป็นค่าคงที่ที่แสดงค่าสูงสุดที่เป็นไปได้ของชนิดข้อมูล string::size_type ซึ่งใช้แทนขนาดของสตริง
        text.replace(pos, 1 , add);
    }

    n = toupper(n)    // toupper เปลี่ยนตัวพิมพ์เล็กให้เป็น ตัวพิมพ์ใหญ่
    pos = text.find(n);
    for(; pos != -1 ;  pos = text.find(n, pos+2)){
        text.replace(pos, 1 , add);
    }
    cout << text << endl;
}


void chose2()
{  
    Ep2();
}

void Menu()
{
    int select;
    cout << "1-3" << endl;
}
 
void Ep3() {
    string target = "12345"; //the 4-digit number without repeating
    string guess;
    int pos = 0;
    int correct = 0;
    char key;
    for (int a = 1 ; a < 2 ; a++)
    {
        while (guess.length() != 5)
        {
            cout << "ครั่งที่ " << a << endl;
            cout << "ใส่เลขที่ 4 ตัว: ";
            cin >> guess;
        }
            for (int i = 0; i < target.length(); i++) 
            {
                key = target.at(i);
                if ( key == guess.at(i))
                {
                    pos++;
                }
                for(int j = 0; j < guess.length(); j++)
                {
                    if (key == guess.at(j))
                    {
                        correct++;
                    }
            }
        }
    cout << "correct: " << correct << endl;
    cout << "position: " << pos << endl;
    }

    
}

void chose3()
{
    Ep3();
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