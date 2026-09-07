class Solution {
    public int distinctSubseqII(String s) {
        final int MOD = 1_000_000_007;
        int[] end = new int[26];
        int total = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            int newEnd = total + 1;
            if (newEnd >= MOD) newEnd -= MOD;
            total = total - end[idx] + newEnd;
            if (total < 0) total += MOD;
            if (total >= MOD) total -= MOD;   
            end[idx] = newEnd;
        }
        return total;
    }
}