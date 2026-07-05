bool f(int arr[], int i, int n){
    if(i >= n-1) return true;

    if(arr[i] > arr[i+1])
        return false;

    return f(arr, i+1, n);
}