import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

import static java.lang.Math.max;

public class HIST {
    public static Scanner sc = new Scanner(System.in);
    public static final int N = 1000000;
    public static int res = 0;

    public static void main(String[] args) {
        while (true) {
            int n = sc.nextInt();
            if (n == 0) {
                break;
            }
            ArrayList<Integer> hist = new ArrayList<>(n + 1);
            hist.add(-1);
            Stack<Integer> h = new Stack<>();
            Stack<Integer> s = new Stack<>();
            for (int i = 1; i <= n; i++) {
                hist.add(sc.nextInt());
            }
            h.add(hist.get(0));
            s.add(0);
            for (int i = 1; i <= n; i++) {
                int start=i;
                while (!h.isEmpty() && h.peek() > hist.get(i)) {
                    int height = h.pop();
                    start = s.pop();
                    int tmp = height * (i - start);
                    res = max(res, tmp);
                    System.out.println("nho hon pop "+height+" ---- "+start+" ------ "+tmp+" ---- "+res);
                }
                if (h.peek() < hist.get(i)) {
                    System.out.println("lon hon"+ h.peek() +" add "+hist.get(i)+" tai "+i);
                    h.add(hist.get(i));
                    s.add(start);
                }
            }
            while (!h.isEmpty()) {
                int height = h.pop();
                int start = s.pop();
                int tmp = height * (n + 1 - start);
                res = max(res, tmp);
                System.out.println("ton dong pop "+height+" ---- "+start+" ------ "+tmp+" ---- "+res);
            }
            System.out.println(res);
        }
    }
}
