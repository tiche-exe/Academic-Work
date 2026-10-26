public class MergeKLists {

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

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                counter.next = list1;
                list1 = list1.next;
            } else {
                counter.next = list2;
                list2 = list2.next;
            }
            counter = counter.next;
        }

        if (list1 != null) {
            counter.next = list1;
        } else {
            counter.next = list2;
        }

        return merged.next;
    }

    public static ListNode mergeKLists (ListNode [] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        int interval = 1;
        while (interval < lists.length) {
            int i = 0;
            while (i + interval < lists.length) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
                i = i + interval * 2;
            }
            interval = interval * 2;
        }
        return lists[0];
    }



    public static void main(String[] args){
        ListNode list1 = new ListNode(1);
        list1.insert(7);
        list1.insert(9);

        ListNode list2 = new ListNode(4);
        list2.insert(5);
        list2.insert(12);

        ListNode list3 = new ListNode(2);
        list1.insert(8);
        list1.insert(10);

        ListNode list4 = new ListNode(5);
        list2.insert(7);
        list2.insert(14);

        ListNode list5 = new ListNode(6);
        list2.insert(9);
        list2.insert(16);

        ListNode temp = mergeKLists(new ListNode[] {list1, list2, list3, list4, list5});

        ListNode merged = temp;
        while(merged != null){
            System.out.print(merged.val + " ");
            merged = merged.next;
        }
    }
}