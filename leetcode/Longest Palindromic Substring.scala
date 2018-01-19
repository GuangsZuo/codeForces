object Solution {
    def isPalindrome(s: String, l: Int, r:Int) :Boolean = {
        var j = r ; 
        for (i<-l to s.length()) {
            if (i>=j) return true;
            if (s(i) != s(j)) return false;
            j = j - 1; 
        }
        true; 
    }
    def longestPalindrome(s: String): String = {
    
        for (len <- s.length() to 1 by -1) {
            var slen = s.length(); 
            for (l <- 0 to slen-len) { 
               var r = l + len - 1;
               if (isPalindrome(s,l,r)) {                 
                   return s.substring(l,r+1);
               }
            }
        }
        "";
    }
}

# better solution 
object Solution {
    def longestPalindrome(s: String): String = {
        val f = Array.ofDim[Boolean](1001,1001);
        var len = s.length();
        var maxlen = 0;
        var l = 0; 
        var r = 0;
        for (i<-len-1 to 0 by -1; j<-i to len-1) {
            f(i)(j) = i match {
                case x if x==j => true ;
                case x if x==j-1 => if (s(i) == s(j)) true else false;
                case x if x<j-1 => if (s(i) == s(j)) f(i+1)(j-1) else false;
            }
            
            if (f(i)(j)==true && maxlen < j - i + 1) {
                maxlen = j - i + 1;
                l = i;
                r = j;
            }  
        }
        s.substring(l,r+1);
    }
}
