import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

public class Main {

	static List<ArrayList<Long>> perm = new ArrayList<ArrayList<Long>>();
	static boolean vis[] = new boolean[3];
	static void gen(List<Long> seq, List<Long> res){
		if(res.size() == seq.size()){
			perm.add(new ArrayList<Long>(res));
			return;
		}
		for (int i = 0; i < seq.size(); i++) {
			if(vis[i])continue;
			vis[i] = true;
			long num = seq.get(i);
			res.add(num);
			gen(seq,res);
			res.remove(res.size()-1);
			vis[i] = false;
		}
	}
	public static void main(String[] args) throws IOException {
		//*
		
		BufferedReader cin = new BufferedReader(
				new InputStreamReader(System.in));
		
		int n = Integer.parseInt(cin.readLine());
		vis[0] = vis[1] = vis[2] = false;
		long mn = Long.MAX_VALUE;
		long mx = Long.MIN_VALUE;
		for (long a = 1; a*a*a <= n; a++) {
			if(n % a > 0) continue;
			long lim = (long) Math.sqrt(n/a)+1;
			for (long b = a; b <= lim; b++) {
				if(n % (a*b) > 0) continue;
				long c = n / (a*b);
				
				perm.clear();
				Long arr[]={a,b,c};
				List<Long> seq =  Arrays.asList(arr);	
				List<Long> res = new ArrayList<Long>();
				gen(seq,res);
				
				for(ArrayList<Long> ar : perm){
					long org = (ar.get(0)+2)*(ar.get(1)+2)*(ar.get(2)+1);
					mn = Math.min(mn, org-n);
					mx = Math.max(mx, org-n);
				}
			}
		}
		System.out.println(mn + " " + mx);
	}
}
