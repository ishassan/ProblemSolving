import java.math.BigInteger;
import java.util.Scanner;



public class Main {

	public static void main(String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		BigInteger zero = new BigInteger("0");
		BigInteger fibs[] = new BigInteger[512];
		fibs[0] = new BigInteger("1");
		fibs[1] = new BigInteger("2");
		for (int i = 2; i < fibs.length; i++) {
			fibs[i] = fibs[i-1].add(fibs[i-2]);
		}
		
		while(true){
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			if(a.compareTo(zero)==0 && b.compareTo(zero)==0)
				break;
			
			int lower=0,upper=0;
			while(fibs[lower].compareTo(a) < 0)
				lower++;
			
			upper = lower;
			while(fibs[upper].compareTo(b)<=0)
				upper++;
			System.out.println(upper-lower);
			
		}
		
	
	}
}