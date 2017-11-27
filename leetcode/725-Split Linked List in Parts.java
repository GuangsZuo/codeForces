/**
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
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
