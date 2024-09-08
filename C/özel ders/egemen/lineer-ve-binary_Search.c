// BİNARY SEARCH ALGORİTMASI 

/*
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Ortadaki elemanı kontrol et
        if (arr[mid] == target)
            return mid;

        // Eğer hedef değeri ortadaki elemandan küçükse, sol yarıda ara
        if (arr[mid] > target)
            high = mid - 1;
        else // Aksi halde sağ yarıda ara
            low = mid + 1;
    }

    // Eğer eleman bulunamadıysa
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Eleman dizinin %d. indeksinde bulundu.\n", result);
    else
        printf("Eleman dizide bulunamadı.\n");

    return 0;
}
*/



/*******************************************************************************/


//LİNEER SEARCH ALGORİTMASI

/*
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;  // Eleman bulundu, indeksi döndür
    }
    return -1;  // Eleman bulunamadı
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = linearSearch(arr, size, target);

    if (result != -1)
        printf("Eleman dizinin %d. indeksinde bulundu.\n", result);
    else
        printf("Eleman dizide bulunamadı.\n");

    return 0;
}
*/