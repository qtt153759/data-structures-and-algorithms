import java.util.Scanner;

import static java.lang.Math.max;

public class MARBLE {
    public static Scanner sc=new Scanner(System.in);
    public static int H,W,n,w,h;
    public static int[][]dp;
    public static void main(String[] args) {
        W=sc.nextInt();
        H=sc.nextInt();
        n=sc.nextInt();
        dp=new int[W+1][H+1];
        for(int i=0;i<n;i++){
            w=sc.nextInt();
            h=sc.nextInt();
            dp[w][h]=w*h;
        }
        for(int i=0;i<=W;i++){
            for(int j=0;j<=H;j++){
                for(int i1=0;i1<=i;i1++){
                    dp[i][j]=max(dp[i][j],dp[i1][j]+dp[i-i1][j]);
                }for(int j1=0;j1<=j;j1++){
                    dp[i][j]=max(dp[i][j],dp[i][j1]+dp[i][j-j1]);
                }
            }
        }
        System.out.println(W*H-dp[W][H]);
    }
}
//21 11
//        4
//        10 4
//        6 2
//        7 5
//        15 10