import java.util.*;

public class Maximum_Gcd_and_Sum {
    
    // Function to get all factors of a number
    private static List<Integer> getFactors(int num) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                factors.add(i);
                if (i != num / i) factors.add(num / i);
            }
        }
        return factors;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] A = new int[n];
        int[] B = new int[n];

        for (int i = 0; i < n; i++) A[i] = sc.nextInt();
        for (int i = 0; i < n; i++) B[i] = sc.nextInt();

        // Step 1: Build factor map for A
        Map<Integer, Integer> factorMap = new HashMap<>(); 
        // (factor -> max number in A having this factor)
        
        for (int x : A) {
            for (int f : getFactors(x)) {
                factorMap.put(f, Math.max(factorMap.getOrDefault(f, 0), x));
            }
        }

        int maxGcd = 0;
        int maxSum = 0;

        // Step 2: For each element in B, check its factors
        for (int y : B) {
            for (int f : getFactors(y)) {
                if (factorMap.containsKey(f)) {
                    int x = factorMap.get(f);
                    int sum = x + y;
                    if (f > maxGcd || (f == maxGcd && sum > maxSum)) {
                        maxGcd = f;
                        maxSum = sum;
                    }
                }
            }
        }

        System.out.println(maxSum);
        sc.close();
    }
}
