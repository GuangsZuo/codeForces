/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        int n = 0;
        ListNode[] ans = new ListNode[k];
        for (ListNode p = root; p != null ; p = p.next)
            n = n + 1;
        int d = n / k, c = n % k;
        if (k >= n) {
            d = 1;
            c = 0;
        }
        ListNode iterator = root;
        for (int i = 0; i < k; ++ i) {
            int has = 0; 
            int shouldHas = i < c ? d + 1 : d ;
            ans[i] = iterator;
            while (iterator != null) {
                has += 1;  
                if (has >= shouldHas) {
                    ListNode temp = iterator.next;
                    iterator.next = null ;
                    iterator = temp;
                    break;
                }
                iterator = iterator.next;
            }
        }
        return ans;
    }
}
