package tui.sse.mde4cpp;

/**
 * This enumeration represents build modes provided by the MDE4CPP framework for
 * the compilation of C++ projects.<br>
 * Two build modes are existing:
 * <ul>
 * <li>DEBUG - compile project with debug options</li>
 * <li>RELEASE - compile project with release options</li>
 * </ul>
 * Each literal includes the conform string representation, which should be used
 * for configuring MDE4CPP compilations.<br>
 */
enum BUILD_MODE
{
	/**
	 * This literal represents the 'Debug' build mode of the MDE4CPP framework
	 * framework.<br>
	 * It provides the compilation of C++ project with debug options.
	 */
	DEBUG("Debug"),
	/**
	 * This literal represents the 'Release' build mode of the MDE4CPP framework
	 * framework.<br>
	 * It provides the compilation of C++ project with release options.
	 */
	RELEASE("Release");

	/**
	 * MDE4CPP conform string representation of a literal
	 */
	private final String name;

	/**
	 * Constructor for BUILD_MODE literals configuring {@code name}
	 *
	 * @param name
	 *            conform string representation
	 */
	private BUILD_MODE(String name)
	{
		this.name = name;
	}

	/**
	 * Returns string representation of a build mode, which can be directly used
	 * inside the MDE4CPP framework
	 *
	 * @return MDE4CPP conform string representation
	 */
	String getName()
	{
		return name;
	}
}