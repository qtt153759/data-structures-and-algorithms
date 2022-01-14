import java.util.*;

public class POSTMAN {
    public static Scanner sc=new Scanner(System.in);
    static long n=sc.nextInt();
    static long k=sc.nextInt();
    static long res=0;
    public static void main(String[] args) {
         ArrayList<ArrayList<Long>>disL=new ArrayList<>();
         ArrayList<ArrayList<Long>>disR=new ArrayList<>();

        long a,b;
        for(int i=0;i<n;i++){
            a=sc.nextInt();
            b=sc.nextInt();
            if(a>0){
                disR.add(new ArrayList<>(Arrays.asList(a,b)));
            }else if(a<0){
                disL.add(new ArrayList<>(Arrays.asList(-a,b)));
            }
        }
        res=Solve(disR)+Solve(disL);
        System.out.println(res);
    }
    public static long Solve(ArrayList<ArrayList<Long>>dis){

        long kq=0;
        Collections.sort(dis,(a,b)->{
            return (int) (b.get(0) -a.get(0));
        }
        );
        long tmp,remain;
        for(int i=0;i< dis.size();i++){
//            System.out.println("voi "+dis.get(i).get(0)+" va "+dis.get(i).get(1));
            tmp=dis.get(i).get(1)/k;
            if(dis.get(i).get(1)-tmp*k>0){
                remain=(tmp+1)*k-dis.get(i).get(1);
            }else{
               remain=tmp*k-dis.get(i).get(1);
                kq=kq+2*dis.get(i).get(0)*tmp;
//                System.out.println(" = "+kq);
                continue;
            }
//            System.out.println("tmp:"+tmp+" va remain "+remain);
            int j=i+1;
            while (remain>0&&j<dis.size()){
                if(remain<=dis.get(j).get(1)){
                    dis.get(j).set(1,dis.get(j).get(1)-remain);
                    remain=0;
                }else{
                    remain=remain-dis.get(j).get(1);
                    dis.get(j).set(1, 0L);
                }
                j++;
            }
            kq=kq+2*dis.get(i).get(0)*(tmp+1);
//            System.out.println(" = "+kq);
        }
        return kq;
    }

}
