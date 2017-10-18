package OA2;

public class DayChange {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array={1, 0, 0, 0, 0, 1, 0, 0};
		for(int i:afterChange(array,1)){
			System.out.println(i);
		}
	}
	
	public static int[] afterChange(int[] array, int day){
		if(array==null||array.length==0||day<=0)return array;
		int[] res=new int[array.length];
		for(int i=0;i<day;i++){
			res[0]=res[1];
			res[array.length-1]=res[array.length-2];
			for(int l=1;l<array.length-1;l++){
				if(array[l-1]==array[l+1])res[l]=0;
				else res[l]=1;
			}
		}
		return res;
	}

}
