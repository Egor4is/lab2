#include <iostream>
#include <ctime>

using namespace std;

// Структура для списка
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Прототипы функций (чтобы main их видел)
void modifyValues(int& ref, int* ptr);
void demoModifyValues();

int main() {
    setlocale(LC_ALL, "Russian");

    const int n = 10;
    cout << "Заполнение массивов" << endl;

    // 1) Статика, индексная адресация
    int arr1[n];
    for (int i = 0; i < n; i++) arr1[i] = i * i;
    cout << "1) ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl;

    // 2) Статика, косвенная адресация
    int arr2[n];
    for (int i = 0; i < n; i++) *(arr2 + i) = i * i;
    cout << "2) ";
    for (int i = 0; i < n; i++) cout << *(arr2 + i) << " ";
    cout << endl;

    // 3) Динамика, индексная адресация
    int* arr3 = new int[n];
    for (int i = 0; i < n; i++) arr3[i] = i * i;
    cout << "3) ";
    for (int i = 0; i < n; i++) cout << arr3[i] << " ";
    cout << endl;
    delete[] arr3;

    // 4) Динамика, косвенная адресация
    int* arr4 = new int[n];
    for (int i = 0; i < n; i++) *(arr4 + i) = i * i;
    cout << "4) ";
    for (int i = 0; i < n; i++) cout << *(arr4 + i) << " ";
    cout << endl;
    delete[] arr4;


    cout << "\nОбъединение упорядоченных массивов" << endl;
    int n1 = 5, n2 = 7;
    int* A = new int[n1] {1, 3, 5, 7, 9};
    int* B = new int[n2] {2, 4, 6, 8, 10, 12, 14};
    int* C = new int[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (A[i] <= *(B + j)) {
            C[k++] = A[i++];
        }
        else {
            *(C + k++) = *(B + j++);
        }
    }
    while (i < n1) C[k++] = A[i++];
    while (j < n2) *(C + k++) = *(B + j++);

    cout << "Результат слияния: ";
    for (int m = 0; m < n1 + n2; m++) cout << C[m] << " ";
    cout << endl;

    delete[] A; delete[] B; delete[] C;


    cout << "\nДвусвязный список" << endl;
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= 10; ++i) {
        Node* newNode = new Node{ i, nullptr, tail };
        if (tail) tail->next = newNode;
        else head = newNode;
        tail = newNode;
    }
    cout << "Элементы списка: ";
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        cout << "[" << curr->data << "]" << (curr->next ? " <-> " : "");
    }
    cout << endl;
    // Очистка памяти списка
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    demoModifyValues();
    return 0;
}
void modifyValues(int& ref, int* ptr) {
    ref = 100;
    *ptr = 200;
}
void demoModifyValues() {
    cout << "\nУпражнение 2\n";
    int a = 1, b = 2;
    cout << "До: a = " << a << ", b = " << b << endl;
    modifyValues(a, &b);
    cout << "После: a = " << a << ", b = " << b << endl;
}
