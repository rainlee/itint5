// 仍然二分，关键是判断前后两部分，哪一部分是有序的
// 先比较有序部分，如果不在有序部分，则在另一部分中查找
// 如果包含重复元素，可能会退化为O(n)

int search(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low&high) + ((low^high) >> 1);
        if (arr[mid] == target)
            return mid;
        
        if (arr[low] <= arr[mid])  // first part sorted
        {
            if ((target >= arr[low]) && (target < arr[mid]))
                high = mid - 1;
            else
                low = mid + 1;
        }
        else  // second part sorted
        {
            if ((target > arr[mid]) && (target <= arr[high]))
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}