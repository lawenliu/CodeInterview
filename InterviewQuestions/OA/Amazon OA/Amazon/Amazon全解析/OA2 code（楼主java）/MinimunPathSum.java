package OA2;

public class MinimunPathSum {
	private class TreeNode{
		TreeNode left;
		TreeNode right;
		int val;
		public TreeNode(){
		}
	}
	static int res=Integer.MAX_VALUE;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}
	
	public static void mini(TreeNode root,int sum){
		if(root.left==null&&root.right==null){
			res=Math.min(sum+root.val,res);
			return;
		}
		if(root.left!=null)mini(root.left,sum+root.val);
		if(root.right!=null)mini(root.right,sum+root.val);
	}

}
