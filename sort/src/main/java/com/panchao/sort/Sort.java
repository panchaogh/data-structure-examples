package com.panchao.sort;

import java.util.Arrays;

public class Sort {
	/**
	 * 插入排序
	 * @param nums
	 * @return
	 */
	public static int[] insertionSort(int[] nums) {
		for (int i = 1; i < nums.length; i++) {
			int tmp = nums[i];
			int j;
			for (j = i; j > 0 && tmp<nums[j-1]; j--) {
				nums[j] = nums[j-1];
			}
			nums[j] = tmp;
		}
		return nums;
	}
	/**
	 * 冒泡排序
	 * @param nums
	 * @return
	 */
	public static int[] bubbleSort(int[] nums) {
		for (int i = nums.length-1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (nums[j] > nums[j+1]) {
					int tmp = nums[j];
					nums[j] = nums[j+1]; 
					nums[j+1] = tmp;
				}
			}
		}
		return nums;
	}
	public static void main(String[] args) {
		int[] nums = {3,5,4,5,4,6,8,9,5,53,2,43,6,8,5,3,6};
		int[] insertionSort = insertionSort(nums);
		System.out.println(Arrays.toString(insertionSort));
		int[] nums1 = {3,5,4,5,4,6,8,9,5,53,2,43,6,8,5,3,6};
		int[] bubbleSort = bubbleSort(nums1);
		System.out.println(Arrays.toString(bubbleSort));
	}
}
