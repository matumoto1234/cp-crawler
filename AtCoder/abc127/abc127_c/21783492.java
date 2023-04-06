// detail: https://atcoder.jp/contests/abc127/submissions/21783492
import java.util.Scanner;

public class  Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[] imos = new int[100002];
    
    for(int i=0;i<100002;i++) imos[i] = 0;
    
    for(int i=0;i<m;i++){
      int l = scanner.nextInt();
      int r = scanner.nextInt();
      l--;
      
      imos[l] = 1;
      imos[r] = -1;
    }
    for(int i=0;i<n;i++){
      imos[i+1]+=imos[i];
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
      if(imos[i]==m){
        ans++;
      }
    }
    System.out.println(ans);
  }
}