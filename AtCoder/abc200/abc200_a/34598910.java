// detail: https://atcoder.jp/contests/abc200/submissions/34598910
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int n = stdin.nextInt();
        int ceiled = (n+(100-1))/100;
        System.out.println(ceiled);
    }
}
