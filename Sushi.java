import java.util.*;

public class Sushi {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        int m = scan.nextInt();

        long[] A = new long[n];
        long[] B = new long[m];

        for (int i = 0; i < n; i++) {
            A[i] = scan.nextLong();
        }

        for (int i = 0; i < m; i++) {
            B[i] = scan.nextLong();
        }

        Arrays.sort(A);
        Arrays.sort(B);

        int i = 0;
        int j = 0;
        int answer = 0;

        while (i < n && j < m) {

            if (B[j] <= 2 * A[i]) {
                answer++;
                i++;
                j++;
            } else {
                i++;
            }
        }

        System.out.println(answer);

        scan.close();
    }
}