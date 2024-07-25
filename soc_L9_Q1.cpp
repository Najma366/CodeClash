#include <iostream>
#include<vector>
using namespace std;

class MaxHeap {
private:
    vector<int> H;
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void shiftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l <= size && H[l] > H[maxIndex])
            maxIndex = l;
        if (r <= size && H[r] > H[maxIndex])
            maxIndex = r;

        if (i != maxIndex) {
            swap(H[i], H[maxIndex]);
            shiftDown(maxIndex);
        }
    }

public:
    MaxHeap() {
        size = -1;
    }

    void insert(int p) {
        size++;
        H.push_back(p);
        int i = size;
        while (i > 0 && H[parent(i)] < H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    int extractMax() {
        int result = H[0];
        H[0] = H[size];
        size--;
        shiftDown(0);
        return result;
    }
};

int main() {
    MaxHeap pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
	    int val;
	    cin >> val;
            pq.insert(val);
    }
    int maxElement = pq.extractMax();
    cout << "Extracted maximum element: " << maxElement << endl;
}
