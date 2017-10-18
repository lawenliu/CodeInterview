package OA2secondRound;

import java.util.*;

class Node {
	int val;
	ArrayList<Node> children;
	public Node(int val) {
		this.val = val;
		children = new ArrayList<Node>();
	}
}

class ReturnType {
	int numberOfNodes;
	double sum;
	Node candidate;
	public ReturnType(int numberOfNodes, double sum, Node candidate) {
		this.numberOfNodes = numberOfNodes;
		this.sum = sum;
		this.candidate = candidate;
	}
}

public class CompanyTree {
	public Node getMaxAvgSubTree(Node root) {
		// write your code here

	}
	
	public static void main(String[] argc) {
		CompanyTree mas = new CompanyTree();
		
		/*
		 * case 1:
		 *       5
		 *     /   \
		 *   3       3
 		 *  / \     /  \
		 * 1   1   1    1  
		 * return is 5
		 */
		Node head1 = new Node(5);
		head1.children.add(new Node(3));
		head1.children.add(new Node(3));
		head1.children.get(0).children.add(new Node(1));
		head1.children.get(0).children.add(new Node(1));
		head1.children.get(1).children.add(new Node(1));
		head1.children.get(1).children.add(new Node(1));
		Node check = mas.getMaxAvgSubTree(head1);
		if(check == head1) {
			System.out.println("test case 1 correct!");
		} else {
			System.out.println("test case 1 fail!");
		}
		
		/*
		 * case 2:
		 *       3
		 *     /   \
		 *   17      8  
		 * return is 3
		 */
		Node head2 = new Node(3);
		head2.children.add(new Node(17));
		head2.children.add(new Node(8));
		check = mas.getMaxAvgSubTree(head2);
		if(check == head2) {
			System.out.println("test case 2 correct!");
		} else {
			System.out.println("test case 2 fail!");
		}
		
		/*
		 * case 3:
		 * null
		 * return is null
		 */
		Node head3 = null;
		check = mas.getMaxAvgSubTree(head3);
		if(check == null) {
			System.out.println("test case 3 correct!");
		} else {
			System.out.println("test case 3 fail!");
		}
		
		/*
		 * case 4:
		 * 1
		 * return is null
		 */
		Node head4 = new Node(1);
		check = mas.getMaxAvgSubTree(head4);
		if(check == null) {
			System.out.println("test case 4 correct!");
		} else {
			System.out.println("test case 4 fail!");
		}
		
		/*
		 * case 5:
		 * 1
		 * | \
		 * 0  null
		 * return is node 1
		 */
		Node head5 = new Node(1);
		head5.children.add(new Node(1));
		head5.children.add(null);
		check = mas.getMaxAvgSubTree(head5);
		if(check == head5) {
			System.out.println("test case 5 correct!");
		} else {
			System.out.println("test case 5 fail!");
		}
		
		/*
		 * case 6:
		 *   1
		 *  / \
		 * 0   3
		 * |
		 * 4
		 * return is node 2 in 2nd level, not root
		 */
		Node head6 = new Node(1);
		head6.children.add(new Node(0));
		head6.children.add(new Node(3));
		head6.children.get(0).children.add(new Node(4));
		check = mas.getMaxAvgSubTree(head6);
		if(check == head6.children.get(0)) {
			System.out.println("test case 6 correct!");
		} else {
			System.out.println("test case 6 fail!");
		}
		
		/*
		 * case 7:
		 *   1
		 *  / \
		 * 2   300
		 * |\ 
		 * 1 1
		 * return is node root
		 */
		Node head7 = new Node(1);
		head7.children.add(new Node(2));
		head7.children.add(new Node(300));
		head7.children.get(0).children.add(new Node(1));
		head7.children.get(0).children.add(new Node(1));
		check = mas.getMaxAvgSubTree(head7);
		if(check == head7) {
			System.out.println("test case 7 correct!");
		} else {
			System.out.println("test case 7 fail!");
		}
		
		/*
		 * case 8:
		 *   1
		 *  / \
		 * 200   3
		 * |\ 
		 * 1 1
		 * return is node 200
		 */
		Node head8 = new Node(1);
		head8.children.add(new Node(200));
		head8.children.add(new Node(3));
		head8.children.get(0).children.add(new Node(1));
		head8.children.get(0).children.add(new Node(1));
		check = mas.getMaxAvgSubTree(head8);
		if(check == head8.children.get(0)) {
			System.out.println("test case 8 correct!");
		} else {
			System.out.println("test case 8 fail!");
		}
	}
}
