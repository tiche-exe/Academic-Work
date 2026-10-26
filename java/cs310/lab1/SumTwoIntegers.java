import java.util.Scanner;
import java.util.HashMap;
import java.util.Arrays;

public class SumTwoIntegers {
    public static void main (String[] args){
        Scanner userInput = new Scanner(System.in);

        System.out.println("Input target value:");
        int target = userInput.nextInt();

        System.out.println("Enter array size:");
        int size = userInput.nextInt(); 
        int nums[] = new int[size];

        System.out.println("Enter array values:");
        for (int i = 0; i < size; i++){
            nums[i] = userInput.nextInt();
        }

        System.out.println(Arrays.toString(twoSum(nums, target)));
    }

    public static int [] twoSum (int [] nums , int target){
        int solution[] = {-1,-1};
        HashMap<Integer, Integer> checked = new HashMap<>();

        for(int i = 0; i < nums.length; i++){
            int remains = target - nums[i];
            if (checked.containsKey(remains)){
                solution[0] = checked.get(remains);
                solution[1] = i;
                return solution;
            }
            checked.put(nums[i], i);
        }
        return solution;
    }
}