class Solution {
    public boolean makesquare(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 4 != 0) {
            return false;
        }

        Arrays.sort(nums);
        reverse(nums);
        int[] squareEdge = new int[4];
        return recMakeSquare(0, squareEdge, nums, sum / 4);
    }

    public boolean recMakeSquare(int index, int[] squareEdge, int[] nums, int target) {
        if (index == nums.length) {
            return squareEdge[0] == squareEdge[1] && squareEdge[1] == squareEdge[2];
        }

        for (int i = 0; i < 4; i++) {
            if (squareEdge[i] + nums[index] > target) {
                continue;
            }

            squareEdge[i] += nums[index];
            if (recMakeSquare(index + 1, squareEdge, nums, target)) {
                return true;
            }
            squareEdge[i] -= nums[index];
        }
        return false;
    }

    public void reverse(int[] nums) {
        for (int i = 0; i < nums.length / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.length - 1 - i];
            nums[nums.length - 1 - i] = temp;
        }
    }
}