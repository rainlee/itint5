// ��Ȼ���֣��ؼ����ж�ǰ�������֣���һ�����������
// �ȱȽ����򲿷֣�����������򲿷֣�������һ�����в���
// ��������ظ�Ԫ�أ����ܻ��˻�ΪO(n)

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