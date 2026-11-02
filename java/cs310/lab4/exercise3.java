import java.util.Scanner;

public class exercise3 {

    public static boolean evenoneorzero(String str) {
        boolean zeros = true; // start: zero 0s seen, which is even
        boolean ones = true;  // start: zero 1s seen, which is even
        for (char c : str.toCharArray()) {
            if (c == '0') {
                zeros = !zeros; // each 0 flips between even and odd
            } else if (c == '1') {
                ones = !ones;   // each 1 flips between even and odd
            }
        }
        return zeros || ones;
    }

    public static void main(String args[]) {
        Scanner userInput = new Scanner(System.in);
        System.out.print("String: ");
        String input = userInput.nextLine().replace(" ", "");
        System.out.println(evenoneorzero(input) ? "True" : "False");
        userInput.close();
    }
}