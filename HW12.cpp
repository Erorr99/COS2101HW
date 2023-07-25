#include <iostream>
#include <iomanip>

using namespace std;

struct Student {
  int id;
  string name;
  double score;
};

struct Node {
  Student student;
  Node *next;
};

Node *createNode(int id, string name, double score) {
  Student student = {id, name, score};
  Node *node = new Node();
  node->student = student;
  node->next = nullptr;
  return node;
}

void addNode(Node *&head, Node *&tail, int id, string name, double score) {
  Node *node = createNode(id, name, score);
  if (head == nullptr) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

Node *findNode(Node *head, int id) {
  Node *current = head;
  while (current != nullptr && current->student.id != id) {
    current = current->next;
  }
  return current;
}

void deleteNode(Node *&head, Node *&tail, int id) {
  Node *previous = nullptr;
  Node *current = head;
  while (current != nullptr && current->student.id != id) {
    previous = current;
    current = current->next;
  }
  if (current == nullptr) {
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃             รายชื่อ ID  " << id << " ไม่พบในระบบ              ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
  } else if (previous == nullptr) {
    head = current->next;
    delete current;
  } else {
    previous->next = current->next;
    if (current == tail) {
      tail = previous;
    }
    delete current;
  }
}

void sortList(Node *&head) { // ใช้เรียงลำดับรายชื่อตาม ID จากน้อยไปมาก โดยใช้ Bubble Sort ในการเรียงลำดับ โดยใช้โครงสร้างข้อมูล Linked List ในการเก็บข้อมูล และใช้โครงสร้างข้อมูล Array ในการเก็บข้อมูลชั่วคราว โดยให้นักศึกษาเขียนโปรแกรมเพื่อเรียงลำดับรายชื่อตาม ID จากน้อยไปมาก โดยใช้ Bubble Sort ในการเรียงลำดับ โดยใช้โครงสร้างข้อมูล Linked List ในการเก็บข้อมูล และใช้โครงสร้างข้อมูล Array ในการเก็บข้อมูลชั่วคราว
  for (Node *i = head; i != nullptr; i = i->next) { 
    for (Node *j = i->next; j != nullptr; j = j->next) {
      if (i->student.id > j->student.id) {
        Student temp = i->student;
        i->student = j->student;
        j->student = temp;
      }
    }
  }
}

void displayList(Node *head) {
    cout << endl;
    cout << endl;
    cout << "┏━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓" << endl;
    cout << "┃   ID   ┃          รายชื่อ          ┃    คะแนน     ┃" << endl;
    cout << "┣━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫" << endl;
    for (Node *current = head; current != nullptr; current = current->next) {
    cout << "┃  " << setw(3) << current->student.id << "   ┃       " << setw(13) << left << current->student.name << "     ┃     "  << setw(7) << current->student.score << "  ┃"<< endl;
  }
    cout << "┗━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛" << endl;
    cout << endl;
    cout << endl;
}

int main() {
  Node *head = nullptr;
  Node *tail = nullptr;

  while (true) {
    int option;

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃                    เมนูโปรแกรม                   ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃ กด 1 เพื่อเพิ่มรายชื่อ       ┃    กด 2 เพื่อลบรายชื่อ     ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃ กด 3 เพื่อแสดงรายชื่อ      ┃  กด 0 เพื่อออกจากโปรแกรม ┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃    ใส่ตัวเลือกของคุณ \t\t\t\t\t\b\b\b ┃ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";cin >> option;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    if (option == 0) {
      break;
    } else if (option == 1) {
      int id;
      string name;
    double score;
    cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ ป้อน ID        ┃ \t\t\t\t\t\b\b\b\b\b\b ┃ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";cin >> id;
    cout << "┃ ป้อน ชื่อ        ┃ \t\t\t\t\t\b\b\b\b ┃ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";cin >> name;
    cout << "┃ ป้อน คะแนน     ┃ \t\t\t\t\t\b\b\b\b\b\b ┃ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";cin >> score;
    cout << "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    addNode(head, tail, id, name, score);
} else if (option == 2) {
int id;
cout << "┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
cout << "┃ ป้อน ID ที่จะลบ  ┃ \t\t\t\t\t\b\b\b┃ \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";cin >> id;
cout << "┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
deleteNode(head, tail, id);
} else if (option == 3) {
sortList(head);
displayList(head);
}
}

return 0;
}