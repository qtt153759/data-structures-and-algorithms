import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.min;

public class ARTICULATION_POINTS_N_BRIDGES {
    static int  n,m;
    private static final int N = 100005;
    static Scanner sc =new Scanner(System.in);
    static int[] nums=new int[N];
    static int[] low=new int[N];
    static List<Integer>list[]=new ArrayList[N];
    static int bridge=0;
    static int articulations=0;
    static int count=0;
    static int[] articulation=new int[N];
    static boolean[] visited=new boolean [N];
    public static void main(String[] args) {
        n=sc.nextInt();
        m=sc.nextInt();
        int a,b;
        for(int i=1;i<=n;i++){
            list[i]=new ArrayList<>();
        }
        for(int i=0;i<m;i++){
            a=sc.nextInt();
            b=sc.nextInt();
            list[a].add(b);
            list[b].add(a);
        }
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                dfs(i,0);
            }
        }
        for(int i=1;i<=n;i++){
            articulations+=articulation[i];
//            if(articulation[i]==1){
//                System.out.println("point "+i);
//            }
        }
        System.out.println(articulations+" "+bridge);
    }
    public static void dfs(int u,int p){
//        System.out.println("Xet "+u+" va "+p+" co low "+(count+1));
        visited[u]=true;
        count++;
        nums[u]=low[u]=count;
        int dem=0;
        for(int v:list[u]){
//            System.out.println("Xet v"+v +"cua "+u);
            if(v==p){
                continue;
            }
            if(visited[v]==false){
                dem++;
                dfs(v,u);
//                System.out.println("co low cua "+u+" va "+v +":   "+low[u]+" va "+low[v]+" num: "+nums[u]);
                if(low[v]>nums[u]){
                    bridge++;
//                    System.out.println("bridge tăng tại "+u+" va "+v+" :"+bridge);
                }
                if(low[v]>=nums[u]){
                    articulation[u]=1;
//                    System.out.println("articualtion =1 tại "+u+" va "+v);
                }
                low[u]=min(low[u],low[v]);
            }else{
                low[u]=min(low[u],nums[v]);
//                System.out.println("co r va "+low[u]);
            }
//            System.out.println("low "+u+" = "+low[u]);
        }
        if(p==0){
            articulation[u]=dem>1?1:0;
        }
    }
}
