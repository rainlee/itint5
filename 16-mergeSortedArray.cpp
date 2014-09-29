// 从后往前遍历，选大的数
void mergeSortedArray(int arr1[], int arr2[], int n, int m) {
    int i = n-1;
    int j = m-1;
    for (int k = m+n-1; k >= 0; --k)
    {
        if ((j < 0) || ((i >= 0) && (j >= 0) && (arr1[i] >= arr2[j])))
            arr1[k] = arr1[i--];
        else
            arr1[k] = arr2[j--];
    }
}