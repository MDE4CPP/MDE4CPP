package UML4CPP.generator.main.helpers;

public class IDGeneratorService {
	
	public String generateID(String classQualifiedName) 
	{
		//generate a hash value from string using polynomial rolling hash
		int n = classQualifiedName.length();
		int m = (int) (10e9 + 9);
		int p = 53;
		long powerOfP = 1;
		long hash = 0;
		
		for(int i = 0; i < n; i++)
		{
			int c = classQualifiedName.charAt(i);
			hash = (hash + c * powerOfP) % m;
			powerOfP = (powerOfP * p) % m;
		}
		
		return Long.toString(hash);
	}
	
}
