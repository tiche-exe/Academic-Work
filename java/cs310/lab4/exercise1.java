import java.util.Scanner;

public class exercise1 {

    public static boolean evenzero(String str) {
        boolean result = true; // start: zero 0s seen, which is even
        for (char c : str.toCharArray()) {
            if (c == '0') {
                result = !result; // each 0 flips between even and odd
            }
        }
        return result;
    }

    public static void main(String args[]) {
        Scanner userInput = new Scanner(System.in);
        System.out.print("String: ");
        String input = userInput.nextLine().replace(" ", "");
        System.out.println(evenzero(input) ? "True" : "False");
        userInput.close();
    }
}
