;import java.util.Scanner;

public class TSP {
    public static Scanner sc = new Scanner(System.in);
    public static final int N = 25;
    public static int n, m;
    public static int[][] graph;
    public static int result = Integer.MAX_VALUE;
    public static int res;
    public static int minV = Integer.MAX_VALUE;
    public static boolean[] visited;

    public static void main(String[] args) {
        n = sc.nextInt();
        m = sc.nextInt();
        graph = new int[n + 1][n + 1];
        visited = new boolean[n + 1];
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            minV = minV > c ? c : minV;
            graph[a][b] = c;
            graph[b][a] = c;
        }
//        System.out.println(minV);
        visited[1] = true;
        Solve(1,1);
        System.out.println(result);
    }

    public static void Solve(int k,int p) {
        for (int i = 2; i <= n; i++) {
//            System.out.println("check "+k+" va "+i);
            if (graph[p][i] != 0 && !visited[i]) {

                visited[i] = true;
                res = res + graph[p][i];
//                System.out.println("Tai " + k + " vao " + i + " co " + res);
                if (k == n - 1) {
//                    System.out.println("xet " + k + " va " + i + " co " + res + " va " + result);
                    if (graph[i][1] != 0 && res + graph[i][1] < result) {
                        result = res + graph[i][1];

                    }
                } else {
//                    System.out.println("xet " + result + " va " + (res + (n - k) * minV));
                    if (res + (n - k) * minV < result) {
                        Solve(k + 1,i);
                    }else{
                        System.out.println("vi pham");
                    }
                }
                visited[i] = false;
                res = res - graph[p][i];
            }
        }
    }
}
