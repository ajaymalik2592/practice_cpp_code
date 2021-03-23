import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int arr[] = new int[N];
        for(int i=0; i<N; i++)
            arr[i] = sc.nextInt();
        long out = solve(arr, N);
        System.out.println(out);
    }
    public static long solve(int [] arr1, int n){
       long[] arr = new long[100001];
       for(int x =0; x<100001; x++)arr[x] = 0;
       for(int x  =0; x<n; x++)arr[arr1[x]] += 1;
       long a = 0;
       for(int x =1; x<= 400; x++)
       {
           if(x*x >= 100001)
           break;
           a += arr[x] * arr[x*x];
           
       }
       return a;
       
     }
}