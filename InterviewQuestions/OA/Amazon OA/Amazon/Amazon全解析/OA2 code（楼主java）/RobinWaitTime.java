package OA2;

import java.util.LinkedList;

public class RobinWaitTime {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arrival={0,1,3,9};
		int[] execution={2,1,7,5};
		int q=2;
		System.out.println(getWait(arrival,execution,q));
	}
	
	public static double getWait(int[] arrival, int[] execution, int q){
		LinkedList<Integer> queue=new LinkedList<Integer>();
		queue.add(0);
		int cur=arrival[0];
		int nextid=0;
		double wait=0;
		while(!queue.isEmpty()){
			int current=queue.poll();
			if(cur>=arrival[current])wait+=cur-arrival[current];
			else cur=arrival[current];
			System.out.println(current+"-->"+wait);
			if(execution[current]>q){
				cur+=q;
				arrival[current]=cur;
				execution[current]-=q;
				for(int i=nextid+1;i<arrival.length;i++){
					if(arrival[i]<=cur){
						queue.add(i);
						nextid=i;
					} else{
						break;
					}
					
				}
				queue.add(current);
				
			} else{
				cur+=execution[current];
				for(int i=nextid+1;i<arrival.length;i++){
					if(arrival[i]<=cur){
						queue.add(i);
						nextid=i;
					} else{
						break;
					}
					
				}
			}
		
		}
		return wait/arrival.length;
	}

}
