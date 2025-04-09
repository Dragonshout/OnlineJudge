import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		String aout = "";
		for (int i = 0; i <t; i++) {
			int a1 =  scanner.nextInt();
			int a2 =  scanner.nextInt();
			int tt = 0;
			String out ="";
				
			for (int x = a1 ; x < a2 + 1; x ++ ) {
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
					tt = (max- min);;
					out = aString;
				}
				if (a2 < 10) {
					out = a1 + "";
					
				}
			}
			aout = aout +  out + "\n";
		}
		System.out.println(aout);
	}
}