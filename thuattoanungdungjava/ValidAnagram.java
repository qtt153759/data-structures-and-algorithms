import java.util.HashMap;
import java.util.Scanner;

public class ValidAnagram {
    public static Scanner sc=new Scanner(System.in);
    public static String s1;
    public static String s2;
    public static HashMap<Character,Integer>map1=new HashMap<>();
    public static HashMap<Character,Integer>map2=new HashMap<>();
    public static void main(String[] args) {
        s1=sc.nextLine();
        s2=sc.nextLine();
        if(s1.length()!=s2.length()){
            System.out.println("kich thuoc khong giong nhau");
            return;
        }
        else{
            for(int i=0;i<s1.length();i++){
                map1.putIfAbsent(s1.charAt(i),0);
                map2.putIfAbsent(s2.charAt(i),0);
                map1.put(s1.charAt(i),map1.get(s1.charAt(i))+1);
                map2.put(s2.charAt(i),map2.get(s2.charAt(i))+1);
            }
            for(char c: map1.keySet()){
                if(map1.getOrDefault(c,0)!=map2.getOrDefault(c,0)){
                    System.out.println("không Anagram do tai "+c+" co "+map1.getOrDefault(c,0)+" khac "+map2.getOrDefault(c,0));
                    return;
                }
            }
        }
        System.out.println("valid anagram");
    }
}
