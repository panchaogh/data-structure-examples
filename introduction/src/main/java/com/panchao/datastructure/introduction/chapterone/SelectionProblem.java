package com.panchao.datastructure.introduction.chapterone;
/**
 * 
 * @ClassName:SelectionProblem
 * @Description:TODO 选择问题(设有一组N个数而要确定其中第k个最大者)
 * @author PANCHAO
 * @date 2017年10月2日 下午10:39:09
 *
 */
public class SelectionProblem {
	/**
	 * sfdsfas23xvfdgd的非官方的手感还是高仿的
	 * @Title: bubblesort
	 * @Description: 使用冒泡排序法对数组进行排序，并返回第k个最大者
	 * @param nums
	 * 			对数组<code>nums</code>进行冒泡排序
	 * @param k
	 * 			返回第<code>k</code>个最大者
	 * @return int    返回类型
	 * 			返回第k个最大者
	 * @throws
	 */
	/**
	 * 使用冒泡排序法对数组进行排序，并返回第<code>k</code>个最大者
	 * @param nums
	 * 			对数组<code>nums</code>进行冒泡排序
	 * @param k
	 * 			返回第<code>k</code>个最大者
	 * @return int
	 * 			返回第k个最大者		
	 */
	public static int bubblesort(int[] nums,int k){
		int temp = 0;
		/*
		 * 冒泡排序(递减顺序)
		 */
		for (int i = nums.length-1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if(nums[j]<nums[j+1]){
					temp = nums[j+1];
					nums[j+1] = nums[j];
					nums[j] = temp;
				}
			}
		}
		/*
		 * 返回第k个最大值
		 */
		return nums[k-1];
	}
	/**
	 * 对数组进行排序，并返回第<code>k</code>个最大者
	 * @param nums
	 * 			对数组<code>nums</code>进行冒泡排序
	 * @param k
	 * 			返回第k个最大者
	 * @return int
	 * 			返回第k个最大者	
	 */
	public static int decreaseprogressively(int[] nums,int k){
		/*
		 * 将nums的前k个数读入sorts中
		 */
		int[] sorts = new int[k];
		for (int i = 0; i < k; i++) {
			sorts[i] = nums[i];
		}
		/*
		 * 对sorts进行递减排序
		 */
		bubblesort(sorts, 1);
		int[] temps = new int[k+1];
		/*将sorts拷贝到temps*/
		System.arraycopy(sorts, 0, temps, 0, sorts.length);
		/*
		 * 将nums剩下的元素逐个读入，当新元素被读到时，如果它小于数组中的第k个元素则忽略之，
		 * 否则就将其放入正确的位置，同时将数组中的一个元素挤出，
		 * 当算法终止时，位于第k个元素作为答案返回
		 */
		for (int i = k; i < nums.length; i++) {
			temps[k] = nums[i];
			/*
			 * 对temps进行递减排序
			 */
			bubblesort(temps, 0);
		}
		System.arraycopy(temps, 0, sorts, 0, temps.length-1);
		System.out.println(sorts.length == k);
		return sorts[k-1];
	}
}
