package OA2secondRound;

import java.util.*;

class Result {
	int id;
	int value;
	public Result(int id, int value) {
		this.id = id;
		this.value = value;
	}
}

public class HighFive {
	public Map<Integer, Double> getHighFive(Result[] resultArray) {
		// write your code here
		
	}
	
	public static void main(String[] argc) {
		HighFive test = new HighFive();
		
		// test case 1
		int index = 0;
		Result[] results1 = new Result[31];
		for(int i = 0; i < 5; i++) {
			results1[index++] = new Result(3, 100);
			results1[index++] = new Result(4, 0);
		}
		results1[index++] = new Result(4, 0);
		results1[index++] = new Result(4, 10);
		results1[index++] = new Result(1, 56);
		results1[index++] = new Result(5, 11);
		results1[index++] = new Result(1, 86);
		results1[index++] = new Result(1, 37);
		results1[index++] = new Result(5, 10);
		results1[index++] = new Result(2, 37);
		results1[index++] = new Result(2, 98);
		results1[index++] = new Result(5, 100);
		results1[index++] = new Result(2, 78);
		results1[index++] = new Result(1, 45);
		results1[index++] = new Result(5, 6);
		results1[index++] = new Result(1, 72);
		results1[index++] = new Result(2, 65);
		results1[index++] = new Result(2, 54);
		results1[index++] = new Result(5, 4);
		results1[index++] = new Result(2, 38);
		results1[index++] = new Result(1, 92);
		results1[index++] = new Result(1, 100);
		results1[index++] = new Result(5, 10);
		Map<Integer, Double> map1 = test.getHighFive(results1);
		if(map1.get(1) == 81.2 && map1.get(2) == 66.6 && map1.get(3) == 100 && map1.get(4) == 2.0 && map1.get(5) == 27.4) {
			System.out.println("test case 1 correct!");
		} else {
			System.out.println("test case 1 fail!");
		}
		
		// test case 2
		int index2 = 0;
		Result[] results2 = new Result[10];
		for(int i = 0; i < 4; i++) {
			results2[index2++] = new Result(2, Integer.MAX_VALUE);
		}
		results2[index2++] = new Result(1, 36);
		results2[index2++] = new Result(1, 36);
		results2[index2++] = new Result(1, 100);
		results2[index2++] = new Result(2, Integer.MAX_VALUE);
		results2[index2++] = new Result(1, 72);
		results2[index2++] = new Result(1, 72);
		Map<Integer, Double> map2 = test.getHighFive(results2);
		if(map2.get(1) == 63.2 && map2.get(2) == Integer.MAX_VALUE) {
			System.out.println("test case 2 correct!");
		} else {
			System.out.println("test case 2 fail!");
		}
		
		// test case 3
		int score = 30;
		int index3 = 0;
		Result[] results3 = new Result[70];
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 7; j++) {
				Result temp = new Result(i, score++);
				results3[index3++] = temp;
			}
		}
		Map<Integer, Double> map3 = test.getHighFive(results3);
		if(map3.get(0) == 34.0 && map3.get(1) == 41 && map3.get(2) == 48 && map3.get(3) == 55 && map3.get(4) == 62 && map3.get(5) == 69 && map3.get(6) == 76) {
			System.out.println("test case 3 correct!");
		} else {
			System.out.println("test case 3 fail!");
		}
	}
}
