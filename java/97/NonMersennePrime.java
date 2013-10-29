import java.math.BigInteger;

public class NonMersennePrime {

	public static void main(String[] args) {
		BigInteger modulo = BigInteger.valueOf(10000000000l);
		BigInteger result = BigInteger.valueOf(2);
		result = result.modPow(BigInteger.valueOf(7830457), modulo);
		result = result.multiply(BigInteger.valueOf(28433));
		result = result.add(BigInteger.ONE).mod(modulo);
		System.out.println(result);
	}

}
