import java.util.Scanner;

import static java.lang.Math.max;

public class KNAPSAC {
    public static int n,weight;
    public static int[][] res=new int [n+1][];
    public static int []w;
    public static int []v;
    public static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        n=sc.nextInt();
        weight=sc.nextInt();
        if(n==0||weight==0){
            System.out.println(0);
            return;
        }
        w=new int[n+1];
        v=new int[n+1];
        res=new int[n+1][weight+1];
        for(int i=1;i<=n;i++){
            w[i]=sc.nextInt();
            v[i]=sc.nextInt();
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=weight;j++){
                if(j>=w[i]){
                    res[i][j]=max(res[i-1][j],v[i]+res[i-1][j-w[i]]);
                }else{
                    res[i][j]=res[i-1][j];
                }
            }
        }
        System.out.println(res[n][weight]);
    }
}
