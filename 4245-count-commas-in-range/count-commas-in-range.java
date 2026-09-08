class Solution {
    public int countCommas(int n) {
        long total = 0;
        long pow = 1;
        int d = 1, commas = 0;
        while (pow <= n) {
            long nextPow = pow * 10;
            long count = Math.min(nextPow - 1, n) - pow + 1;
            total += count * commas;
            if (d % 3 == 0) commas++;   
            pow = nextPow;
            d++;
        }
        return (int) total;
    }
}