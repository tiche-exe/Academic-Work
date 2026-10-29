import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class Lab3Part2{
    public static void main(String[] args) {
        Set<Character> L = new HashSet<>(); //Letters
        Set<Integer> D = new HashSet<>(); //Digits

        for (char c = 'A'; c <= 'Z'; c++){
            L.add(c);
        }
        for (char c = 'a'; c <= 'z'; c++){
            L.add(c);
        }

        for (int n = 0; n <= 9; n++){
            D.add(n);
        }

        System.out.println("Set L: " + L + "\n");
        System.out.println("Set D: " + D + "\n");

        //L U D
        Set<Object> U = new HashSet<>(); //union
        U.addAll(L);
        U.addAll(D);
        System.out.println("L U D: " + U + "\n");
        System.out.println("L U D elements: " + U.size() + "\n");

        //LD
        Set<Object> LD = new LinkedHashSet<>(); //concatenation
        for (char l : L){
            for (int d : D){
                LD.add("" + l + d);
            }
        }
        System.out.println("LD: " + LD + "\n");
        System.out.println("LD elements: " + LD.size() + "\n");

        //L^4
        int count = 0;
        outer:
        for (char a : L){
            for (char b : L){
                for (char c : L){
                    for (char d : L) {
                        System.out.println("L^4 elements: " + a + b + c + d);
                        if (++count == 3) break outer;
                    }
                }
            }
        }

        //D+
        System.out.println("\n");

        count = 0;
        for (int d : D){
            System.out.println("D+ element: " + d);
            if (++count == 3) break;
        }
    }
}
