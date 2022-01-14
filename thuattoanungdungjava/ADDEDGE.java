import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.min;

public class ADDEDGE {
    public static final int N = 100000;
    public static int n, m;
    public static int count = 0;
    public static int[] nums = new int[N];
    public static int[] low = new int[N];
    public static boolean[] visited = new boolean[N];
    public static Scanner sc = new Scanner(System.in);
    public static List<List<Integer>> list[] = new ArrayList[N];
    public static int bridge = 0;

    public static void main(String[] args) {
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            list[a].add(new ArrayList<>(Arrays.asList(b, 0)));
            list[b].add(new ArrayList<>(Arrays.asList(a, 0)));
        }
        for (int i = 1; i <= n; i++) {
            if (nums[i] == 0) {
                dfs(i, 0);
            }
        }
        long res=0;
        nums = new int[N];
        for(int i=1;i<=n;i++){
            if(nums[i]==0){
                count=0;
                dfs2(i);
                if(count>2){
                    res+=(Long.valueOf(count)-1)*(Long.valueOf(count)-2)/2;
                }
            }
        }
        System.out.println(res);
    }

    public static void dfs(int u, int p) {
//       System.out.println("Xet " + u + " va " + p + " co low " + (count + 1));

        count++;
        nums[u] = low[u] = count;
        for (int i = 0; i < list[u].size(); i++) {

            int a = list[u].get(i).get(0);
//           System.out.println("Xet v" + a + "cua " + u);

            if (a == p) {
                continue;
            }
            if (nums[a] == 0) {
                dfs(a, u);
//                System.out.println("co low cua " + u + " va " + a + ":   " + low[u] + " va " + low[a] + " num: " + low[u]);

                if (low[a] > nums[u]) {
                    bridge++;
                    list[u].get(i).set(1, 1);
//                    System.out.println("bridge tăng tại " + u + " va " + a + " :" + bridge);

                }
                low[u] = min(low[a], low[u]);
            } else {
                low[u] = min(low[u], nums[a]);
//                System.out.println("co r va " + low[u]);
            }
//            System.out.println("low " + u + " = " + low[u]);
        }
    }
    public static void dfs2(int u){
        nums[u]=1;
        count++;
        for(int i=0;i<list[u].size();i++){
            int a=list[u].get(i).get(0);
            int b=list[u].get(i).get(1);
            if(nums[a]==0&&b==1){
                dfs2(a);
            }
        }
    }
}
