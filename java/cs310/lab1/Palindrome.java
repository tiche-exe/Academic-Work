import java.util.Scanner;

public class Palindrome {
    public static void main (String[] args){
        Scanner userInput = new Scanner(System.in);
        String s = userInput.nextLine();
        isPalindrome(s);
        if (isPalindrome(s) == true){
            System.out.println("Is Palindrome");
        }
        else{
            System.out.println("Is NOT Palindrome");
        }
    }

    public static boolean isPalindrome(String s){
        int f = 0;
        int l = s.length() - 1;
        
        while(f < l){
            if (s.charAt(f) == s.charAt(l)){
                return false;
            }
            f++;
            l--;
        }
        return true;
    }
}



//StringBuilder Way
/* public class Palindrome{
    public static void main(String[] args){
        String s = new Scanner(System.in).nextLine();
        System.out.println(isPalindrome(s) ? "Is Palindrome" : "Is NOT Palindrome");
    }

    static boolean isPalindrome(String s){
        return s.equals(new StringBuilder(s).reverse().toString());
    }
} */
