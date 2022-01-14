import javax.sound.midi.Soundbank;
import java.util.*;

public class BCA {
    public static int m;
    public static int n;
    public static int result=Integer.MAX_VALUE;
    public static int current;
    public static HashMap<Integer,ArrayList<Integer>> map;
    public static boolean[][]conflict;
    public static ArrayList<Integer>res[];
    public static int [] save;
    public static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        m=sc.nextInt();
        n=sc.nextInt();
        map=new HashMap<>(m+1);
        res=new ArrayList[m+1];
        save=new int[m+1];
        conflict=new boolean[n+1][n+1];
        for(int i=1;i<=m;i++){
            map.put(i,new ArrayList<>());
            res[i]=new ArrayList<>();
            int k=sc.nextInt();
            for(int j=1;j<=k;j++){
                map.get(i).add(sc.nextInt());
            }
        }
        int k= sc.nextInt();
        for(int i=1;i<=k;i++){
            int a=sc.nextInt();
            int b=sc.nextInt();
            conflict[a][b]=true;
        }
        Solve(1);
        System.out.println(result);
    }
    public static boolean check (int k,int i){
        if(map.get(i).contains(k)){
            if(res[i].isEmpty()){
                //System.out.println(i+"rong dc phep nhet "+k);
                return true;
            }
            for(int tmp:res[i]){
                if(conflict[tmp][k]==true){
//                    System.out.println("conflic tai "+i+" do tmp "+tmp+" k "+k);
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    public static void Solve(int k){
        for(int i=1;i<=m;i++){
//            System.out.println("Xet k "+k+" va i "+i);
            if(check(k,i)){
                res[i].add(k);
                save[i]++;
                int tmp=0;
                for(int j=1;j<save.length;j++){
                    tmp=tmp<save[j]?save[j]:tmp;
                }
                current=tmp;
//                System.out.println("check ok k "+k+" va i "+i+" current "+current);
                if(k==n){
                    result=result>current?current:result;
                    //System.out.println("update result "+result);
                    //System.out.println("================================");
                    for(int t=1;t<res.length;t++){
                        //System.out.print("finish "+t+" : ");
                        for(int o:res[t]){
                            //System.out.print(o+" ");
                        }
                    }
                    //System.out.println("================================");
                }else{
                    //System.out.println("xet current "+current+" va result "+result);
                    if(current<result){
                        Solve(k+1);
                    }
                }
                res[i].remove(new Integer(k));
                save[i]--;
            }
        }
    }
}
