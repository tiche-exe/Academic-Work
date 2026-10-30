import java.util.Arrays;

public class millingMachine{
    public static int minMoves(String[] tools, int startIndex, String target){

        int solution = Integer.MAX_VALUE; //has to big enough number so that if the array is the max value for an integer it still works
        int rightMoves = 0 ; //counter for right moves
        int leftMoves = 0; //counter for left moves
        
        //go through the array
        for (int i = 0; i < tools.length; i++){
            if (tools[i].equals(target)){//if we found target we check the moves
                rightMoves = (i - startIndex + tools.length) % tools.length; //+ n) % n -> changes neg diff into [0, n) for the wrap-around
                leftMoves = (startIndex - i + tools.length) % tools.length; //same thing but other side (flip startIndex and i)
                solution = Math.min(solution, Math.min(leftMoves, rightMoves)); //compare which way had less moves
            }
        }
        return solution;
    }
    
    public static void main (String args[]){
        //example testcase1
        String[] tools1 = {"ballendmill", "keywaycutter", "slotdrill", "facemill"};
        System.out.println(minMoves(tools1, 1, "ballendmill"));
        //example testcase2
        String[] tools2 = {"ballendmill", "keywaycutter", "slotdrill", "facemill"};
        System.out.println(minMoves(tools2, 2, "ballendmill"));
    }
}
