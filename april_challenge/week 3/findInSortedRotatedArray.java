class Solution {
    public int search(int[] arr, int target) {
        int si = 0;
        int ei = arr.length - 1;
        
        while (si <= ei) {
            int mid = (si + ei) >> 1;
            if (target == arr[mid])
                return mid;
            
            // to ensure that the arr[mid] lie inside the array
            if (arr[mid] >= arr[si])
            {
                if ((target < arr[mid]) && (target >= arr[si]))
                    ei = mid - 1;
                else 
                    si = mid + 1;
            }
            
            // to ensure that the arr[mid] lie inside the array
            if (arr[mid] <= arr[ei])
            {
                if ((arr[mid] < target) && (target <= arr[ei]))
                    si = mid + 1;
                else 
                    ei = mid - 1;
            }
        }
        return -1;
    }
}