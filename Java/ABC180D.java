import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x, y, a, b;
        x = sc.nextLong();
        y = sc.nextLong();
        a = sc.nextLong();
        b = sc.nextLong();

        int k = (int) ((Math.log(b) - Math.log(a - 1) - Math.log(x)) / Math.log(a)) + 1;
        int lim = (int) ((Math.log(y - 1) - Math.log(x)) / Math.log(x));

        if (lim <= k) {
            System.out.println(lim);
            return;
        }

        long ans = (y - ((long) Math.pow(a, k)) * x) / b + (long) k;
        System.out.println(ans);
        // System.out.println(k + "(k)");
    }
}