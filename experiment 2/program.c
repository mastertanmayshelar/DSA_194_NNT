#include <stdio.h>

void accept(int arr[], int n) {
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n) {
    printf("Array elements are:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearsearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) return 1;
    }
    return 0;
}

int BinSearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) return 1;
        else if(key < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

void displaymenu() {
    printf("\n========MENU========");
    printf("\n1. Create Array");
    printf("\n2. Display Array");
    printf("\n3. Linear Search");
    printf("\n4. Binary Search (Sorts Array First)");
    printf("\n5. Display Menu");
    printf("\n6. Exit");
    printf("\n====================");
}

int main() {
    int arr[100];
    int n = 0;
    int choice;
    int target;
    int key;
    
    displaymenu();
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter size: ");
                scanf("%d", &n);
                accept(arr, n);
                break;
            case 2:
                display(arr, n);
                break;
            case 3:
                printf("Enter target: ");
                scanf("%d", &target);
                if(linearsearch(arr, n, target))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 4:
                sortArray(arr, n); // Binary search requires sorted data
                printf("Enter key: ");
                scanf("%d", &key);
                if(BinSearch(arr, n, key))
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 5:
                displaymenu();
                break;
            case 6:
                printf("Program ended.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 6);
    
    return 0;
}
