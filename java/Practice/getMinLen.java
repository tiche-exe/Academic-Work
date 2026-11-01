public class getMinLen {

    //delete "AB"/"BB" from seq containing only A's & B's
    //return length
    public static int getMinLen(String seq) {

        System.out.println("\'" + seq + "\'"); //quotes so empty string is visible

        int index = seq.indexOf("AB");
        if (index == -1) { //BB (other case if not AB)
            index = seq.indexOf("BB");
        }

        //base case
        if (index == -1) {
            return seq.length();
        }

        //delete & loop
        return getMinLen(seq.substring(0, index) + seq.substring(index + 2));
    }

    public static void main(String[] args) {
        //set testcases
        System.out.println(getMinLen("BABB"));
        System.out.println();
        System.out.println(+ getMinLen("ABBA"));
        System.out.println();
        System.out.println(getMinLen("AAAA"));
        System.out.println();
        System.out.println(getMinLen("BBBB"));
        System.out.println();
        System.out.println(getMinLen(""));
    }
}