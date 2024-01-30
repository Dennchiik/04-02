#include <iostream>
using namespace std;

struct Elem {
    int data;
    Elem* next, * prev;
};

class List {
private:
    Elem* Head, * Tail;
    int Count;

public:
    List();
    List(const List&);
    ~List();
    int GetCount();
    Elem* GetElem(int);
    void DelAll();
    void Del(int pos = 0);
    void Insert(int pos = 0);
    void AddTail(int n);
    void AddHead(int n);
    void Print();
    void Print(int pos);
    List& operator=(const List&);
    List operator+(const List&);
    bool operator==(const List&);
    bool operator!=(const List&);
    bool operator<=(const List&);
    bool operator>=(const List&);
    bool operator<(const List&);
    bool operator>(const List&);
    List operator-();

    void DelRange(int pos1, int pos2);
};

void List::DelRange(int pos1, int pos2) {
    if (pos1 < 1 || pos2 < pos1 || pos2 > Count) {
        cout << "Invalid range!\n";
        return;
    }

    Elem* PrevRange = GetElem(pos1 - 1);
    Elem* AfterRange = GetElem(pos2 + 1);

    Elem* temp = GetElem(pos1);
    while (temp != AfterRange) {
        Elem* nextTemp = temp->next;
        delete temp;
        temp = nextTemp;
        Count--;
    }

    if (PrevRange != nullptr) {
        PrevRange->next = AfterRange;
    }
    else {
        Head = AfterRange;
    }

    if (AfterRange != nullptr) {
        AfterRange->prev = PrevRange;
    }
    else {
        Tail = PrevRange;
    }
}

int main() {
    List L;
    for (int i = 1; i <= 10; i++) {
        L.AddTail(i);
    }

    cout << "Original List:\n";
    L.Print();

    L.DelRange(3, 7);

    cout << "\nList after deleting elements from position 3 to 7:\n";
    L.Print();

    return 0;
}
