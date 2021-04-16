// detail: https://atcoder.jp/contests/agc002/submissions/21783633
import java.util.Scanner;

public class  Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int a=scanner.nextInt();
    int b=scanner.nextInt();
    if(a>0&&b>0){
      System.out.println("Positive");
      return;
    }
    if(a==0||b==0){
      System.out.println("Zero");
      return;
    }
    if(a>0!=b>0){
      System.out.println("Zero");
      return;
    }
    int sa=(a-b)*-1;
    if(a%2==0) System.out.println("Positive");
    else System.out.println("Negative");
  }
}