import java.util.Scanner;

public class exercise2 {

    public static boolean evenone(String str) {
        int count = 0; // number of 1s seen
        for (char c : str.toCharArray()) {
            if (c == '1') {
                count++;
            }
        }
        return count > 0 && count % 2 == 0; // "0 0 0 0" must give False
    }

    public static void main(String args[]) {
        Scanner userInput = new Scanner(System.in);
        System.out.print("String: ");
        String input = userInput.nextLine().replace(" ", "");
        System.out.println(evenone(input) ? "True" : "False");
        userInput.close();
    }
}