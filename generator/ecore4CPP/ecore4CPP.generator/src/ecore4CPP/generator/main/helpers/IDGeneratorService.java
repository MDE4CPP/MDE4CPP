package ecore4CPP.generator.main.helpers;

public class IDGeneratorService {
	
	public String polynomialRollingHash(String key) 
	{
		//generate a hash value from string using polynomial rolling hash
		int n = key.length();
		int m = 2147483647; // 32 Bit Prime number
		int p = 53;
		long powerOfP = 1;
		long hash = 0;
		
		for(int i = 0; i < n; i++)
		{
			int c = key.charAt(i);
			hash = (hash + c * powerOfP) % m;
			powerOfP = (powerOfP * p) % m;
		}
		
		return Long.toString(hash);
	}

	public String polynomialRollingHashShort(String key) 
	{
		//generate a hash value from string using polynomial rolling hash
		int n = key.length();
		//int m = 65537; // or 32 bit signed 32749 Prime Numbers; 
		int m = (int) (10e9 + 9);
		int p = 53;
		int powerOfP = 1;
		int hash = 0;
		
		for(int i = 0; i < n; i++)
		{
			int c = (short) key.charAt(i);
			hash = (hash + c * powerOfP) % m;
			powerOfP = (powerOfP * p) % m;
		}
		
		return Integer.toUnsignedString((int)hash);
	}

}
