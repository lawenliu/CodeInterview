package OA2;

import java.util.Comparator;
import java.util.PriorityQueue;

public class ShortestJob {
	
	public static class Process{
		int arrive;
		int duration;
		public Process(int arrive1,int duration1){
			duration=duration1;
			arrive=arrive1;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arrive={0,1,3,9};
		int[] duration={2,1,7,5};
		System.out.println(getWait(arrive,duration));
	}
	
	public static double getWait(int[] arrive,int[] duration){
		if(arrive==null||duration==null||arrive.length==0||duration.length==0)return 0;
		PriorityQueue<Process> heap=new PriorityQueue<Process>(arrive.length,new Comparator<Process>(){
			@Override
			public int compare(Process arg0, Process arg1) {
				// TODO Auto-generated method stub
				if(arg0.duration==arg1.duration){
					return arg0.arrive-arg1.arrive;
				}
				return arg0.duration-arg1.duration;
			}
			
		});
		double wait=0;
		double cur=0;
		int curid=0;
		Process f=new Process(arrive[0],duration[0]);
		heap.add(f);
		while(!heap.isEmpty()){
			Process tem=heap.poll();
			if(cur>=tem.arrive){
				wait+=cur-tem.arrive;
			} else{
				cur=tem.arrive;
			}
			cur+=tem.duration;
			for(int i=curid+1;i<arrive.length;i++){
				if(cur>=arrive[i]){
					Process temp=new Process(arrive[i],duration[i]);
					heap.add(temp);
					curid++;
				} else{
					break;
				}
			}
		}
		
		return wait/arrive.length;
	}

}
