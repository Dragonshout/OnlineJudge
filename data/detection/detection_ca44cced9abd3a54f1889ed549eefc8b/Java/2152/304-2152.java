import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		String aout = "";
		for (int i = 0; i <t; i++) {
			String[] a11 = br.readLine().split(" ");
			
			int a1 = Integer.parseInt(a11[0]);
			int a2 = Integer.parseInt(a11[1]);

			int tt = 0;
			String out ="";
				
			for (int x = a1 ; x < a2 + 1; x ++ ) {
				if (a2 < 10) {
					out = a1 + "";
					break;
				}
				String aString = x + "";
				int max=0;
				int min = 10;

				for(int y = 0 ;y < aString.length(); y ++) {

					int z = Integer.parseInt(aString.charAt(y) + "");
					if(z > max) {
						max = z;

					}
					if(z < min) {
						min = z;

					}
				}
				if((max- min) > tt) {
					tt = (max- min);
					out = aString;
					if((max - min) == 9) {
						break;
					}
				}

			}
			aout = aout +  out + "\n";
		}
		System.out.println(aout);
	}
}