#include <iostream>
#include <iomanip>
using namespace std;

struct Book
{
    string id;
    string name;
    int type;
    int price;
};

void input1(Book item[], int &i, int count[])
{

    string id;
    string name;
    int type;

    // รับข้อมูลหนังสือเล่มแรก
    cout << "╔════════════════════╦═══════════════════════════╗" << endl;
    cout << "║   ป้อนหลังสือเล่มที่     ║"<< setw(13) << i + 1 << "\t\t \b\b║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<< endl;
    cout << "║   ป้อน ID           ║ \t\t\t  ║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> id;

    // ตรวจสอบว่า id เป็น ### หรือไม่
    while (id != "###")
    {

        // ชื่อหนังสือ
        cout << "║   ชื่อหนังสือ          ║  \t\t\t     ║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b ";
        cin >> name;

        // ประเภทหนังสือ
        do
        {
            cout << "╠═══════════════╦════╩════════════╦══════════════╣" << endl;
            cout << "║  1.คอมพิวเตอร์  ║  2.คณิตศาสตร์     ║   3.สถิติ      ║"<< endl;
            cout << "╠═══════════════╩═════════════════╩══════════════╣" << endl;
            cout << "║ \t\t\t\t\t\t  \b║ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" ; cin >> type;
            cout << "╠═══════════════╦════════════════════════════════╣" << endl;
            if (type < 1 || type > 3)
            {
                cout << "ประเภทหนังสือไม่ถูกต้อง" << endl;
            }
        } while (type < 1 || type > 3);

        count[type - 1]++;

        // บันทึกข้อมูลหนังสือ
        item[i].id = id;
        item[i].name = name;
        item[i].type = type;

        // ราคาหนังสือ
        do
        {
            cout << "║   ราคาหนังสือ   ║ \t\t\t\t   ║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            cin >> item[i].price;
            cout << "╚═══════════════╩════════════════════════════════╝" << endl;
            if (item[i].price < 0)
            {
                cout << "ราคาหนังสือไม่ถูกต้อง" << endl;
            }
        } while (item[i].price < 0);

        cout << endl;

        // รับข้อมูลหนังสือเล่มถัดไป
        i++;
        cout << "╔════════════════════╦═══════════════════════════╗" << endl;
        cout << "║   ป้อนหลังสือเล่มที่     ║"<< setw(13) << i + 1 << "\t\t \b\b║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"<< endl;
        cout << "║   ป้อน ID           ║ \t\t\t  ║\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        cin >> id;
    }
}

