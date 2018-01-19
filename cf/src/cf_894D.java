/**
 * Created by zgs on 2017/12/3.
 */

import java.util.*;
import java.io.*;
public class cf_894D {
    public static int n = 0, m = 0 ;
    public static int w[] = new int[1000000];
    public static Map<Integer, List<Integer>> map = new HashMap<>();
    public static Map<Integer, List<Integer>> mapS = new HashMap<>();
    public static int max_level = (int) Math.floor(Math.log(i) / Math.log(2)) ;
    public static void main(String[] args){
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        n = cin.nextInt();
        m = cin.nextInt();
        for (int i=1; i<n; ++i) w[i] = cin.nextInt();
        tree_merge_sort();
        for (int i=1; i<=m; ++i) {
            int a = cin.nextInt();
            int h = cin.nextInt();
            get_gain_H(a,h);
        }
    }
    public static void tree_merge_sort() {
        for (int node = n; node >= 1; node --) {
            List<Integer> temp = new ArrayList<>(get_child_nums(node)) ;
            temp.add(0);
            if (node * 2 + 1 <= n) merge(map.get(node * 2), map.get(node * 2 + 1), temp, w[node*2], w[node*2+1]);
            else if (node * 2 <= n) merge(map.get(node * 2), new ArrayList<>(0), temp, w[node*2], 0);
            map.put(node, temp);
            List<Long> tempS = new ArrayList<>(temp.size());
            long sum = 0 ;
            for (int e :temp) {
                sum += e ;
                tempS.add(sum) ;
            }
            mapS.put(node, tempS);
        }
    }
    public static void merge(List<Integer> a, List<Integer> b, List<Integer> c, int a_, int b_) {
        int j = 0 , i = 0;
        for (; i<a.size() && j<b.size(); ) {
            if (a.get(i) + a_ <= b.get(j) + b_)  {
                c.add(a.get(i) + a_);
                ++ i;
            } else {
              c.add(b.get(j) + b_);
              ++ j;
            }
        }
        for (; i<a.size(); ++i) c.add(a.get(i) + a_);
        for (; j<=b.size(); ++j) c.add(b.get(j) + b_);
    }
    public static int get_child_nums(int i){
        int level = (int) Math.floor(Math.log(i)/Math.log(2)) ;
        return ((int)1) << (max_level - level + 1);
    }
    public static long  get_gain_H(int a, long h) {
        long gain_H  = 0 ;
        int level = a;
        while (level>=1) {
            List<Integer> order = map.get(a);
            int l = 0 , r = order.size()-1, mid;
            while (l < r - 1) {
                mid = l + r >> 1;
                if (order.get(mid)<h) l = mid ;
                else r = mid - 1;
            }
            if (order.get(r) > h) l = r;
            gain_H += h*(l+1) - mapS.get(a).get(l);
            h -= w[a-1];
            level = level >> 1;
            if (h<=0) break;
            gain_H += h;
            a = a | 1 ;
            if (a > n)

        }
    }
}
