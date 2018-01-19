/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
object Solution {
    val t = Array.ofDim[Int](100000,2);
    val Max : (Int, Int)=>Int = (x,y)=> if (x>y) x else y
    val Min : (Int, Int)=>Int = (x,y)=> if (x<y) x else y
    def buildTree(a: Array[Int], p: Int, x: Int, y:Int): Unit = {
        if (x == y) {
           t(p)(0) = a(x-1)
           t(p)(1) = a(x-1)
           return
        }
        val mid = x + y >> 1
        buildTree(a, p<<1, x, mid)
        buildTree(a, p<<1|1, mid+1, y)
        t(p)(0) = Max(t(p<<1)(0),t(p<<1|1)(0))
        t(p)(1) = Min(t(p<<1)(1),t(p<<1|1)(1))
        return
    }
    def find(p: Int, l: Int, r: Int, x:Int, y:Int, m:Int):Int = {
        if (x>r || y<l) return {
            m match {
                case 0 => 0
                case 1 => 2147483640
            }
        }
        if (x<=l && r<=y) return t(p)(m)
        val mid = l + r >> 1
        m match {
            case 0 => Max(find(p<<1,l,mid,x,y,m), find(p<<1|1,mid+1,r,x,y,m))
            case 1 => Min(find(p<<1,l,mid,x,y,m), find(p<<1|1,mid+1,r,x,y,m))
        }
    }
    def maxArea(height: Array[Int]): Int = {
        var i = 0
        val p = height.map{h => i+=1; (h,i)}.sorted
        val p_x:Array[Int] = p.map{x => x._2}
        val n = p_x.size
        buildTree(p_x, 1, 1, n)
        var ans = 0 
        i = 0 
        p.foreach(x =>{ 
           i += 1
           val x_1 = find(1,1,n, i, n, 0)
           val x_2 = find(1,1,n, i, n, 1)
          // println(i," ",x, " ", x_1, " ", x_2)
           if (x_1 > x._2) ans = if (ans < (x_1 - x._2) * x._1) (x_1 - x._2) * x._1 else ans 
           if (x_2 < x._2) ans = if (ans < (x._2 - x_2) * x._1) (x._2 - x_2) * x._1 else ans 
        })
        ans 
    }
}
