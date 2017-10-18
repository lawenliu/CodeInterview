package OA2;

public class CircleLinkedlist {
	
	public static class CNode {
		int val;
		CNode next;
		CNode(int x) {
		val = x;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CNode a=new CNode(3);
		CNode b=new CNode(4);
		CNode c=new CNode(12);
		CNode d=new CNode(14);
		CNode e=new CNode(17);
		CNode f=new CNode(28);
		CNode g=new CNode(39);
		CNode h=new CNode(44);
		a.next=b;
		b.next=c;
		c.next=d;
		d.next=e;
		e.next=f;
		f.next=g;
		g.next=h;
		h.next=a;
		CNode tem=insert(d,12);
		CNode t=tem.next;
		while(t!=tem){
			System.out.println(t.val);
			t=t.next;
		}
		System.out.println(t.val);
	}
	
	public static CNode insert(CNode head,int n){
		CNode c=new CNode(n);
		if(head==null) {
			c.next=c;
			return c;
		}
		
		if(head.next==head){
			head.next=c;
			c.next=head;
			if(n>head.val)return head;
			else return c;
		}
		
		CNode pre=head;
		CNode cur=head.next;
		while(cur!=head){
			if(n>=pre.val&&n<=cur.val)break;
			if(pre.val>cur.val&&(n>pre.val||n<cur.val)){
				break;
			}
			pre=cur;
			cur=cur.next;
		}
		c.next=cur;
		pre.next=c;
		return c;
		
	}

}
