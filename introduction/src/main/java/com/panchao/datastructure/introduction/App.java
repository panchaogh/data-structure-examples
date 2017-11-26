package com.panchao.datastructure.introduction;

/**
 * Hello world!
 *
 */
public class App 
{
	
	public int b(int months){
		if (months==1 || months == 2) {
			return 1;
		}
		return b(months-1)+b(months-2);
	}
    public static void main( String[] args )
    {
    	App a = new App();
        for (int i = 1; i <= 100; i++) {
        	System.out.println("第"+i+"月有兔子对数："+a.b(i));
		}
    }
}
