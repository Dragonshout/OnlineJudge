import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		for (int i = 0; i < (13*a) +19 ; i++) {
			System.out.print("*");
		}
		System.out.println();
		for ( int x = 0; x < a;x ++) {
			System.out.print("*");
			for (int i = 0; i < (13*a) +17 ; i++) {
				System.out.print(".");

			}
			System.out.print("*");

			System.out.println();
		}
		System.out.print("*");
		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
			
		}
		for (int x = 0;x < (a*2) +3; x ++) {
			System.out.print("@");
			
		}
		for (int x = 0;x < (a*2) +2; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");
		for (int x = 0;x < (a*2) +2; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");
		for (int x = 0;x < (a*2) +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");
		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
			
		}
		for (int x = 0;x < (a*2) +3; x ++) {
			System.out.print("@");
			
		}
		for (int x = 0;x < a +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("*");
		System.out.println();
		//
		int hang =5;
		int xy = 1;
		for (int i = 0; i < (a*2) +1; i++) {
			System.out.print("*");
			for (int x = 0;x < a +1; x ++) {
				System.out.print(".");
				
			}
			System.out.print("@");

			for (int x = 0;x < (a*2) +2; x ++) {
				System.out.print(".");
				
			}
			for (int x = 0;x < (a) +1; x ++) {
				System.out.print(".");
			}
			
			if(hang <(( a *2) +3) - (a -3)) {
				if (hang == ((( a *2) +3) - (a -3)) -1 )  {
					for (int x =0;x < (a + 5) - hang;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (xy) ;x ++) {
						System.out.print("@");
					}
					System.out.print("@");
					xy++;
					xy++;
					for (int x =0;x < (a + 5) - hang;x ++) {
						System.out.print(".");
					}
					for (int x =0;x < (a) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a*2) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a*3) + 3;x ++) {
						System.out.print(".");
					}
					System.out.print("*");
				}else {
					for (int x =0;x < (a + 5) - hang;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (xy) ;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					xy++;
					xy++;
					for (int x =0;x < (a + 5) - hang;x ++) {
						System.out.print(".");
					}
					for (int x =0;x < (a) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a*2) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a) + 1;x ++) {
						System.out.print(".");
					}
					System.out.print("@");
					for (int x =0;x < (a*3) + 3;x ++) {
						System.out.print(".");
					}
					System.out.print("*");
				}
				
			}else {
				System.out.print("@");
				for (int x =0;x < (a*2) + 1;x ++) {
					System.out.print(".");
				}
				System.out.print("@");

				for (int x =0;x < (a) + 1;x ++) {
					System.out.print(".");
				}
				System.out.print("@");
				for (int x =0;x < (a*2) + 1;x ++) {
					System.out.print(".");
				}
				System.out.print("@");
				for (int x =0;x < (a) + 1;x ++) {
					System.out.print(".");
				}
				System.out.print("@");
				for (int x =0;x < (a*3) + 3;x ++) {
					System.out.print(".");
				}
				System.out.print("*");
			}
			hang ++;
			System.out.println();
		}
		System.out.print("*");
		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
			
		}
		for (int x = 0;x < (a*2) +3; x ++) {
			System.out.print("@");
			
		}
		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");

		for (int x = 0;x < (a*2) +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");

		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("@");
		for (int x = 0;x < (a*2) +1; x ++) {
			System.out.print("@");
		
		}
		System.out.print("@");
		for (int x = 0;x < (a) +1; x ++) {
			System.out.print(".");
			
		}
		for (int x = 0;x < (a*2) +3; x ++) {
			System.out.print("@");
			
		}
		for (int x = 0;x < a +1; x ++) {
			System.out.print(".");
		
		}
		System.out.print("*");
		System.out.println();
		for ( int x = 0; x < a;x ++) {
			System.out.print("*");
			for (int i = 0; i < (13*a) +17 ; i++) {
				System.out.print(".");

			}
			System.out.print("*");

			System.out.println();
		}
		for (int i = 0; i < (13*a) +19 ; i++) {
			System.out.print("*");
		}
	}
	
}