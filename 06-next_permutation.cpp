// �Ӻ���ǰ �ҵ���һ���ƻ�����˳�����i
// �ٴδӺ���ǰ���ҵ���һ������i���������߽���
// ��iλ�ú��������
// ����ǰ�Ѿ���������У��򷵻�false
bool next_permutation(vector<int> &arr) {
    int i = arr.size() - 2;
    for (; (i >= 0) && (arr[i] >= arr[i+1]); --i) ;
    
    if (i < 0)
        return false;
         
    int j = arr.size() - 1;
    for (; (j > i) && (arr[j] <= arr[i]); --j) ;
    
    swap(arr[i], arr[j]);
    int low = i + 1;
    int high = arr.size() - 1;
    while (low < high)
         swap(arr[low++], arr[high--]);
    
    return true;
}