#include <iostream>
using namespace std;

const int MAX = 100; 
int queue[MAX];
int front = -1;
int rear = -1;

void insert_element(int value) {
    if (rear == MAX - 1) {
        cout << "\nOVERFLOW";
    } else if (rear == -1 && front == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
    cout << value << " queue. me daal diya \n";
}

int delete_element() {
    int val;
    if (front == -1) {
        cout << "\nUNDERFLOW";
        return -1;
    } else {
        val = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset the queue when it becomes empty
        }
        cout << val << " jhatak diya queue se.\n";
        return val;
    }
}

int peek() {
    if (front == -1) {
        cout << "\nUNDERFLOW";
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    int i;
    cout << "\nSab dikha? : ";
    if (front == -1) {
        cout << "Queue toh khali h baba .";
    } else {
        for (i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << " Enqueue krne ke liye 1 dabaen\n";
        cout << " Dequeue krne ke liye 2 daben\n";
        cout << " Peek krne ke liye 3 dabaen\n";
        cout << " Sab dekhene ke liye 4 dabaen\n";
        cout << " Is mayajal se nikalne ke liye 5 dabaen \n";
        cout << " Aapki pashnd?: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Eak value dale : ";
                cin >> value;
                insert_element(value);
                break;
            case 2:
                delete_element();
                break;
            case 3:
                value = peek();
                if (value != -1)
                    cout << "Front element hai: " << value << '\n';
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Nikal rha hun...\n";
                break;
            default:
                cout << "\n Miyan! pashand bhut gandi h aapki. Puhnah prayas kren.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
