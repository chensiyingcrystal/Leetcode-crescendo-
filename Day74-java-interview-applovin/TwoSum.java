import java.util.HashMap;
import java.util.Arrays;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();

        for(int i = 0; i < nums.length; i++) {
            int compliment = target - nums[i];

            if (numMap.containsKey(compliment)) {
                return new int[] {numMap.get(compliment), i};
            } else {
                numMap.put(nums[i], i);
            }
        }

        return null;

    }

    public static void main(String[] args) {
        TwoSum tt = new TwoSum();
        int[] arr = new int[] {2, 7, 11, 15};
        int[] ans = tt.twoSum(arr, 9);
        System.out.println(Arrays.toString(ans));


    }
}

