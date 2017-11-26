package com.panchao.datastructure.introduction.chapterone;

import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;
/**
 * 
 * @ClassName:SelectionProblemTest
 * @Description:TODO 选择问题(设有一组N个数而要确定其中第k个最大者)测试类
 * @author PANCHAO
 * @date 2017年10月2日 下午10:42:02
 *
 */
public class SelectionProblemTest {
	private static int[] nums = new int[100000];
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		for (int i = 0; i < nums.length; i++) {
			nums[i] = i;
		}
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
		nums = null;
	}
	/**
	 * 使用冒泡排序法对数组进行排序，并返回第<code>k</code>个最大者    测试方法
	 */
	@Test
	public void testbubblesort() {
		Assert.assertEquals(99997, SelectionProblem.bubblesort(nums, 3));
	}
	/**
	 * 对数组进行排序，并返回第<code>k</code>个最大者    测试方法
	 */
	@Test
	public void decreaseprogressively() {
		Assert.assertEquals(99997, SelectionProblem.bubblesort(nums, 3));
	}

}
