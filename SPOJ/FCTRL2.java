import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static BigInteger fact(int num){
		BigInteger res = new BigInteger("1");
		while(num>0){
			res = res.multiply(BigInteger.valueOf(num));
			num--;
		}
		return res;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n,num;
		n = in.nextInt();
		for (int i = 0; i < n; i++) {
			num = in.nextInt();
			System.out.println(fact(num));
		}
	}
}
