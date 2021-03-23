import java.util.Scanner;

public class AddTwoNumbers {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++){
                String s1=sc.next();
                int x=sc.nextInt();
                int n = s1.length();
                System.out.print(s1);
                while(n < 15){
                	  System.out.print(" ");

                }
                int j = 3;
                if(x < 10)j =1 ;
                else if(x < 100)j=2;

                for(int d = j ; d<3; j++) System.out.print(s1);
               	System.out.print(x);


            }
            System.out.println("================================");

    }

}



