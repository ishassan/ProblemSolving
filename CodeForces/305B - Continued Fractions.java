import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Java {
	static BigInteger arr[];


	public static void main(String[] args) {
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		BigInteger a = scanner.nextBigInteger();
		BigInteger b = scanner.nextBigInteger();
		BigInteger gcd = a.gcd(b);
		a = a.divide(gcd);
		b = b.divide(gcd);
		
		int n = scanner.nextInt();
		arr = new BigInteger[n + 1];
		for (int i = 0; i < n; i++) {
			arr[i] = scanner.nextBigInteger();
		}
		BigInteger x = arr[n - 1], y = BigInteger.ONE;
		for (int i = n-2; i >= 0; i--) {
			BigInteger tmp = x.add(BigInteger.ZERO);
			x = y.add(BigInteger.ZERO);
			y = tmp.add(BigInteger.ZERO);
			
			BigInteger yy = y.add(BigInteger.valueOf(0));
			BigInteger xx = x.add(y.multiply(arr[i]));
			gcd = yy.gcd(xx);
			xx = xx.divide(gcd);
			yy = yy.divide(gcd);
			x = xx.add(BigInteger.ZERO);
			y = yy.add(BigInteger.ZERO);
		}
		if(a.compareTo(x) == 0 && b.compareTo(y)==0)
			System.out.println("YES");
		else
			System.out.println("NO");
		scanner.close();
	}
}
