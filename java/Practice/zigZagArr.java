import java.util.Arrays;

public class zigZagArr {

    public static int[] zigzag(int[] numbers) {
        
        int[] solution = new int[numbers.length - 2];

        for (int i = 0; i < numbers.length - 2; i++) {
            int a = numbers[i];
            int b = numbers[i + 1];
            int c = numbers[i + 2];

            if ((a < b && b > c) || (a > b && b < c)) {
                solution[i] = 1;
            } else {
                solution[i] = 0;
            }
        }
        return solution;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 3, 2};
        System.out.println(Arrays.toString(zigzag(arr1)));
        int[] arr2 = {4, 6, 7, 1, 9, 3};
        System.out.println(Arrays.toString(zigzag(arr2)));
        int[] arr3 = {1, 0, 2};
        System.out.println(Arrays.toString(zigzag(arr3)));
    }
}