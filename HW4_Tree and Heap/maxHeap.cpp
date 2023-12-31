#include <iostream>

using namespace std;

int N;

void checkMaxHeap(int a[], int index) {
    int maxx; //Index của phần tử lớn nhất trong: cha, con trái, con phải.
    int left = 2*index; //index của con trái.
    int right = 2*index + 1; //index của con phải.

    //Tìm vị trí của phần tử lớn nhất trong: cha, con trái, con phải
    if (left <= N && a[left] > a[index]) {
        maxx = left;
    } else {
        maxx = index;
    }
    if (right <= N && a[right] > a[index]) {
        maxx = right;
    }

    //Cha không lớn nhất thì đổi chỗ cha cho thằng con lớn nhất
    if (maxx != index) {
        swap(a[maxx], a[index]);
        checkMaxHeap(a, maxx);
    }
}

//Duyệt cây, trừ lớp cuối cùng vì lớp này không có con
void maxHeap(int a[]) {
    for (int i = N/2; i >= 1; i--) {
        checkMaxHeap(a, i);
    }
}

int main () {
    cin >> N;
    int a[N+1];
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    maxHeap(a);

    //preorder Traversal
    for (int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
