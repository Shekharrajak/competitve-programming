


	/* IMPORTANT: class must not be public. */

	/*
	 * uncomment this if you want to read input.
	import java.io.BufferedReader;
	import java.io.InputStreamReader;
	*/
	import java.util.*;
	//import java.io.*;
	class vowel {
	    public static void main(String args[] ) throws Exception {
	        /*
	         * Read input from stdin and provide input before running

	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        String line = br.readLine();
	        int N = Integer.parseInt(line);
	        for (int i = 0; i < N; i++) {
	            System.out.println("hello world");
	        }
	        */
			Scanner sc = new Scanner(System.in);
			String s =sc.next();
			CharSequence cs1 = "a";
			CharSequence cs2 = "e";
			CharSequence cs3 = "o";
			CharSequence cs4 = "i";
			CharSequence cs5 = "u";
	        if(s.contains(cs1) && s.contains(cs2) && s.contains(cs3) && s.contains(cs4) && s.contains(cs5) ){
	        	
	        	System.out.println("yes");
	        }
	        else{
	        	System.out.println("no");
	        }
	        sc.close();
	    }
	}




