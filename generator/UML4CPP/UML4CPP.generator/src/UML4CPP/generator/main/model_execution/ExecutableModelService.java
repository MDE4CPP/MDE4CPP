package UML4CPP.generator.main.model_execution;

/**
 * Service class to determine the kind of executable UML specification that the generated model should conform to.<br>
 * <br><br>
 * 
 * @author Maximilian Hammer
 *
 */

public class ExecutableModelService {

	private enum ExecutableModelKind
	{
		NONE,
		FUML,
		PSCS,
		PSSM
	}
	
	private ExecutableModelKind m_executableModelKind = ExecutableModelKind.NONE;
	
	public boolean isExecutableModel()
	{
		return (m_executableModelKind != ExecutableModelKind.NONE);
	}
	
	public boolean isFUMLExecutable()
	{
		return isExecutableModel();
	}
	
	public boolean isPSCSExecutable()
	{
		return	(
					(m_executableModelKind == ExecutableModelKind.PSCS) ||
					(m_executableModelKind == ExecutableModelKind.PSSM)
				);
	}
	
	public boolean isPSSMExecutable()
	{
		return (m_executableModelKind == ExecutableModelKind.PSSM);
	}
	
	public void setIsNoneExecutable()
	{
		m_executableModelKind = ExecutableModelKind.NONE;
	}
	
	public void setIsFUMLExecutable()
	{
		m_executableModelKind = ExecutableModelKind.FUML;
	}
	
	public void setIsPSCSExecutable()
	{
		m_executableModelKind = ExecutableModelKind.PSCS;
	}
	
	public void setIsPSSMExecutable()
	{
		m_executableModelKind = ExecutableModelKind.PSSM;
	}
}
