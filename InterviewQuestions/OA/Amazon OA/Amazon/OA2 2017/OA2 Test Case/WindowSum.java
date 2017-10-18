package OA2secondRound;

import java.util.*;

public class WindowSum {
	public List<Integer> windowSum(int[] nums, int k) {
		// write your code here
		
	}
	
	public static void main(String[] argc) {
		WindowSum test = new WindowSum();
		
		// test case 1
		int[] nums1 = {1,2,3,4,5,6,7};
		int k1 = 3;
		List<Integer> sums1 = test.windowSum(nums1, k1);
		System.out.print("Original nums:");
		test.print(nums1);
		System.out.println(" k = " + k1);
		System.out.print("window sums: ");
		test.print(sums1);
		System.out.println();
		
		// test case 2
		int[] nums2 = {-1,-3,-8,10,16,-4,7};
		int k2 = 2;
		List<Integer> sums2 = test.windowSum(nums2, k2);
		System.out.print("Original nums:");
		test.print(nums2);
		System.out.println(" k = " + k2);
		System.out.print("window sums: ");
		test.print(sums2);
		System.out.println();
		
		// test case 3
		int[] nums3 = {-1,-5, Integer.MAX_VALUE-6 ,4,-7,6};
		int k3 = 2;
		List<Integer> sums3 = test.windowSum(nums3, k3);
		System.out.print("Original nums:");
		test.print(nums3);
		System.out.println(" k = " + k3);
		System.out.print("window sums: ");
		test.print(sums3);
		System.out.println();
		
		// test case 4
		int[] nums4 = {1,-5,Integer.MAX_VALUE, 5};
		int k4 = 3;
		List<Integer> sums4 = test.windowSum(nums4, k4);
		System.out.print("Original nums:");
		test.print(nums4);
		System.out.println(" k = " + k4);
		System.out.print("window sums: ");
		test.print(sums4);
		System.out.println();
		
		// test case 5
		int[] nums5 = {Integer.MIN_VALUE, 1, 0};
		int k5 = 2;
		List<Integer> sums5 = test.windowSum(nums5, k5);
		System.out.print("Original nums:");
		test.print(nums5);
		System.out.println(" k = " + k5);
		System.out.print("window sums: ");
		test.print(sums5);
		System.out.println();
		
		// test case 6
		int[] nums6 = {3,4,-5,2,6,7};
		int k6 = 0;
		List<Integer> sums6 = test.windowSum(nums6, k6);
		System.out.print("Original nums:");
		test.print(nums6);
		System.out.println(" k = " + k6);
		System.out.print("window sums: ");
		test.print(sums6);
		System.out.println();
		
		// test case 7
		int k7 = -5;
		List<Integer> sums7 = test.windowSum(nums6, k7);
		System.out.print("Original nums:");
		test.print(nums6);
		System.out.println(" k = " + k7);
		System.out.print("window sums: ");
		test.print(sums7);
		System.out.println();
		
		// test case 8
		int k8 = 20;
		List<Integer> sums8 = test.windowSum(nums6, k8);
		System.out.print("Original nums:");
		test.print(nums6);
		System.out.println(" k = " + k8);
		System.out.print("window sums: ");
		test.print(sums8);
		System.out.println();
		
		// test case 9
		int[] nums9 = new int[0];
		int k9 = 8;
		List<Integer> sums9 = test.windowSum(nums9, k9);
		System.out.print("Original nums:");
		test.print(nums9);
		System.out.println(" k = " + k9);
		System.out.print("window sums: ");
		test.print(sums9);
		System.out.println();
		
		// test case 10
		int[] nums10 = {0,-5,6,3,-8,34,-9};
		int k10 = 7;
		List<Integer> sums10 = test.windowSum(nums10, k10);
		System.out.print("Original nums:");
		test.print(nums10);
		System.out.println(" k = " + k10);
		System.out.print("window sums: ");
		test.print(sums10);
		System.out.println();
		
		// test case 11
		int[] nums11 = {0,0,0,0,0,0};
		int k11 = 3;
		List<Integer> sums11 = test.windowSum(nums11, k11);
		System.out.print("Original nums:");
		test.print(nums11);
		System.out.println(" k = " + k11);
		System.out.print("window sums: ");
		test.print(sums11);
		System.out.println();
	}
	
	private void print(int[] nums) {
		if(nums == null || nums.length == 0) return;
		System.out.print(nums[0]);
		for(int i = 1; i < nums.length; i++) {
			System.out.print(", " + nums[i]);
		}
	}
	
	private void print(List<Integer> sums) {
		if(sums == null || sums.size() == 0) return;
		System.out.print(sums.get(0));
		for(int i = 1; i < sums.size(); i++) {
			System.out.print(", " + sums.get(i));
		}
	}
}
