import java.util.*;
import java.math.*;
class Main{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int count = input.nextInt();
        while(count-- > 0){
            BigInteger x = input.nextBigInteger();
            String g = input.next();
            BigInteger y = input.nextBigInteger();
            BigInteger ans = x.gcd(y);
            System.out.println(x.divide(ans) + " / " + y.divide(ans));
        }
    }
}