class Solution {
public:

    int firstocc(vector<int>& arr, int target){
        int l=0,h=arr.size()-1,first=-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(arr[mid]==target){
                first=mid;
                h=mid-1;
            }
            else if(arr[mid]>target) h=mid-1;
            else l=mid+1;
        }

        return first;
    }

    int lastocc(vector<int>& arr, int target){
        int l=0,h=arr.size()-1,last=-1;

        while(l<=h){
            int mid=(l+h)/2;

            if(arr[mid]==target){
                last=mid;
                l=mid+1;
            }
            else if(arr[mid]>target) h=mid-1;
            else l=mid+1;
        }

        return last;
    }

    int countOccurrences(vector<int> arr, int target){
        int first = firstocc(arr,target);

        if(first==-1) return 0;

        int last = lastocc(arr,target);

        return last-first+1;
    }
};