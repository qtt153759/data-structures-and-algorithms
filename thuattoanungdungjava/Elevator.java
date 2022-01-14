import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Elevator {
    private static final int N = 1000001 ;
    static int f,  s, g, u, d;
    static Scanner sc=new Scanner(System.in);
    static int[] res=new int[N];
    public static void main(String[] args) {
        f=sc.nextInt();
        s=sc.nextInt();
        g=sc.nextInt();
        u=sc.nextInt();
        d=sc.nextInt();
        Queue<Integer>q=new LinkedList<>();
        res[s]=0;
        q.add(s);
        while(!q.isEmpty()){
            int tmp=q.remove();
            if(tmp==g){
                System.out.println(res[g]);
                return ;
            }
            if(tmp+u<=f&&res[tmp+u]==0&&s!=tmp+u){
                res[tmp+u]=res[tmp]+1;
                q.add(tmp+u);
            }
            if(tmp-d>=0&&res[tmp-d]==0&&s!=tmp-d){
                res[tmp-d]=res[tmp]+1;
                q.add(tmp-d);
            }
        }
        System.out.println("use the stairs");
    }
}
