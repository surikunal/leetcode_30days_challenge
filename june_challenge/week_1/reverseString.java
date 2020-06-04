class Solution {
    void swap(char[] arr, int si, int ei) {
        char temp = arr[si];
        arr[si] = arr[ei];
        arr[ei] = temp;
    }

    void reverseString(char[] s) {
        int si = 0, ei = s.length - 1;
        while (si <= ei) {
            swap(s, si, ei);
            si++;
            ei--;
        }
    }
}