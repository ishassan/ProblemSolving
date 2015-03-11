import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class solution {
	static BigInteger[] memo = new BigInteger[1010];
	static BigInteger fib(int n){
		if(n<2)
			return BigInteger.valueOf(n);
		if(n==2)
			return BigInteger.valueOf(1);
		if(memo[n]!=BigInteger.valueOf(-1))
			return memo[n];

		return memo[n] = fib(n-1).add(fib(n-3));
	}
	public static void main(String[] args) {
		try {
			FileOutputStream fout = new FileOutputStream("fido.out");
			PrintStream cout = new PrintStream(fout);
			FileInputStream fin = new FileInputStream("fido.in");
			Scanner cin = new Scanner(fin);
			
			int n = cin.nextInt();
			
			for(int i=0; i<1010; i++)
				memo[i]= BigInteger.valueOf(-1);
			cout.println(fib(n).toString());
			
		} catch (Exception e) {
			System.out.println("error");
		}

	}
}
