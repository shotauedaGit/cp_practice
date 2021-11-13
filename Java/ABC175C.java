import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x, k, d;
        x = sc.nextLong();
        k = sc.nextLong();
        d = sc.nextLong();

        x = Math.abs(x);
        long optimal;
        if ((x % d) <= d - (x % d))
            optimal = x / d;
        else
            optimal = x / d + 1;

        long ans = x - d * Math.min(k, optimal);
        System.out.println(ans);

    }
}