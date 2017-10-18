package OA2;

public class maze {
	static boolean res=false;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] grid = {
				{1, 0, 1, 1, 1},
				{1, 1, 0, 0, 1},
				{0, 1, 0, 9, 0},
				{0, 1, 1, 0, 1}};
		System.out.print(maze3(grid));
	}

	public static boolean maze3(int[][] grid) {
		boolean[][] status=new boolean[grid.length][grid[0].length];
		for(int i=0;i<status.length;i++){
			for(int l=0;l<status[0].length;l++){
				status[i][l]=true;
			}
		}
		canPass(grid,status,0,0);
		return res;
	}
	
	public static void canPass(int[][] array,boolean[][] status,int row,int column){
		if(!isValid(array,row,column))return;
		if(array[row][column]==9){
			res=true;
			return;
		}
		System.out.println(row+"--"+column);
		if(status[row][column]){
			status[row][column]=false;
			canPass(array,status,row,column+1);
			canPass(array,status,row+1,column);
			canPass(array,status,row,column-1);
			canPass(array,status,row-1,column);
			status[row][column]=true;
		}
		
	}
	public static boolean isValid(int[][] array, int row,int column){
		if(row>=0&&row<array.length&&column>=0&&column<array[0].length&&array[row][column]!=0){
			return true;
		}
		return false;
	}
	
	

}
