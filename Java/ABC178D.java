import java.util.*;

public class Main {
    public static int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();

        int[] a = new int[2021];
        int[] sum = new int[2021];

        a[3] = 1;
        a[4] = 1;
        a[5] = 1;
        sum[3] = 1;
        sum[4] = 2;
        sum[5] = 3;

        for (int i = 6; i <= s; ++i) {
            a[i] = madd(1, sum[i - 3]);
            sum[i] = madd(sum[i - 1], a[i]);

            // System.out.println(i + ":" + a[i]);
        }

        System.out.println(a[s]);
    }

    public static int madd(int a, int b) {
        return (a + b) % MOD;
    }

    public static int mmul(int a, int b) {
        long ret = a;
        ret = (ret * b) % MOD;
        return (int) ret;
    }

    public static int mpow(int a, int p) {
        int tmp = a, ans = 1;
        if (p == 0)
            return 1;
        else if (p == 1)
            return a;
        else {
            while (p > 0) {
                if (p % 2 == 0) {
                    p /= 2;
                    tmp = mmul(tmp, tmp);
                } else {
                    --p;
                    ans = mmul(ans, tmp);
                }
            }
        }
        return ans;
    }

}