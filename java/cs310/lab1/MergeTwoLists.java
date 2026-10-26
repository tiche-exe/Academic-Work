public class MergeTwoLists {

    static class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val = x;
        }

        void insert(int x) {
            ListNode current = this;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new ListNode(x);
        }
    }

    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode merged = new ListNode(0);
        ListNode counter = merged;

        while (list1 != null && list2 != null){
            if (list1.val <= list2.val){

                counter.next = list1;
                list1 = list1.next;
                counter = counter.next;
            }
            else{
                counter.next = list2;
                list2 = list2.next;
                counter = counter.next;
            }
        }

        if (list1 != null){
            counter.next = list1;
        }
        else{
            counter.next = list2;
        }

        return merged.next;
    }

    public static void main(String[] args){
        ListNode list1 = new ListNode(1);
        list1.insert(7);
        list1.insert(9);

        ListNode list2 = new ListNode(4);
        list2.insert(5);
        list2.insert(12);

        ListNode temp = mergeTwoLists(list1, list2);

        ListNode merged = temp;
        while(merged != null){
            System.out.print(merged.val + " ");
            merged = merged.next;
        }
    }
}