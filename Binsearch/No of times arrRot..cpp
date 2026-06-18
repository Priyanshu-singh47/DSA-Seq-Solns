int findKRotation(vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;

    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {

        int mid = (low + high) / 2;

        // Search space already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        // Left half sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half sorted
        else {
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}