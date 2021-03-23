import java.io.*;
import java.util.*;


public class Aaa
 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
         long X = Long.parseLong(br.readLine().trim());
         long T = Long.parseLong(br.readLine().trim());
         int N = Integer.parseInt(br.readLine().trim());

         long[] arr = new long[N];
         for(int i_arr=0; i_arr <N ; i_arr++)
         {
            String arr_arr = br.readLine().trim()
         ;
         	arr[i_arr] = Long.parseLong(arr_arr);
         }

         long out_ = solve(X, arr, T, N);
         System.out.println( out_);

         wr.close();
         br.close();
    }
    static long solve(long X, long[] arr, long T1, int N){
        int T2 = (int)(T1);
        long[] ti = new long[T2];
        for(int i_arr=0; i_arr<ti.length; i_arr++)
         {
         	ti[i_arr] = 0;
         }
        ti[0] = arr[0];
        int i = 1;
        long total = arr[0], ans = 0;int y = 1;
        while(true)
        {
            if(total < X  && y < N && X - total >= arr[y])
            {
                ti[i] = arr[y];
                total += arr[y];
                y++;
               
                
            }
            else ans++;
            int g = (i+1)%T2;
            total -= ti[g];
            ti[g] = 0;
            i++;
            i %= T2;
             if(y == N)break;
        }
        return ans;
    
    }
}