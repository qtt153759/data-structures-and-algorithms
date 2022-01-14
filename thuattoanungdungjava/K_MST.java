import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.min;

public class K_MST {
    public static int n;
    public static int m;
    public static int k;
    public static final int N=50;
    public static HashMap<Integer,ArrayList<ArrayList<Integer>>>map=new HashMap<>(N);
    public static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        int a,b,c;
        n=sc.nextInt();
        m=sc.nextInt();
        k=sc.nextInt();
        for(int i=1;i<=n;i++){
            map.put(i,new ArrayList<>());
        }
        for(int i=0;i<m;i++){
            a=sc.nextInt();
            b=sc.nextInt();
            c=sc.nextInt();
            map.get(a).add(new ArrayList<>(Arrays.asList(b,c)));
            map.get(b).add(new ArrayList<>(Arrays.asList(a,c)));
        }
        int res=Integer.MAX_VALUE;
        for(int i=1;i<=n;i++){
            res=min(res,prim(i));
        }
        System.out.println(res);
    }
    public static int prim(int s){
        boolean[]visited=new boolean[n+1];
        int []key=new int[n+1];
        Arrays.fill(key,Integer.MAX_VALUE);
        key[s]=0;
        int sum=0;
        for(int i=1;i<=k+1;i++){
            int u=0;
            for(int v=1;v<=n;v++){
                if(!visited[v]&&key[v]<key[u]){
                    u=v;
                }
            }
            sum=sum+key[u];
            visited[u]=true;
            for(int j=0;j<map.get(u).size();j++){
                int a=map.get(u).get(j).get(0);
                int w=map.get(u).get(j).get(1);
                if(!visited[a]&&key[a]>w){
                    key[a]=w;
                }
            }
        }
        return sum;
    }
}