void output1(const Book item[], int size, const int type[])
{
    // int total = 0;
    int total_type[3] = {0, 0, 0};

    // output
    cout << "รายการหนังสือทั้งหมด" << endl;
    cout << "╔════════════════════════════════════════════════╗" << endl;
    cout << "║                    COMPUTER                    ║" << endl;
    cout << "╠══════╦════════════════════╦════════╦═══════════╣" << endl;
    cout << "║  ID  ║        NAME        ║  TYPE  ║   PRICE   ║" << endl;
    cout << "╠══════╬════════════════════╬════════╬═══════════╣" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 1)
        {
            cout << "║ "<< setw(3) << item[i].id << "  ║ " << setw(11) << item[i].name << "        ║" << setw(4) << item[i].type << "    ║ " << setw(5) << item[i].price << "     ║" << endl;
            total_type[0] += item[i].price;
        }
    }
    cout << "╠══════╬════════════════════╩════════╩═══════════╣" << endl;
    cout << "║TOTAL ║             " << setw(5) << total_type[0] << "                       ║" << endl;
    cout << "╠══════╩═════════════════════════════════════════╣" << endl;
    cout << "║                      MATH                      ║" << endl;
    cout << "╠══════╦════════════════════╦════════╦═══════════╣" << endl;
    cout << "║  ID  ║        NAME        ║  TYPE  ║   PRICE   ║" << endl;
    cout << "╠══════╬════════════════════╬════════╬═══════════╣" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 2)
        {
            cout << "║ "<< setw(3) << item[i].id << "  ║ " << setw(11) << item[i].name << "        ║" << setw(4) << item[i].type << "    ║ " << setw(5) << item[i].price << "     ║" << endl;
            total_type[1] += item[i].price;
        }
    }
    cout << "╠══════╬════════════════════╩════════╩═══════════╣" << endl;
    cout << "║TOTAL ║             " << setw(5) << total_type[1] << "                       ║" << endl;
    cout << "╠══════╩═════════════════════════════════════════╣" << endl;
    cout << "║                      STAT                      ║" << endl;
    cout << "╠══════╦════════════════════╦════════╦═══════════╣" << endl;
    cout << "║  ID  ║        NAME        ║  TYPE  ║   PRICE   ║" << endl;
    cout << "╠══════╬════════════════════╬════════╬═══════════╣" << endl;
    for (int i = 0; i < size; i++)
    {
        if (item[i].type == 3)
        {
            cout << "║ "<< setw(3) << item[i].id << "  ║ " << setw(11) << item[i].name << "        ║" << setw(4) << item[i].type << "    ║ " << setw(5) << item[i].price << "     ║" << endl;
            total_type[2] += item[i].price;
        }
    }
    cout << "╠══════╬════════════════════╩════════╩═══════════╣" << endl;
    cout << "║TOTAL ║             " << setw(5) << total_type[2] << "                       ║" << endl;
    cout << "╠══════╩═══════╦═══════════════════╦═════════════╣" << endl;


    cout << "║              ║     COMPUTER      ║" << setw(7) << type[0] << "      ║" << endl;
    cout << "║   ALL BOOK   ╠═══════════════════╣" << "═════════════╣" << endl; 
    cout << "╠══════════════╣       MATH        ║" << setw(7) << type[1] << "      ║" << endl;
    cout << "║              ╠═══════════════════╣" << "═════════════╣" << endl;
    cout << "║  " << setw(6) << size << "      ║       STAT        ║" << setw(7) << type[2] << "      ║" << endl;
    cout << "╠══════════════╬═══════════════════╝" << "═════════════╣" << endl;
    cout << "║     TOTAL    ║              " << setw(5) << total_type[0] + total_type[1] + total_type[2] << "              ║" << endl;
    cout << "╚══════════════╩═════════════════════════════════╝" << endl;

}

void chose1()
{
    Book item[100];
    int type_count[3] = {0, 0, 0};
    int size = 0;
    input1(item, size, type_count);
    output1(item, size, type_count);
}


struct Product
{
    int id;
    string name;
    float price;
    int stock;
};

Product fake_item()
{
    Product item;
    item.id = -1;
    item.name = "none";
    item.price = 0;
    item.stock = 0;
    return item;
}

void init(Product item[], int size)
{
    // ให้ข้อมูลเริ่มต้น
    item[0].id = 5;
    item[0].name = "Milk";
    item[0].price = 10.0;
    item[0].stock = 10;

    item[1].id = 3;
    item[1].name = "coffee";
    item[1].price = 20.0;
    item[1].stock = 5;

    item[2].id = 4;
    item[2].name = "water";
    item[2].price = 5.0;
    item[2].stock = 20;

    item[3].id = 2;
    item[3].name = "juice";
    item[3].price = 15.0;
    item[3].stock = 3;

    item[4].id = 6;
    item[4].name = "green tea";
    item[4].price = 40.0;
    item[4].stock = 12;

    item[5].id = 1;
    item[5].name = "energy drink";
    item[5].price = 10.0;
    item[5].stock = 20;
}

Product bin_search(const Product item[], int first, int last, int key)
{
    int mid = (first + last) / 2;
    if (first > last)
    {
        return fake_item();
    }
    else if (key == item[mid].id)
    {
        return item[mid];
    }
    else if (key < item[mid].id)
    {
        return bin_search(item, first, mid - 1, key);
    }
    else
    {
        return bin_search(item, mid + 1, last, key);
    }
}

