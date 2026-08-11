package org.eclipse.core.runtime.preferences;

/**
 * This stub class and the corresponding org.eclipse.equinox dependencies
 * (preferences, common, registry) are required to fix a NullPointerException
 * during the standalone execution of Acceleo generators (e.g., UML4CPP, ecore4CPP).
 * 
 * When Acceleo runs outside of an Eclipse RCP environment, it still tries to
 * initialize AcceleoPreferences which internally accesses PreferencesService.
 * The default ConfigurationScope in org.eclipse.equinox.preferences tries to get 
 * the OSGi configuration location, but because OSGi is not running, the Location 
 * is null, resulting in an NPE when isReadOnly() is called. 
 * 
 * By including the equinox dependencies we satisfy the classloader, and by 
 * providing this stub in the source tree, it takes precedence over the jar 
 * implementation and safely prevents the NPE.
 */
public final class ConfigurationScope implements IScopeContext {
    public static final String SCOPE = "configuration";
    public static final IScopeContext INSTANCE = new ConfigurationScope();
    
    public ConfigurationScope() {}
    public String getName() { return SCOPE; }
    public org.eclipse.core.runtime.preferences.IEclipsePreferences getNode(String qualifier) { return null; }
    public org.eclipse.core.runtime.IPath getLocation() { 
        return null;
    }
}
