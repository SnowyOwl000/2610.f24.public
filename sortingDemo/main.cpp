#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

void bubbleSort(uint32_t data[],uint32_t nItems) {

    for (uint32_t last=nItems-1;last>0;last--)
        for (uint32_t i=0;i<last;i++)
            if (data[i] > data[i+1])
                swap(data[i],data[i+1]);
}

void mergeSortRec(uint32_t data[],uint32_t low,uint32_t high,uint32_t aux[]) { // NOLINT(*-no-recursion)

    if (low < high) {
        uint32_t
            mid = (low + high) / 2;

        mergeSortRec(data,low,mid,aux);
        mergeSortRec(data,mid+1,high,aux);

        uint32_t
            L = low,
            k = low,
            R = mid + 1;

        while (L <= mid && R <= high) {
            if (data[R] < data[L])
                aux[k++] = data[R++];
            else
                aux[k++] = data[L++];
        }

        while (L <= mid)
            aux[k++] = data[L++];

        while (R <= high)
            aux[k++] = data[R++];

        for (k=low;k<=high;k++)
            data[k] = aux[k];
    }
}

void mergeSort(uint32_t data[],uint32_t nItems) {
    auto
        *mSortAux = new uint32_t[nItems];

    mergeSortRec(data,0,nItems-1,mSortAux);

    delete[] mSortAux;
}

bool binarySearch(const uint32_t data[],uint32_t nItems,uint32_t key) {
    uint32_t
        low=0,high=nItems-1;

    while (low < high) {
        uint32_t
            mid = (low + high) / 2;

        if (key > data[mid])
            low = mid + 1;
        else
            high = mid;
    }

    return data[low] == key;
}

int main(const int argc,char *argv[]) { //NOLINT
    random_device
        rd;
    mt19937
        mt(rd());
    uint32_t
        n;

    // get the number of items to sort
    if (argc != 2) {
        cout << "Enter number of elements to sort: ";
        cin >> n;
    } else
        n = strtol(argv[1],nullptr,10);

    // set up the arrays
    auto
        initialData = new uint32_t[n];
    auto
        bSortData = new uint32_t[n];
    auto
        mSortData = new uint32_t[n];

    // populate arrays
    for (uint32_t i=0;i<n;i++)
        initialData[i] = bSortData[i] = mSortData[i] = mt();

    // bubble sort
    auto
        start = chrono::system_clock::now();

    bubbleSort(bSortData,n);

    auto
        end = chrono::system_clock::now();

    auto
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    cout << "Bubble sort time: " << elapsed / 1000000 << '.' << elapsed % 1000000 << 's' << endl;

    double
        bTime = elapsed; // NOLINT(*-narrowing-conversions)

    // merge sort
    start = chrono::system_clock::now();

    mergeSort(mSortData,n);

    end = chrono::system_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

    double
        mTime = elapsed; // NOLINT(*-narrowing-conversions)

    double
        ratio = bTime / mTime;

    cout << setfill('0');
    cout << "Merge sort time: " << elapsed / 1000000 << '.'
        << setw(6) << elapsed % 1000000 << 's' << endl;

    // verify sorted order
    bool
        okay = true;

    for (uint32_t i=0;i<n-1;i++)
        if (mSortData[i] > mSortData[i+1])
            okay = false;

    cout << "Merge sort in order: " << (okay ? "pass" : "fail") << endl;

    okay = true;

    for (uint32_t i=0;i<n;i++)
        if (bSortData[i] > mSortData[i])
            okay = false;

    cout << "Bubble sort in order: " << (okay ? "pass" : "fail") << endl;

    // see if all elements are in the sorted list
    okay = true;

    for (uint32_t i=0;i<n;i++)
        okay = okay && binarySearch(bSortData,n,initialData[i]);

    cout << "All elements sorted: " << (okay ? "pass" : "fail");

    cout << "Timing ratio: " << ratio << endl;

    delete[] initialData;
    delete[] bSortData;
    delete[] mSortData;

    return 0;
}
