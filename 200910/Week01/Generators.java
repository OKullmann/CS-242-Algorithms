import java.util.Random;

class Array_Generators {

    public static int[] sorted_up(int n) {
        int[] A = new int[n];
        for (int i = 0; i < n; i++)
	    A[i] = i;
        return A;
    }

    public static int[] sorted_down(int n) {
        int[] A = new int[n];
        for (int i = 0; i < n; i++)
	    A[i] = n-i;
        return A;
    }

    public static int[] sorted_rand(int n) {
        int[] A = new int[n];
	Random randomGenerator = new Random();
        for (int i = 0; i < n; i++)
 	    A[i] = randomGenerator.nextInt() % (5 * n);
        return A;
    }

}

