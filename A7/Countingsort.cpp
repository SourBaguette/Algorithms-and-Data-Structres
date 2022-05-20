#include <iostream>
using namespace std;

void countingsort(int arr[], int size)
{
    int range = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[0] < arr[i]) {
            range = arr[i];
        }
    }
    range = range + 1;
    int output[size];
    int temp[range];
    for (int i = 0; i < range; i++) {             //setting index array as 0 to avoid errors
        temp[i] = 0;
    }
    for (int j = 0; j < size; j++) {             //counting the occurances of each number and incrementing in the index array
        temp[arr[j]] = temp[arr[j]] + 1;
    }
    for (int k = 1; k < range; k++) {           //summing the occurances of index array from left to right side
        temp[k] = temp[k] + temp[k - 1];
    }

    for (int l = (size - 1); l >= 0; l--) {     //putting the elements in sorted order and decreasing their occurance each time we insert the number
        output[temp[arr[l]]] = arr[l];
        temp[arr[l]] = temp[arr[l]] - 1;
    }
    for (int i = 0; i < size; i++) {            // storing values from output array to initial array
        arr[i] = output[i + 1];                 // there is a +1 because elements in output array were only sorted excluding position 0
    }
}
int main()
{
    int arr[] = { 4, 1, 3, 4, 3 };
    countingsort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}
