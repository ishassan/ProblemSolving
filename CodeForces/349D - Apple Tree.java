import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	static int arr[],cntChilds[];
	static long decrease[];
	static ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
	static long gcd(long a, long b){
		if(b == 0) return a;
		return gcd(b, a%b);
	}
	static long lcm(long a, long b){
		return a/gcd(a, b)*b;
	}
	static long DFS(int idx, int prev){
		if(idx > 0 && adj.get(idx).size()==1){
			decrease[idx]=1;
			return arr[idx];
		}
		
		long mn = Long.MAX_VALUE;
		long l = 1;
		for (int i = 0; i < adj.get(idx).size(); i++) {
			int nxt = adj.get(idx).get(i);
			if(nxt == prev) continue;
			mn = Math.min(mn, DFS(nxt, idx));
			l = lcm(l, decrease[nxt]);
		}
		decrease[idx] = Math.max(1, l*cntChilds[idx]);
		mn -= mn%l;
		
		return mn*cntChilds[idx];
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int n = sc.nextInt(),a,b;
		arr = new int[n];
		cntChilds = new int[n];
		decrease = new long[n];
		adj = new ArrayList<ArrayList<Integer>>();
		long sum = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
			adj.add(new ArrayList<Integer>());
			sum += arr[i];
		}
		for (int i = 0; i < n-1; i++) {
			a = sc.nextInt();
			b = sc.nextInt();
			--a;--b;
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		cntChilds[0] = adj.get(0).size();
		for (int i = 1; i < n; i++) cntChilds[i] = adj.get(i).size()-1;
		
		System.out.println(sum - DFS(0,-1));
	}
}
