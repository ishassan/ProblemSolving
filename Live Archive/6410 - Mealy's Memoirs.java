import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
		int tst = Integer.valueOf(cin.readLine());
		while(tst-- > 0){
			
			String str = cin.readLine();
			String word = "([a-z]{3,16}?)";
			Matcher mat = Pattern.compile(word + "at" + word + "dot" + word + "((dot)(([a-z]{3,16}?)|([a-z]{2}?)|([a-z]{2}dot[a-z]?)))?").matcher(str);
			int c =0;
	
			if(mat.find()){
				do{
					++c;	
				}while(mat.find(mat.end()));
			}
			System.out.printf("$%.2f\n",c*1.28);
		}
	}
}
