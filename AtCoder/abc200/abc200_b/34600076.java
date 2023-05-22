// detail: https://atcoder.jp/contests/abc200/submissions/34600076
import java.util.Scanner;

public class Main {

    public static long operation(long n) {
       if (n%200==0) {
           return n/200;
       }

       String joined = Long.toString(n).concat("200");
       return Long.parseLong(joined);
    }

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        long n = (long)stdin.nextInt();
        int k = stdin.nextInt();
        for (int i = 0; i < k; i++) {
            n = operation(n);
        }
        System.out.println(n);
    }
}
