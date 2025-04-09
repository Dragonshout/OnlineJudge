import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		long a = scanner.nextInt();
		long total = 0;
		for(int x = 1 ;x < a + 1;x ++) {
			total += x;
		}
		System.out.println(total - a);
	}
}