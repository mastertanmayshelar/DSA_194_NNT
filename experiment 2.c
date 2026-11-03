#include <stdio.h> 
void input(int a[], int n) 
{ 
    int i; 
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]); 
} 
void bubble(int A[],int n)

{
    int i , j, temp;
    for(i = 0; i < n-1; i++ ){
        for(j = 0; j < n-i-1; j++ ){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j+1] = A[j];
                A[j] = temp;
                } 
                for(i = 0; i< n; i++){
                printf("%d",A[i]);
                }
            }
        }
    }

void selection(int a[], int n) 
{ 
    int i, j, min, t; 
    for(i = 0; i < n - 1; i++) 
    { 
    min = i; 
    for(j = i + 1; j < n; j++) 
    { 
     if(a[j] < a[min]) 
     min = j; 
} 
t = a[i]; 
a[i] = a[min]; 
a[min] = t; 
    } 
} 
void insertion(int a[], int n) 
{ 
    int i, j, temp; 
    for(i = 1; i < n; i++) 
    { 
temp = a[i]; 
j = i - 1; 
while(j >= 0 && a[j] > temp) 
{ 
     a[j + 1] = a[j]; 
     j--; 
 } 
a[j + 1] = temp; 
    } 
} 
int partition(int a[], int l, int h) 
{ 
int p = a[h]; 
int i = l - 1; 
int j, t; 
for(j = l; j < h; j++) 
{ 
  if(a[j] < p) 
{ 
i++; 
 
    t = a[i]; 
    a[i] = a[j]; 
    a[j] = t; 
  } 
} 
 
    t = a[i + 1]; 
    a[i + 1] = a[h]; 
    a[h] = t; 
 
    return i + 1; 
} 
void quick(int a[], int l, int h) 
{ 
    int p; 
    if(l < h) 
    { 
        p = partition(a, l, h); 
 
        quick(a, l, p - 1); 
        quick(a, p + 1, h); 
    } 
} 
void merge(int a[], int l, int m, int h) 
{ 
    int i = l, j = m + 1, k = 0; 
    int b[100]; 
 
    while(i <= m && j <= h) 
    { 
        if(a[i] < a[j]) 
            b[k++] = a[i++]; 
        else 
            b[k++] = a[j++]; 
    } 
 
    while(i <= m) 
        b[k++] = a[i++]; 
 
    while(j <= h) 
        b[k++] = a[j++]; 
 
    for(i = l, k = 0; i <= h; i++, k++) 
        a[i] = b[k]; 
} 
void mergesort(int a[], int l, int h) 
{ 
    int m; 
    if(l < h) 
    { 
        m = (l + h) / 2; 
 
        mergesort(a, l, m); 
        mergesort(a, m + 1, h); 
 
        merge(a, l, m, h); 
    } 
} 
void print(int a[], int n) 
{ 
    int i; 
 
    for(i = 0; i < n; i++) 
        printf("%d\t", a[i]); 
 
    printf("\n"); 
} 
 
int main() 
{ 
    int a[100], b[100], c[100], d[100], e[100]; 
    int n, i; 
 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 
 
    printf("Enter elements: "); 
    input(a, n); 
    for(i = 0; i < n; i++) 
    { 
        b[i] = a[i]; 
        c[i] = a[i]; 
        d[i] = a[i]; 
        e[i] = a[i]; 
    } 
    bubble(a, n); 
    selection(b, n); 
    insertion(c, n); 
    quick(d, 0, n - 1); 
    mergesort(e, 0, n - 1); 
    printf("\nBubble Sort: "); 
    print(a, n); 
    printf("Selection Sort: "); 
    print(b, n); 
    printf("Insertion Sort: "); 
    print(c, n); 
    printf("Quick Sort: "); 
    print(d, n); 
    printf("Merge Sort: "); 
    print(e, n); 
 
    return 0; 
} 
