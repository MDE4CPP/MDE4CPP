/*
 * WStr.cpp
 *
 *  Created on: 11.08.2017
 *      Author: Alexander
 */

#include "WStr.hpp"


WStr::WStr ( const XMLCh* const toTranscode )
{
    // Call the private transcoding method
	m_local = xercesc::XMLString::transcode( toTranscode );
}

WStr::WStr ( const WStr& other ) :
				m_local( other.m_local )
{
	const_cast<WStr&>( other ).m_local = 0;
}

WStr::~WStr ()
{
	if ( m_local )
	{
		xercesc::XMLString::release( &m_local );
	}
}

const std::string WStr::unicodeForm () const
{
	std::string str(m_local);
	return str;
}

