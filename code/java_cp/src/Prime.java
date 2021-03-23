public class Prime {
    static int N = 100;
    public static void main(String[] args) {

        int p [] = new int[N + 1]; // i will use sieve
        for(int x =0; x<=N; x++){
            p[x] = x;
        }
        N = 10;
        for(int x = 2; x<=N; x++){
            if(p[x] != x)continue;
            for(int y = x + x; y<= N; y+=x){
                p[y] = x;
            }
        }
        System.out.println("these are the prime number from 1 - 100");
        for(int x=2; x<=N; x++){
            if(p[x] != x)continue;
            System.out.print(x + "  " );
        }

    }
}