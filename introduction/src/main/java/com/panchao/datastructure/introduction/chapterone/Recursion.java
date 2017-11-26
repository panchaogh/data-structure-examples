package com.panchao.datastructure.introduction.chapterone;
/**
 * 
 * @ClassName:recursion
 * @Description:TODO(递归思想)
 * @author PANCHAO
 * @date 2017年10月3日 下午3:01:40
 *
 */
public class Recursion {
	
	public static int getImplement(int x){
		if (x == 0) {
			return 0;
		} else {
			return 2*getImplement(x-1)+x*x;
		}
	}
}
