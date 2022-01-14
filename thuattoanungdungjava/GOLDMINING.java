import com.sun.security.jgss.GSSUtil;

import java.util.*;

public class GOLDMINING {
    public static final int N = 1000001;
    public static Scanner sc = new Scanner(System.in);
    public static int n, L1, L2;
    public static int result = 0;
    public static int[] locate;
    public static int[] res;
    public static Deque<Integer> q = new LinkedList<>();

    public static void main(String[] args) {
        n = sc.nextInt();
        L1 = sc.nextInt();
        L2 = sc.nextInt();
        locate = new int[N];
        res = new int[N];
        for (int i = 1; i <= n; i++) {
            locate[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            //System.out.println("xet tai "+i);
            if (i <= L1) {
                res[i] = locate[i];
            } else {
                while (!q.isEmpty() && q.peekFirst() < (i - L2)) {
                    int xoa = q.removeFirst();
                    //System.out.println("xoa do ngoai vong lap "+xoa);
                }
                while (!q.isEmpty() && res[q.peekLast()] < res[i - L1]) {
                    int xoa = q.removeLast();
                    //System.out.println("thanh loc "+xoa);
                }
                q.addLast(i - L1);
                //System.out.println("bo sung"+(i-L1));
                res[i] = res[q.peekFirst()] + locate[i];
                //System.out.println("res="+res[i]);

            }
            if (result < res[i]) {
                result = res[i];
            }
        }
        System.out.println(result);
    }
}
