import java.io.*;

public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, rslt = 0;
		int[] arr = new int[1001];
		arr[0] = arr[1] = -1;

		int end = (int)Math.sqrt(1000);
		for(int i=2;i<=end;i++){
			if(arr[i] == -1) continue;
			arr[i] = 0;
			for(int j=2;i*j<=1000;j++) arr[i*j] = -1;
		}

		N = Integer.parseInt(br.readLine());

		String S = br.readLine();
		String[] input = S.split(" ");

		for(String i : input){
			if(arr[Integer.parseInt(i)] == 0) rslt++;
		}
		System.out.println(rslt);
	}
}