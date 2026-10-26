import java.util.Scanner;

public class LowerCaseVowels{
    public static void main(){
        Scanner userInput = new Scanner(System.in);
        System.out.println("Input String: ");
        String str = userInput.nextLine();

        int count = 0;

        for(char c : str.toCharArray()){
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                count++;
            }
        }

        System.out.println("the string has " + count + " vowels");
    }
}