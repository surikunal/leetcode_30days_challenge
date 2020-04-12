import java.util.*;

public class singleNum {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        solve1();
        solve2();
    }

    public static void solve1() {
        int[] arr = { 1, 3, 1, -1, 3 };
        Arrays.sort(arr);
        System.out.println("the missing num is " + pairOfShows(arr));
    }

    public static int solve2() {
        int[] arr = {1, 3, 1, -1, 3};
        int ans = 0;
        for (int i = 0; i < arr.length; i++) {
            ans ^= arr[i];
        }
        return ans;
    }

    public static int pairOfShows(int[] arr) {
        if (arr.length % 2 == 0) {
            System.out.println("all are paired");
            return -1;
        }
        int si = 0, ei = arr.length - 1;
        while (si <= ei) {
            int mid = (si + ei) / 2;
            if (mid == 0 || mid == arr.length - 1)
                return arr[mid];
            if (si == ei) {
                return arr[mid];
            }

            else if (mid % 2 == 0) {
                if (arr[mid] == arr[mid + 1]) {
                    si = mid + 1;
                } else if (arr[mid] != arr[mid - 1]) {
                    return arr[mid];
                } else {
                    ei = mid - 1;
                }
            }

            else if (mid % 2 != 0) {
                if (arr[mid] == arr[mid - 1]) {
                    si = mid + 1;
                } else if (arr[mid] != arr[mid + 1]) {
                    return arr[mid];
                } else {
                    ei = mid - 1;
                }
            }
        }
        return -1;
    }
}
