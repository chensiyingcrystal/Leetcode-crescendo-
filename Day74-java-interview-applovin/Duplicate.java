import java.util.HashSet;
import java.util.Arrays;

class Duplicate  {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> numSet = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (numSet.contains(nums[i])) {
                return true;
            } else {
                numSet.add(nums[i]);
            }
        }




        return false;
    }

    public static void main(String[] args) {
        Duplicate mm = new Duplicate();
        int[] arr = new int[] {2, 5, 1, 3, 4};
        boolean ans = mm.containsDuplicate(arr);
        System.out.println(ans);


    }
}

