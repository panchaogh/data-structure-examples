package com.panchao.datastructure.introduction.chapterone;

import org.junit.Assert;
import org.junit.Test;

public class RecursionTest {

	@Test
	public void testgetImplement() {
		Assert.assertEquals(0, Recursion.getImplement(0));
		Assert.assertEquals(1, Recursion.getImplement(1));
		Assert.assertEquals(6, Recursion.getImplement(2));
		Assert.assertEquals(21, Recursion.getImplement(3));
		Assert.assertEquals(58, Recursion.getImplement(4));
	}

}