void sort_item(Product item[], int size)
{
    bool swapped = true;
    Product temp;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < (size - 1); i++)
        {
            if (item[i].id > item[i + 1].id)
            {
                temp = item[i];
                item[i] = item[i + 1];
                item[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

void display_item(Product item[])
{
    cout << endl;
    cout << "╔════════════════════════════════════════════════╗" << endl;
    cout << "║                   สินค้าทั้งหมด                    ║" << endl;
    cout << "╠═════════════════════╦══════════╦═══════════════╣" << endl;
    cout << "║      ชื่อสินค้า         ║   จำนวน  ║     ราคา      ║" << endl;
    cout << "╠═════════════════════╬══════════╬═══════════════╣" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "║   " << setw(12) << left << item[i].name << "      ║     " << setw(2) << item[i].stock << "   ║";
        cout << "    " << setw(6) << item[i].price << "     ║" << endl;
    }
    cout << "╚═════════════════════╩══════════╩═══════════════╝" << endl;
}

void result(Product item[], int item_is_buy[], int total)
{
    cout << endl;
    cout << "╔════════════════════════════════════════════════╗" << endl;
    cout << "║                   สินค้าทั้งหมด                    ║" << endl;
    cout << "╠═════════════════════╦══════════╦═══════════════╣" << endl;
    cout << "║      ชื่อสินค้า         ║   จำนวน  ║     ราคา      ║" << endl;
    cout << "╠═════════════════════╬══════════╬═══════════════╣" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (item_is_buy[i] > 0)
        {
            cout << "║    " << setw(12) << left << item[i].name << "     ║   " << setw(2) << item_is_buy[i] << "     ║";
            cout << "    " << setw(4) << item[i].price << "       ║" << endl;
        }
    }
    cout << "╠═════════════════════╬══════════╩═══════════════╣" << endl;
    cout << "║      ราคารวม        ║          " << setw(8) << total << "        ║" << endl;
    cout << "╚═════════════════════╩══════════════════════════╝" << endl;
}

void buy_product(Product item[], int item_count[], int &total)
{
    int product_id;
    int product_quality;
    Product product;

    do
    {   
        cout << "╔═════════════════════╦══════════════════════════╗" << endl;
        cout << "║     ป้อนรหัสสินค้า      ║ \t \t \t \t \b\b\b\b\b ║ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"; 
        cin >> product_id;
        product = bin_search(item, 0, 6, product_id);
        if (product.id == -1)
        {
            cout << "ไม่มีสินค้านี้ในร้าน" << endl;
        }
    } while (product.id == -1);

    do
    {
        cout << "║     ป้อนจำนวน        ║ \t \t \t \t \b\b\b\b\b\b\b║ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        cin >> product_quality;
        cout << "╚═════════════════════╩══════════════════════════╝" << endl;
        if (product_quality > product.stock)
        {
            cout << "สินค้ามีจำนวนไม่เพียงพอ" << endl;
        }
    } while (product_quality > product.stock);

    // process
    item_count[product.id - 1] += product_quality;
    total += product.price * product_quality;
    item[product.id - 1].stock -= product_quality;
    cout << "╔═════════════════════╦════════════╦═════════════╗" << endl;
    cout << "║     สินค้าที่ซื้อ         ║    ราคา    ║    จำนวน    ║" << endl;
    cout << "╠═════════════════════╬════════════╬═════════════╣" << endl;
    cout << "║    " << setw(13) << product.name <<  "    ║    " << setw(5) << product.price * product_quality << "   ║     "<< setw(5) << product_quality << "   ║"<<  endl;
    cout << "╚═════════════════════╩════════════╩═════════════╝" << endl;
}

void chose2()
{
    int size = 6, total = 0;
    int count[6] = {0};
    Product item[size];
    char choice = ' ';
    float money;

    init(item, size);
    sort_item(item, size);

    do
    {
        display_item(item);
        buy_product(item, count, total);

        do
        {
            cout << "╔════════════════════════════════════════════════╗" << endl;
            cout << "║                 เลือกทำรายการต่อ                 ║" << endl;
            cout << "╠═══════════════════════╦════════════════════════╣" << endl;
            cout << "║       1. ซื้อสินค้าต่อ     ║    2. เพื่อไปชำระเงิน     ║" << endl;
            cout << "╠═══════════════════════╩════════════════════════╣" << endl;
            cout << "║ \t\t\t\t\t\t ║ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"; cin >> choice;
            cout << "╚════════════════════════════════════════════════╝" << endl;
            if (choice != '1' && choice != '2')
            {
                cout << "กรุณาเลือกทำรายการใหม่" << endl;
            }
        } while (choice != '1' && choice != '2');

        cout << endl;

    } while (choice == '1');

    result(item, count, total);

}

int main()
{
    chose1();
    chose2();
    return 0;
}