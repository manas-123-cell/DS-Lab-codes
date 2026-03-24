/*You are tasked with writing a program that sorts an array using the Merge Sort algorithm. 
The program should read the elements of the array, display them before and after sorting.*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;

            if (right >= n)
                right = n - 1;

            int i = left, j = mid + 1, k = left;

            while (i <= mid && j <= right) {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }

            while (i <= mid)
                temp[k++] = arr[i++];

            while (j <= right)
                temp[k++] = arr[j++];

            for (int x = left; x <= right; x++)
                arr[x] = temp[x];
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
