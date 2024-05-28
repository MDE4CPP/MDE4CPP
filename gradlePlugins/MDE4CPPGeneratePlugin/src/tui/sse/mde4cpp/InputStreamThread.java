package tui.sse.mde4cpp;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Thread for forwarding input and error streams of MDE4CPP compiling processes
 * to command line.<br>
 *
 * Input stream data is send to {@code System.out.println()}<br>
 * Error stream data is send to {@code System.err.println()}<br>
 * <br>
 * Additionally, warning message and starting message can be configured.<br>
 * If a warning message is defined, this message is printed first.<br>
 * Configured starting message will be highlighted by '#' framing
 * afterwards.<br>
 * Stream data follow.
 *
 */
class InputStreamThread extends Thread
{
	private boolean m_isErrorSteam = false;
	private String m_startingMessage = null;
	private String m_warningMessage = null;

	private InputStream m_stream;

	/**
	 * Constructor
	 *
	 * @param steam
	 *            the input steam, which should be forwarded
	 * @param isErrorStream
	 *            if {@code true} then {@code Systen.err.println()} is used.
	 *            Otherwise, {@code Systen.out.println()} is used.
	 */
	public InputStreamThread(InputStream steam, boolean isErrorStream)
	{
		m_stream = steam;
		m_isErrorSteam = isErrorStream;
	}

	/**
	 * set starting message
	 *
	 * @param startingMessage
	 *            message, which should be highlighted
	 */
	void setStartingMessage(String startingMessage)
	{
		m_startingMessage = startingMessage;
	}

	/**
	 * set warning message
	 *
	 * @param warningMessage
	 *            message, which should be places in front of starting message with
	 *            'WARNING' tag
	 */
	public void setWarningExecPluginExisting(String warningMessage)
	{
		m_warningMessage = warningMessage;
	}

	@Override
	public void run()
	{
		try
		{
			BufferedReader reader = new BufferedReader(new InputStreamReader(m_stream));
			String line;
			if (m_warningMessage != null)
			{
				System.out.println("WARNING: " + m_warningMessage);
			}
			if (m_startingMessage != null)
			{
				String highlighting = new String(new char[m_startingMessage.length() + 4]).replace('\0', '#');
				System.out.println(highlighting);
				System.out.println("# " + m_startingMessage + " #");
				System.out.println(highlighting);
			}
			while ((line = reader.readLine()) != null)
			{
				if (m_isErrorSteam)
				{
					System.err.println(line);
				}
				else
				{
					System.out.println(line);
				}
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
