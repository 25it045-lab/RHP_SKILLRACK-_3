import java.util.*;

public class B_Keran_And_Coffee {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int k = scan.nextInt();
        int q = scan.nextInt();

        int[][] ranges = new int[n][2];

        for (int i = 0; i < n; i++) {
            ranges[i][0] = scan.nextInt();
            ranges[i][1] = scan.nextInt();
        }

        int MAX = 200000;

        int[] diff = new int[MAX + 2];

        for (int i = 0; i < n; i++) {
            int left = ranges[i][0];
            int right = ranges[i][1];

            diff[left]++;
            diff[right + 1]--;
        }

        int[] freq = new int[MAX + 1];

        for (int i = 1; i <= MAX; i++) {
            freq[i] = freq[i - 1] + diff[i];
        }

        int[] admissible = new int[MAX + 1];

        for (int i = 1; i <= MAX; i++) {
            if (freq[i] >= k) {
                admissible[i] = 1;
            }
        }

        int[] pref = new int[MAX + 1];

        for (int i = 1; i <= MAX; i++) {
            pref[i] = pref[i - 1] + admissible[i];
        }

        while (q-- > 0) {
            int a = scan.nextInt();
            int b = scan.nextInt();

            System.out.println(pref[b] - pref[a - 1]);
        }

        scan.close();
    }
}