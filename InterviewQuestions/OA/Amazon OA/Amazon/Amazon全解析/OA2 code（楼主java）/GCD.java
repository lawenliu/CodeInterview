package OA2;

public class GCD {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array={72,56,14};
		System.out.println(getGCD(array));
	}
	
	public static int getGCD(int[] array){
		if(array==null||array.length==0||array[0]==1){
			return 0;
		}
		int res=array[0];
		for(int i=1;i<array.length;i++){
			int temp=array[i];
			if(temp==0)return 0;
			while(temp%res!=0){
				int tem=temp;
				temp=res;
				res=tem%res;
			}
		}
		
		return res;
	}

}
