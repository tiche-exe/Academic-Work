import java.util.Arrays;

public class arrDDiff {
    public static int countTriplets(int[] arr, int d){
        Arrays.sort(arr); //used built-in sort
        int count = 0;
        int pointer = 0; //left pointer

        for(int i = 0; i < arr.length; i++){            
            
            //move leftpointer until difference is <= d to search pairs
            while(arr[i] - arr[pointer] > d){
                pointer++;
            }

            int validn = i - pointer; //amount of elements to pair up

            if (validn >= 2){
                int pairs = validn*(validn - 1) /2; //count all pairs

                count = (count + pairs) % 1000000007; //add to solution w/ mod stated: 10^9 + 7
            }
        }
        return count;
    }

    public static void main(String args[]){
        //example testcase1
        int[] arr1 = {-3, -2, -1, 0};
        System.out.println(countTriplets(arr1, 2));
        //example testcase2
        int[] arr2 = {2, 1, 3, 4};
        System.out.println(countTriplets(arr2, 3));
    }
}
