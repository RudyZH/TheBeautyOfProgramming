package beauty;

class TreeNode {
	
	public int val;
	public TreeNode left;
	public TreeNode right;
	
	public TreeNode(int val) {
		this.val = val;
		this.left = null;
		this.right = null;
	}
	
	public TreeNode() {
		this.val = 0;
		this.left = null;
		this.right = null;
	}
}

public class PrintNodeInLevel {

	public void printNodeAtLevel(TreeNode root, int k) {
		if (root == null || k < 0)
			return;
		if (k == 0) {
			System.out.print(root.val + " ");
			return;
		} else {
			printNodeAtLevel(root.left, k - 1);
			printNodeAtLevel(root.right, k - 1);
		}
	}
	
	public static void main(String[] args) {
		
		TreeNode t1 = new TreeNode(1);
		TreeNode t2 = new TreeNode(2);
		TreeNode t3 = new TreeNode(3);
		TreeNode t4 = new TreeNode(4);
		TreeNode t5 = new TreeNode(5);
		TreeNode t6 = new TreeNode(6);
		TreeNode t7 = new TreeNode(7);
		TreeNode t8 = new TreeNode(8);
		
		t1.left = t2;
		t1.right = t3;
		t2.left = t4;
		t2.right = t5;
		t3.right = t6;
		t5.left = t7;
		t5.right = t8;
		
		PrintNodeInLevel p = new PrintNodeInLevel();
		p.printNodeAtLevel(t1, 3);
		
	}

}
