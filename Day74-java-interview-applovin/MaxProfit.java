import java.util.HashMap;
import java.util.Arrays;

class MaxProfit {
    public int maxProfit(int[] prices) {
        int maxProfit = Integer.MIN_VALUE;
        int minPrice = Integer.MAX_VALUE;

        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        MaxProfit mm = new MaxProfit();
        int[] arr = new int[] {2, 5, 1, 3, 4};
        int ans = mm.maxProfit(arr);
        System.out.println(ans);


    }
}

