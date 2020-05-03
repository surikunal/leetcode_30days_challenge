class Solution {
    public int[] productExceptSelf(int[] arr) {
        int n = arr.length;
        int[] left = new int[arr.length];
        left[0] = arr[0];
        int[] right = new int[arr.length];
        right[n - 1] = arr[n - 1]; 
        for (int i = 1; i < arr.length - 1; i++)
        {
            left[i] = arr[i] * left[i - 1];
            right[n - i - 1] = arr[n - i - 1] * right[n - i];
        }
        arr[0] = right[1];
        arr[n - 1] = left[n - 2];
        for (int i = 1; i < arr.length - 1; i++)
        {
            arr[i] = left[i - 1] * right[i + 1];
        }
        return arr;
    }
}