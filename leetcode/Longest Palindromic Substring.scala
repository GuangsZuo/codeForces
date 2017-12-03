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
