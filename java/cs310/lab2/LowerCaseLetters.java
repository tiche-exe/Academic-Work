import java.util.Scanner;

public class LowerCaseLetters {
    public static void main(String[] args) {
        Scanner userInput = new Scanner(System.in);

        System.out.println("Input the lowercase letters: ");
        String lettersInput = userInput.nextLine();
        String letters = lettersInput.replaceAll("[,\\s]", "");

        System.out.println("Input String: ");
        String str = userInput.nextLine();

        int count = 0;

        for (char letter : str.toCharArray()) {
            if (letters.indexOf(letter) != -1) {
                count++;
            }
        }
        if (count == 1) {
            System.out.println("the string has one lowercase letter defined by me");
        } else {
            System.out.println("the string has " + count + " lowercase letters defined by me");
        }

        userInput.close();
    }
}
