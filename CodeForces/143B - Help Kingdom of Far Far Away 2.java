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

	static String integral(StringBuilder str){
		int idx = str.length()-3;
		while(idx > 0){
			str.insert(idx, ",");
			idx -= 3;
		}
		return str.toString();
	}
	static String fractional(StringBuilder str){
		while(str.length() < 2)
			str.append("0");
		return str.substring(0, 2);
	}
	public static void main(String[] args) throws IOException {

		BufferedReader cin = new BufferedReader(
				new InputStreamReader(System.in));
		
		StringBuilder str = new StringBuilder(cin.readLine());
		boolean min = false;
		if(str.charAt(0)=='-'){
			str.deleteCharAt(0);
			min = true;
		}
		
		String res = null;
		int idx = str.indexOf(".");
		if(idx == -1)
			res = (min?"(":"")+"$"+integral(str)+".00"+(min?")":"");
		else
			res = (min?"(":"")+"$"+integral(new StringBuilder(str.substring(0,idx)))+"."+fractional(new StringBuilder(str.substring(idx+1)))+(min?")":"");
		
		
		System.out.println(res);
		

	}
}
