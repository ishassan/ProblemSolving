import java.awt.List;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.Vector;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader cin = new BufferedReader(
				new InputStreamReader(System.in));

		StringTokenizer tok = new StringTokenizer(cin.readLine());
		int r1 = Integer.parseInt(tok.nextToken());
		int r2 = Integer.parseInt(tok.nextToken());

		tok = new StringTokenizer(cin.readLine());
		int c1 = Integer.parseInt(tok.nextToken());
		int c2 = Integer.parseInt(tok.nextToken());

		tok = new StringTokenizer(cin.readLine());
		int d1 = Integer.parseInt(tok.nextToken());
		int d2 = Integer.parseInt(tok.nextToken());

		 for (int a = 1; a < 10; a++) {
			for (int b = 1; b < 10; b++) {
				if(a == b)continue;
				for (int c = 1; c < 10; c++) {
					if(a == c || c == b) continue;
					for (int d = 1; d < 10; d++) {
						if(d == a || d == c || d == b) continue;
						if (a + b != r2)
							continue;
						if (c + d != r1)
							continue;
						if (a + c != c1)
							continue;
						if (b + d != c2)
							continue;
						if (a + d != d2)
							continue;
						if (c + b != d1)
							continue;
						System.out.println(c + " " + d);
						System.out.println(a + " " + b);
						System.exit(0);
					}
				}
			}

		}
		 System.out.println(-1);

	}
}
